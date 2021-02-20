#include <memory>
#include <mutex>

using namespace std;

template<typename T>
class threadsafe_queue
{

private:
    struct node
    {
        shared_ptr<T> data;
        unique_ptr<node> next;
    };
    
    // 1. 先拿锁,为什么? 按照书中所说, 如果同时调用 pop 和 push, push 会先拿到 tail的锁, 然后 pop会拿到 head的锁, 持有不同的锁, 却操作相同的对象? 这里如何理解呢? 作者说, 害怕从 head读到了 tail节点, 为什么? head.get() == tail, 因为是这样子的, 在他的设计里, 注意一开始, head(new node),tail(head.get()), 他是这么弄的. 所以说, 会出现刚说的那种情况, 通过head锁, 读到了tail节点, 尤其是在只有一个节点的情况下, 这个问题, 我们要理解其上下文环境, 其实解决的问题也很简单, 改进一下就可以了, 我来试着改进一下

    unique_ptr<node> pop_head(){
        unique_lock<mutex> head_lock(head_mutex);  
        node* tail2;   
        {
            再拿一次锁, 否则这个时候如果有人修改了tail结点呢? tail结点始终指向的是空节点, 这个是必须知道的
            // 举个例子: 在没锁的情况下, step1: 第一个线程调用 pop, 执行到  head.get()==tail2的前一句, 被打断 了, step2: 另外一个线程调用 push, 插入了个数据, 这个时候,按理说, 应该已经有了一个数据了, 这个时候 head.get()已经有值了, 应该pop出来啊!
            // 再说一遍, 其实是这样的, 为了保证事务的完整性, 假如数据先是空的, 这个时候 pop先进去了, 我们应该怎么办呢? 告诉程序这是空的, 才对. 实际上, 如果我们只拿头锁, 不拿尾巴锁的话, 被其他线程拿到, 头部结点其实是会被修改的, 然后弹出一个值, 这不是我们想要的            
            // 有这样两个线程 t1 call pop, t2 call push, 
            // case1: t1先拿到 head-mutex, t2拿到 tail-mutex, t1 take tail-mutex
            //     what will happen? t2 push an item, t1 pop an item
            // case2: t1 take head-mutex and tail-mutex, t1 pop nullptr, t2 push an item
            // case3: t1 call pop, t2 call pop, 
            lock_guard<mutex> tail_lock(tail_mutex);
            tail2 = tail;
        }         
        if(head.get()==tail2){
            return nullptr;
        }
        // 需要返回旧的头节点, 所以要单开一个变量
        unique_ptr<node> const old_head=move(head);
        head=move(old_head->next);
        head_lock.unlock();
        return old_head;
    }

public:
    shared_ptr<T> pop(){
        unique_ptr<node> old_head=pop_head();
        return old_head?old_head->data:shared_ptr<T>();
    }
    
    void push(T new_value)
    {
        // 1. 先把要入的元素整好了
        shared_ptr<T> new_data(
            make_shared<T>(move(new_value)));
        unique_ptr<node> p(new node);
        node* const new_tail=p.get();

        // 2. 给尾巴锁加锁, 这里有一个问题是,如果想把两个节点放到一起, 那么其实是不太可能的, 因为单个操作是原子操作,两个操作之间却没有保证原子, 因此需要我们调用的时候保证原子, 也就是说, 需要在同级的单个节点和两个节点操作前, 都加上同一把锁, 这样才能解决问题, 或者设计一个方法, 支持批量插入
        lock_guard<mutex> tail_lock(tail_mutex);
        tail->data=new_data;
        tail->next=move(p);
        tail=new_tail;
    }

private:
    mutex head_mutex;
    mutex tail_mutex;
    
    // 奇葩的设计, 一个是智能指针, 一个是原始指针, 其实就是一回事
    unique_ptr<node> head;    
    node* tail;

public:
    threadsafe_queue():
        head(new node),tail(head.get())
    {}

    threadsafe_queue(const threadsafe_queue& other)=delete;
    threadsafe_queue& operator=(const threadsafe_queue& other)=delete;

};


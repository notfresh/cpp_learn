#include <memory>

using namespace std;


template<typename T>
class queue
{
private:
    struct node
    {
        shared_ptr<T> data;
        unique_ptr<node> next;
    };
    
    // 私有属性
    unique_ptr<node> head;
    node* tail;
    
public:
    // 按照作者所说, pop 的改进在于
    // 1. 其内容使用指针存储, 而非值本身, 所以不必构建实例: 存储值的部分换成了指针,而非实例本身, 和6.4相比
    // 2. tail节点获取只用于比较, 很快
    // 3. pop和push不必再操作同一个锁对象了
    
    shared_ptr<T> pop()
    {
        if(head.get()==tail)
        {
            return shared_ptr<T>();
        }
        shared_ptr<T> const res(head->data);
        // 这里可以缩成一句话, head = head->next; // 貌似是, head本身不会被释放吗? 在赋值的时候, 旧head的内容已经碑额释放了, 但是类似于 old_head 这个变量呢? old_head 这个变量从来没被声明过, 所以无所谓了, 声明 old_head 的意义就在于释放其成员变量本身.          
        unique_ptr<node> const old_head=move(head);
        head=move(old_head->next);
        return res;
    }        

    // 改进
    // 1. push只访问tail节点

    void push(T new_value)
    {
        shared_ptr<T> new_data(
            make_shared<T>(move(new_value)));
        tail->data=new_data;

        // 这个p就是 dummynode, 没有任何意义, 仅仅是尾节点后面的一个节点
        unique_ptr<node> p(new node); // 空节点, 不带数据       
        node* const new_tail=p.get();
        tail->next=move(p);
        
        tail=new_tail; // 这么奇怪的原因太恶心了
    }

    queue():
        head(new node),tail(head.get())
    {}

    queue(const queue& other)=delete;
    queue& operator=(const queue& other)=delete;
    
};


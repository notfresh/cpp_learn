#include <memory>
#include <mutex>

using namespace std;

template<typename T>
class threadsafe_queue
{
    
private:
    struct node{
        shared_ptr<T> data;
        unique_ptr<node> next;    // 之所以把next设计成 unique_ptr,是为了让其自动释放data 
    }; 
    
    mutex head_mutex;
    mutex tail_mutex;
    // 奇葩的设计, 一个是智能指针, 一个是原始指针, 其实就是一回事
    unique_ptr<node> head;    // head是为了释放资源, 但tail不必
    node* tail; // 如果没有必要, 不要使用 unique_ptr

    // size
    int size_ = 0;
 
public:
    shared_ptr<T> pop(){        
        shared_ptr<T> ret;
        lock_guard<mutex> head_lock(head_mutex);
        unique_ptr<node> real_head = move(head->next);

        if(real_head){
            ret = real_head->data;
            head->next = move(real_head->next);                        
        }        
        return ret;
    }
   
    void push(T& new_value)
    {
        // 1. 先把要入的元素整好了, 构建一个链表结点
        shared_ptr<T> new_data = make_shared<T>(move(new_value));
        unique_ptr<node> p(new node);
        p->data = new_data;   
        // 2. 给尾巴锁加锁, 这里有一个问题是,如果想把两个节点放到一起, 那么其实是不太可能的, 因为单个操作是原子操作,两个操作之间却没有保证原子, 因此需要我们调用的时候保证原子, 也就是说, 需要在同级的单个节点和两个节点操作前, 都加上同一把锁, 这样才能解决问题, 或者设计一个方法, 支持批量插入
        lock_guard<mutex> tail_lock(tail_mutex);
        tail->next = move(p);
        size_++;
        tail = tail->next.get();
    }

public:
    threadsafe_queue():
        head(new node), tail(head.get())
    {}

    threadsafe_queue(const threadsafe_queue& other)=delete;
    threadsafe_queue& operator=(const threadsafe_queue& other)=delete;

    int size(){return size_;}

};

#include <zxlib/test_class.h>
#include <zxlib/print.h>
#include <thread>

threadsafe_queue<SimpleClass> q;

void f1(){
    int i=0;
    while(i<10){
        SimpleClass sc(to_string(i));
        q.push(sc);        
        i++;
    }
}

void f2(){
    int i=0;
    while(i<10){
        shared_ptr<SimpleClass> sc = q.pop();        
        if(sc) sc->f1();
        else{
            print("sc is null");
        };
        i++;
    }
}

int main(){
    // thread t1(f1);
    // t1.join();

    // thread t2(f1);
    // t2.join();
    f1();
    print(q.size());
    // q.pop();
    f2();
   
}   
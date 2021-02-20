#include <memory>
#include <mutex>

using namespace std;

template<typename T>
class threadsafe_list
{
    struct node
    {
        mutex m;
        shared_ptr<T> data;
        unique_ptr<node> next; // 不足为奇, 但是就是好奇为啥不同普通指针呢? 好就好在可以自动释放 

        node():
            next()
        {}
        
        node(T const& value):
            data(make_shared<T>(value))
        {}
    };
    
    node head;

public:
    threadsafe_list()
    {}

    ~threadsafe_list()
    {
        remove_if([](T const&){return true;});
    }

    threadsafe_list(threadsafe_list const& other)=delete;
    threadsafe_list& operator=(threadsafe_list const& other)=delete;
    
    // 第一个方法
    void push_front(T const& value)
    {
        unique_ptr<node> new_node(new node(value)); // 缩小锁的范围, 尤其是new等等高成本的东西
        lock_guard<mutex> lk(head.m);
        new_node->next=move(head.next);
        head.next=move(new_node);
    }

    // 第二个方法
    template<typename Function>
    void for_each(Function f)
    {
        node* current=&head;
        unique_lock<mutex> lk(head.m);
        while(node* const next=current->next.get())
        {
            unique_lock<mutex> next_lk(next->m);
            lk.unlock();
            f(*next->data);
            current=next;
            lk=move(next_lk);
        }
    }

    // 第四个方法
    template<typename Predicate>
    shared_ptr<T> find_first_if(Predicate p)
    {
        node* current=&head;
        unique_lock<mutex> lk(head.m);
        while(node* const next=current->next.get())
        {
            unique_lock<mutex> next_lk(next->m);
            lk.unlock();
            if(p(*next->data))
            {
                return next->data;
            }
            current=next;
            lk=move(next_lk);
        }
        return shared_ptr<T>();
    }

    // 第三个方法
    template<typename Predicate>
    void remove_if(Predicate p)
    {
        node* current=&head;
        unique_lock<mutex> lk(head.m);
        while(node* const next=current->next.get())
        {
            unique_lock<mutex> next_lk(next->m);
            if(p(*next->data))
            {
                unique_ptr<node> old_next=move(current->next);
                current->next=move(next->next);
                next_lk.unlock();
            }
            else
            {
                lk.unlock();
                current=next;
                lk=move(next_lk);
            }
        }
    }
};


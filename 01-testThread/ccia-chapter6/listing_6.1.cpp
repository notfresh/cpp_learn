#include <exception>
#include <stack>
#include <mutex>
#include <memory>
#include <zxlib/test_class.h>
#include <zxlib/print.h>

struct empty_stack: std::exception
{
    const char* what() const throw()
    {
        return "empty stack";
    }
};


template<typename T>
class threadsafe_stack{
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack(){}
    threadsafe_stack(const threadsafe_stack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T&& new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        // 无论如何, 你都应该知道, data_push的时候, 调用两个构造函数, 那么这个时候
        data.push(std::move(new_value)); // 因为这里是move, 所以调用了move构造函数
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(
            std::make_shared<T>(std::move(data.top()))); // make_shared 拷贝了一份
        data.pop();
        return res;
    }

    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=std::move(data.top());
        data.pop();
    }

    
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main(){
    SimpleClass t("c1");
    threadsafe_stack<SimpleClass> st;
    st.push(move(t));
    // SimpleClass t2 = move(t);
    // print("t i1: ", t.i1);

}
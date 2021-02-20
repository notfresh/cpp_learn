#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <zxlib/print.h>

using std::unique_lock;
using std::lock_guard;
using std::mutex;
using std::condition_variable;
using std::queue;
using std::thread;

// 这个i 就是传说中, 线程共享的内存, 下面的 process_i 同理,
// 但是呢, 它们分别都只在某一个线程中被修改, 所以不会引起混乱!
int i = 0;
bool more_data_to_prepare()
{   
    if(i< 3){
        i++;
        return true;
    }
    return false;    
}

struct data_chunk
{};

data_chunk prepare_data()
{
    return data_chunk();
}

int process_i = 0;
void process(data_chunk&)
{
    process_i++;
}

bool is_last_chunk(data_chunk&)
{
    if(i == process_i){
        return true;
    }
    return false;  
}

// 线程之间共享的内存
mutex mut;
queue<data_chunk> data_queue;
condition_variable data_cond;



void data_preparation_thread()
{
    print("start data_preparation_thread");
    while(more_data_to_prepare())
    {
        data_chunk const data=prepare_data();
        std::lock_guard<std::mutex> lk(mut);
        print("push data ");
        data_queue.push(data);
        data_cond.notify_one();
    }
}

void data_processing_thread()
{   
    print("start data_processing_thread");
    while(true)
    {
        // std::unique_lock<std::mutex> lk(mut);
        // data_cond.wait(lk,[]{return !data_queue.empty();});

        unique_lock<mutex> locker(mut);
        data_cond.wait(locker, [](){
            return !data_queue.empty();
        });
        data_chunk data=data_queue.front();
        data_queue.pop();
        locker.unlock();
        print("process data ");
        process(data);
        if(is_last_chunk(data))
            break;
    }
}

int main()
{
    thread t1(data_preparation_thread);
    thread t2(data_processing_thread);    
    t1.join();
    t2.join();
}

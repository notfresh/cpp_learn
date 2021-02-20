// #include "threadsafe_queue.h"
#include <zxlib/print.h>
#include <zxlib/threadsafe_queue.h>

using namespace std;

threadsafe_queue<string> que;

void producer(){
    for(int i=0; i<100; i++){
        que.push(to_string(i));
        print("produce: ", "push " + to_string(i) );
        // 一个线程GG, 其他线程也跟着GG
        if(i == 50) {
            int d = 0;
            try{
                print( 1/d);
            }
            catch(...){
                print("error...");
            }            
        }         
        // print(123, 123);
    }       
}

void consumer(){
    for(int i=0; i<100; i++){
        shared_ptr<string> ptr = que.wait_and_pop();
        print("consume: ", ptr->data());
    } 
}

int main(){
    thread t1(producer);
    thread t2(consumer);   
    t1.join();     
    t2.join();
}
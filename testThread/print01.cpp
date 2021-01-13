//
// Created by zxzx on 2020/12/8.
// 两个线程 轮换打印0，1
//

#ifndef ZZZ_PRINT01_H
#define ZZZ_PRINT01_H

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int number;
mutex lck;
int MAX_NUM = 4;

void printOdd(){
    cout << "thread1 started" << endl;
    while(true){
        lck.lock();
        if(number > MAX_NUM){
            lck.unlock();
            break;
        }
        // 业务代码
        if( (number & 1) == 1){
            number++;
            cout << "thread1: " << number << endl;
        }
        lck.unlock();
    }
    cout << "thread1 finished" << endl;
}

void printEven(){
    cout << "thread2 started" << endl;
    while(true){
        lck.lock();
        if(number > MAX_NUM){
            lck.unlock();
            break;
        }
        // 业务代码
        if( (number & 1) == 0){
            number++;
            cout << "thread2: " << number << endl;
        }
        lck.unlock();
    }
    cout << "thread2 finished" << endl;
}

void testPrint01(){
    cout << " start" << endl;
    number = 0;
    thread th1(printOdd);
    thread th2(printEven);
    th1.join(); //开始
    th2.join();
    cout << " finish" << endl;
}


int main(){
    testPrint01();
}

#endif //ZZZ_PRINT01_H

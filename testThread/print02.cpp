//
// Created by zxzx on 2020/12/8.
// 两个线程 轮换打印0，1
//

#ifndef ZZZ_PRINT02_H
#define ZZZ_PRINT02_H

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int number;
mutex lck;
int MAX_NUM = 0;
int end_num = 100;

void printOdd(){
    while(true){
        if(MAX_NUM>end_num) break; //$F,$
        if(MAX_NUM%2==0) { //$f, $t,
            cout << "thread1 " << MAX_NUM << endl; //$2
            MAX_NUM++;//$2
        }
    }
}

void printEven(){
    while(true){
        if(MAX_NUM>end_num) break;
        if(MAX_NUM%2==1) {
            cout << "thread2 " << MAX_NUM << endl;
            MAX_NUM++;//$2
        }
    }
}

void testPrint02(){
    cout << " start" << endl;
    number = 0;
    thread th1(printOdd);
    thread th2(printEven);
    th1.join(); //开始
    th2.join();
    cout << " finish" << endl;
}

int main(){
    testPrint02();
}

#endif //ZZZ_PRINT02_H

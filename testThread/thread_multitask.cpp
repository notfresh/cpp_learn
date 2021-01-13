//
// Created by zxzx on 2020/12/8.
// 两个线程 轮换打印0，1
//

#ifndef ZZZ_PRINT01_H
#define ZZZ_PRINT01_H

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
using namespace std;
int number;
mutex lck;
int MAX_NUM = 4;


template <typename  T>
void time_stat(T&& func){
    using namespace std::chrono;
    auto now = system_clock::now();
    func();
    auto now2 = system_clock::now();
    duration<double> range = now2 - now;
    cout << "消耗了" << range.count() << "秒" << endl;
}

void f1(){
    long num = 0;
    for(int i=0;i<INT_MAX;i++){
        num += i;
    }
    cout << "sum value is " << num << endl;
}

void f1_v(int from, int to, long& sum){
    long num = 0;
    for(int i=from;i<to;i++){
        num += i;
    }
    sum = num;
}

void testPrint01(){
    time_stat([](){
        long s1=0, s2=0;
        int task_cnt = 2;
        thread t1(f1_v, 0, INT_MAX/2, ref(s1));
        thread t2(f1_v, INT_MAX/2, INT_MAX, ref(s2));
        t1.join();
        t2.join();
        cout <<  " 和等于： " << s1 + s2 << endl;
    });

    time_stat([](){
        long s1=0;
        thread t1(f1_v, 0, INT_MAX, ref(s1));
        t1.join();
        cout <<  " 和等于： " << s1 << endl;
    });
}


int main(){
    testPrint01();
    // 结果为
    // 和等于： 2305843005992468481
    //消耗了3.15688秒
    // 和等于： 2305843005992468481
    //消耗了5.73118秒
}


#endif //ZZZ_PRINT01_H

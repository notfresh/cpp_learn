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


void f1(string &a){
    cout << a << endl;
    cout << &a << endl;
}

void testPrint01(){
    string a = "abcef";
    cout << "out: " << &a << endl;
    thread t(f1, ref(a));
    t.join();
}


int main(){
    testPrint01();
}

#endif //ZZZ_PRINT01_H

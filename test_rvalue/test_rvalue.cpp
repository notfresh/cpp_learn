//
// Created by zxzx on 2020/12/27.
//
#include <iostream>
#include "zxlib/my_str.h"

using namespace std;

void print1(MyStr &str) {
    cout << "lvalue call" << endl;
    cout << str << endl;
}

void print1(MyStr&& str) {
    cout << "rvalue call" << endl;
    cout << str << endl;
}

void test_rvalue() {
    MyStr str = "abc";
    print1(move(str)); // move知识做了个类型转换，并没有调用移动构造函数！！
    cout << "after: " <<  str << endl;
    print1(MyStr("zzz")); // 调用右值版
}

int main() {
    test_rvalue();
}




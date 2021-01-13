//
// Created by zxzx on 2020/12/27.
//
#include <iostream>
#include <vector>

using namespace std;

#include <zxlib/my_str.h>

int main() {
    MyStr a = MyStr("Hello");
    cout << "a: " << a << endl;
    MyStr b = move(a); // 调用移动构造函数
    cout << "b: " << b << endl;
    cout << "a: " << a << endl;

}


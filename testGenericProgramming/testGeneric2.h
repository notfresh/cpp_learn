//
// Created by zxzx on 2020/10/11.
//

#ifndef CPP_LEARN_TESTGENERIC2_H
#define CPP_LEARN_TESTGENERIC2_H

#include <iostream>
using namespace std;

// 一个泛型方法，支持多种类型的打印
template<typename T>
void print(T t){
    cout << t << endl;
}

void generic_print(){
    print(12);
    print("abcd");
    print(123.0);
}
#endif //CPP_LEARN_TESTGENERIC2_H

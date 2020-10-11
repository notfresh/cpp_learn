//
// Created by zxzx on 2020/10/11.
//

#ifndef CPP_LEARN_TESTGENERIC2_H
#define CPP_LEARN_TESTGENERIC2_H

#include <iostream>
using namespace std;

template<typename T>
void print(T t){
    cout << t << endl;
}

void generic_f1(){
    print(12);
    print("abcd");
    print(123.0);
}
#endif //CPP_LEARN_TESTGENERIC2_H

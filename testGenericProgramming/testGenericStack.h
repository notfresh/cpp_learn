//
// Created by zxzx on 2020/10/11.
//

#ifndef CPP_LEARN_TESTGENERIC_H
#define CPP_LEARN_TESTGENERIC_H

#include <iostream>
using namespace std;

template<class T>
class Stack{
public:
    T& pop();
    T& top();
    Stack();
    Stack(vector<T>& vctor);
    void push(T& item);
};

#endif //CPP_LEARN_TESTGENERIC_H

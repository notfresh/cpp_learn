//
// Created by zxzx on 2020/12/8.
// 函数对象的测试
//

#ifndef ZZZ_FUNCOJBECT_H
#define ZZZ_FUNCOJBECT_H

#include <iostream>
using namespace std;

template<typename T>
class Bigger{
private: T value;
public:
    Bigger(T t){
        value = t;
    }
    bool operator()(const T& toCompare){
        return value > toCompare;
    }
};

void testBigger(){
    Bigger<int> b(4);
    cout << b(3) << endl; // 1, 即为true
}

#endif //ZZZ_FUNCOJBECT_H

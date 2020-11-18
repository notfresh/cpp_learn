//
// Created by zxzx on 2020/10/9.
//

#ifndef CPP_LEARN_TESTEXTEND_H
#define CPP_LEARN_TESTEXTEND_H

#include <iostream>


class A{
public:
    int m_abc = 1;

};

class B: public A{
public:
    int m_abc = 2;
    const int a = 10;
    B():a(3){}
    B(int x){}
};

void test01(){
    using namespace std;

    B *b = new B;
    cout << b->a << endl; // 3
    B *b2 = new B(3);
    cout << b2->a << endl; // 10
}

#endif //CPP_LEARN_TESTEXTEND_H

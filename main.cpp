#include <iostream>
#include <typeinfo>
#include <vector>
//
// Created by zxzx on 2020/10/13.
//
using namespace std;
#include <iostream>

class B{
public:
    int a = 1;
    int a2 = 1;
    virtual void f1(){
        cout << "base "<< a << endl;
    }
};

class D: public B{
public:
    int a = 2;
    void f2(){
        cout << a << endl;
    }
    virtual void f1(){
        cout << "derived "<< a << endl;
    }
};

void test_extend(){
    B *b = new D;
    cout << sizeof(*b) << endl;
    b->f1();
    // 16
    // base 1

    // 16
    //derived 2
}

void test_extend2(){
    D *b = new D;
    cout << sizeof(*b) << endl;
    b->f2();
    //12
    //2
}

void test_extend3(){
    B *b = NULL;
    cout << "size of NULL point b:" << sizeof(*b) << endl;
    // size of NULL point b:8
}

int t = sizeof(int);


// #include "test_oop/constructor_test.h"
// #include "Lt53_jzoff.h"
#include "testGenericProgramming/testGeneric2.h"

int main() {

    generic_print();
    return 0;
}





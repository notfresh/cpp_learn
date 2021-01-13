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

    A* a = nullptr;
    a = new B();


}

using namespace std;
#include <iostream>

class B2{
public:
    int a = 1;
    int a2 = 1;
    virtual void f1(){
        cout << "base "<< a << endl;
    }
    virtual void f2(){
        cout << a << endl;
    }
};


class D: public B2{
public:
    int a = 2;
//    void f2(){
//        cout << a << endl;
//    }
    virtual void f1(){
        cout << "derived: "<< a << endl;
    }
};

void test_extend(){
    B2 *b = new D;
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

void test_call_virtual(){
    D d;
    B2& b = d;
    b.f1();
}

void test_call_virtual2(){ // 如果一个属性被改写了，但是方法没有别改写，那么方法会调用哪个属性呢？
    D d;
    B2& b = d;
    b.f2();
}


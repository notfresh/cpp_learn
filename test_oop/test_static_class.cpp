//
// Created by zxzx on 2020/12/29.
//
#include <iostream>
using namespace std;

class A{
public:
    int i1 = 1;
    static int a;

    virtual void f1(){
        std::cout << "class A" << std::endl;
    }

    static void f2(){
        cout << a << endl;
    }
};

class B:public A{

};
int A::a = 2;


void test_static(){
    A::f2();
    A a;
    a.f2(); // 实例也可以调用
    B b;
    b.f2();
}

int main(){
    test_static();
}
//
// Created by zxzx on 2020/10/9.
//


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


int main(){
    using namespace std;
    A* a = nullptr;
    a = new B();
    B *b2 = new B();
    a = b2;
    A ao;
    B bo;
    ao = static_cast<A>(bo); // 内容被裁减了，但是指针不会！ dynamic_cast 会报错

}


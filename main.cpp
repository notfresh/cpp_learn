#include <iostream>
#include <typeinfo>
//
// Created by zxzx on 2020/10/13.
//
using namespace std;
#include <iostream>

class B{
public:
    int a = 1;
    int a2 = 1;
    void f1(){
        cout << a << endl;
    }
};

class D: public B{
public:
    int a = 2;
    void f2(){
        cout << a << endl;
    }
};

void test_extend(){
    B *b = new D;
    cout << sizeof(*b) << endl;
    b->f1();
    //8
    //1
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

int main() {
    test_extend();
    test_extend2();
    test_extend3();
    return 0;
}





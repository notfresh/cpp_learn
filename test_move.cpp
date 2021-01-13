//
// Created by zxzx on 2021/1/6.
//
#include <iostream>
using namespace std;

class A{
public:
    A(){}
    A(A& other)=delete;
    A(A&& other){
        cout << "move constructor" << endl;
    }
    A& operator=(A&& other){
        cout << "move assign" << endl;
        return other;
    }
};

A f(){
    A a;
    return a;
}

A g(){
    return A();
}

void test_move(){
    A a1 = f(); // 没有调用move,这里估计编译器直接优化了，直接调用的内存拷贝！！。。。压根没走用户代码
    A a2 = g();
}

void test_move2(){
    A a1;
    A a2 = move(a1);
    A a3;
    a3 = move(a2);

}

int main(){
    test_move();
//    test_move2();
}
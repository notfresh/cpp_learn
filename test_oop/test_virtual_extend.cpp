//
// Created by zxzx on 2020/12/30.
//
#include <iostream>
using namespace std;

class A{
    int a; // 4个字节, 8byte
//    int virtual  f1(){ // 虚函数表
//        return a;
//    }
};

class B: public virtual A{ // 虚继承指针，8byte
    int b ; // 4 byte
};

int main(){
    cout << sizeof(B) << endl; // 16
}

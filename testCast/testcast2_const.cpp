//
// Created by zxzx on 2020/12/9.
//


#include <iostream>
using namespace std;

void test_cast1(){ //@cast
    const int b = 1;
    const int *a = &b;
    int * bp = const_cast<int*>(a);
    //  *a = 3;
    *bp = 3; // 没用
    cout << b << endl;

}

void test_cast2(){
    const int b = 1;
    int  a = static_cast<int>(b);
}

void test_cast3(){
    int b = 1;
    char p = reinterpret_cast<char>(b); // error: reinterpret_cast from 'int' to 'char' is not allowed
}

int main(){
    test_cast3();
}



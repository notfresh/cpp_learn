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
//    char p = reinterpret_cast<char>(b); // error: reinterpret_cast from 'int' to 'char' is not allowed
}

class B{
public:
	int m_iNum;
	B(){}
};

void foo(){
	const B b1;
//	b1.m_iNum = 100; //comile error
	B* b2 = const_cast<B*>(&b1);
	b2->m_iNum = 200; //fine
	cout << b1.m_iNum << endl;
}


int main(){
    test_cast3();
	foo();
}



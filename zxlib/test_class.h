//
// Created by zxzx on 2020/12/29.
//

#ifndef CPP_LEARN_TEST_CLASS_H
#define CPP_LEARN_TEST_CLASS_H

#include <iostream>

class A{
public:
    int i1 = 1;

    virtual void f1(){
        std::cout << "class A" << std::endl;
    }
};

class B: public A{
public:
    int i2 = 2;
    const int a = 10;
    B():a(3){}
    B(int x){}

private:
	void f1(){ // 如果B 不需要被继承了，可以不写 virtual 关键字的
        std::cout << "class B" << std::endl;
    }
};

class C: public B{
public:
	void f1(){
		std::cout << "class C" << std::endl;
	}
};


class SimpleClass{

public:
	int i1 = 1;

	void f1(){
		std::cout << "class A" << std::endl;
	}
};


#endif //CPP_LEARN_TEST_CLASS_H

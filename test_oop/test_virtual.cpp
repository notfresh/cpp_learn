//
// Created by zxzx on 2020/12/29.
//

#include <zxlib/test_class.h>
#include <zxlib/print.h>
void test_virtual(){
    A* a = new B();
    a->f1();
    A* a2 = new C();
    a2->f1();
	a2->A::f1();
}

class X{
public:
	int a=1;

	virtual void f1(){
		print(1);
	}

};

class Y1: virtual public X{
public:
	int a=2;

	virtual void f1(){
		print(2);
	}
};

class Y2: virtual public X{
public:
//	int a=3;
	virtual void f1(){
		print(3);
	}
};

class Z: virtual public Y1, virtual public Y2{

};

int main(){
//    test_virtual();
	Z z;
	print(z.a);
//	z.Y2::f1();
}

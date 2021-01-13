//
// Created by zxzx on 2021/1/13.
//

#include <iostream>
using namespace std;

class B;

class A{
private:
	~A(){};

public:
	friend B;  
	int i1 = 1; //cpp11特性

	virtual void f1(){
		std::cout << "class A" << std::endl;
	}
};

class B{
public:
	void freeA(A* a){
		delete a;
		a = nullptr;
	}
};

int main(){
	A *a = new A();
//	delete a; //这个指针无法被释放了
	B b;
	b.freeA(a);
}
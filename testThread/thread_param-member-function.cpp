//
// Created by zxzx on 2020/12/8.
// 两个线程 轮换打印0，1
//

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
using namespace std;

class SimpleClass{

public:
	int i1 ;

	void f1(){
		std::cout << "class A" << std::endl;
	}
};

void testPrint01(){
	SimpleClass c;
    thread t(&SimpleClass::f1, &c);
    t.join();
}


int main(){
    testPrint01();
}


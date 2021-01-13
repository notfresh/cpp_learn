//
// Created by zxzx on 2021/1/13.
//
// 单线程版本的

#include <mutex>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class A{
public:
	int i1 = 1;

	void f1(){
		std::cout << "class A instance: " << this << std::endl;
	}
};

class B{
public:
	int i1 = 1;

	void f1(){
		std::cout << "class B instance: " << this << std::endl;
	}
};

template <typename T>
class Singleton{
private:
	static mutex m_mutex;
	Singleton(){};
	Singleton(Singleton& other);
	Singleton& operator=(Singleton& other);
	static T * instance;

public:
	static T* getInstance(){ //这里应该返回
		if(!instance){
			lock_guard<mutex> guard(m_mutex); // 使用lock_guard， 防止锁无法释放
			if(!instance){
				instance = new T(); // 这里有一个问题：要不要把T的构造函数设置为私有的呢？ 然后把 Singleton 类做为其友元？这里可以考虑如此设计。
			}
		}
		return instance;
	};
};

template <typename T>
mutex Singleton<T>::m_mutex; // 泛型是无法使用静态类的

template <typename T>
T* Singleton<T>::instance;


void f0(){
	A* single = Singleton<A>::getInstance();
	single->f1();

	A* single2 = Singleton<A>::getInstance();
	single2->f1();

	A* a = new A();
	a->f1();

	B* single3 = Singleton<B>::getInstance();
	single3->f1();

}

int main(){
//	f2();
	f0();

}

// class A instance: 0x7fc27fc02990
// class A instance: 0x7fc27fc02990
// class A instance: 0x7fc27fc029a0
// class B instance: 0x7fc27fc029b0




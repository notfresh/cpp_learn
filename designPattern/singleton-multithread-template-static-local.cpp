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

public:
	T t;
	static Singleton* getInstance(){ //这里应该返回
		static Singleton* instance;
		if(!instance){
			lock_guard<mutex> guard(m_mutex); // 使用lock_guard， 防止锁无法释放
			if(!instance){
				instance = new Singleton(); // 这里有一个问题：要不要把T的构造函数设置为私有的呢？ 然后把 Singleton 类做为其友元？这里可以考虑如此设计。
			}
		}
		return instance;
	};

};

template <typename T>
mutex Singleton<T>::m_mutex; // 泛型是无法使用静态类的



void f0(){
	Singleton<A>* single = Singleton<A>::getInstance();
	single->t.f1();

	Singleton<A>* single2 = Singleton<A>::getInstance();
	single2->t.f1();

	Singleton<B>* singleb = Singleton<B>::getInstance();
	singleb->t.f1();

	Singleton<B>* singleb2 = Singleton<B>::getInstance();
	singleb2->t.f1();
}

int main(){
//	f2();
	f0();

}
/*
class A instance: 0x7ffc18402990
class A instance: 0x7ffc18402990
class B instance: 0x7ffc184029a0
class B instance: 0x7ffc184029a0
 *
 * */





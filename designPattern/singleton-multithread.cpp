//
// Created by zxzx on 2021/1/13.
//
// 单线程版本的

#include <mutex>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;


class Singleton{
private:
	Singleton(){ // 这个方法导致Singleton无法被继承
		cout << "call constructor" << endl;
	};
	static Singleton *instance;
	static mutex m_mutex;

public:
	static Singleton* getInstance(){
		if(instance== nullptr){
			lock_guard<mutex> guard(m_mutex); // 使用lock_guard， 防止锁无法释放
			if(!instance){
				instance = new Singleton(); // 这里有一个问题：要不要把T的构造函数设置为私有的呢？ 然后把 Singleton 类做为其友元？这里可以考虑如此设计。
			}
		}
		return instance;
	};

	static void delInstance(){
		if(instance!= nullptr){
			lock_guard<mutex> guard(m_mutex); // 使用lock_guard， 防止被多次释放
			if(instance){
				delete instance;
				instance = nullptr;
				cout << "deconstruct instance" << endl;
			}
		}
	}
};


Singleton* Singleton::instance = nullptr ;
mutex Singleton::m_mutex;

void f0(){
	Singleton* single = Singleton::getInstance();
	cout << single << endl;
}

void tets_multithread(){
	thread t1(f0);
	t1.join();
	thread t2(f0);
	t2.join();
	thread t3(f0);
	t3.join();
	thread t4(f0);
	t4.join();
	thread t5(f0);
	t5.join();


//	vector<thread> threads(10,t1);

//	for(int i=0;i<10;i++){
//		threads[i].join();
//	}

/** 打印结果如下：
 *
call constructor
0x7f8fc14029e0
0x7f8fc14029e0
0x7f8fc14029e0
0x7f8fc14029e0
0x7f8fc14029e0
 *
 * */
}

void f2(){
	Singleton* single = Singleton::getInstance();
	Singleton* single2 = Singleton::getInstance();
	cout << single << endl;
	cout << single2 << endl;
	Singleton::delInstance();
	single = Singleton::getInstance();
	cout << single << endl;
}


int main(){
	f2();
//	tets_multithread();
}
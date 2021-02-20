//
// Created by zxzx on 2020/10/17.
//

#ifndef ZZZ_SharedPtr_H
#define ZZZ_SharedPtr_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

template<typename T> //首先，这是一个泛型类
class SharedPtr {
public: // 2个构造函数，一个普通指针的有参，一个拷贝构造函数，重载拷贝运算符，重载->,重载星号运算符。
	SharedPtr(T *p) : m_ptr(p), m_cnt(new int(1)) {}

	SharedPtr(SharedPtr &other) : m_ptr(p), m_cnt(other.m_cnt) {
		*m_cnt++;
	}

	SharedPtr& operator=(SharedPtr& other){
		if(this == &other) return *this;
		desc();
		this->m_ptr = other.m_ptr;
		this->m_cnt = other.m_cnt;
		(*m_cnt)++;
	}

	~SharedPtr() {
		decr();
	}

	T* operator->() {
		return m_ptr;
	}

	T& operator*(){
		return *m_ptr;
	}

private:
	int *m_cnt;
	T *m_ptr;

	void desc(){
		*m_cnt--;
		if(*m_cnt == 0){
			delete m_cnt;
			delete m_ptr;
			m_cnt = nullptr;
			m_ptr = nullptr;
		}
	}
};


#endif //ZZZ_SharedPtr_H

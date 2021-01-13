//
// Created by zxzx on 2020/10/17.
//

#ifndef ZZZ_SharedPtr_H
#define ZZZ_SharedPtr_H
#include <iostream>
#include <memory>
#include <string>
using namespace std;

template <typename T> //首先，这是一个泛型类
class SharedPtr{
public: // 2个构造函数，一个普通指针的有参，一个拷贝构造函数，重载拷贝运算符，重载->,重载星号运算符。
    SharedPtr(T* p=NULL) {
        m_refCount = new int(1);// 我们假设这个传入的指针一定是刚刚分配的堆内存的值，如果传入一个已有的指针，那么应该报错，因为可能会重复释放
        m_p = p;
    };

    SharedPtr(const SharedPtr& sp){
        m_p = sp.m_p; // 指向同一个内存位置
        m_refCount = sp.m_refCount;
        ++*m_refCount; // 引用数加1，实际指向的值是公用的
    }

    SharedPtr& operator=(SharedPtr& p){//指向新的其他对象
        if(this==&p) return *this; // 注意自己给自己赋值！！！,这里可以优化
        decr(); // 释放原来的资源
        m_p = p.m_p;
        m_refCount = p.m_refCount;
        ++*p.m_refCount; // p是一个对象，不是一个指针，所以不能写成 p->m_refCount
        return *this;
    }

    T* operator->(){ // 获取指针
        if(m_p) return m_p;
        throw runtime_error("null pointer1"); // 这里注意异常抛出！！，关于异常，我们还可以继续优化！！
    };

    T& operator*(){
        if(m_p)
            return *m_p;
        throw runtime_error("null pointer2");
    }

    ~SharedPtr(){
        decr();
        cout << "deconstructor" << endl;
    }

    int getRefCount(){ // 这个必须有！
        return *m_refCount;
    }

private:
    T* m_p;
    int* m_refCount; // 这个指针

    void decr(){
        --*m_refCount;
        if( *m_refCount == 0){
            cout << " free" << endl;
            delete m_p;
            delete m_refCount;
            m_p = NULL;
            m_refCount = NULL;
        }
    }
};


#endif //ZZZ_SharedPtr_H

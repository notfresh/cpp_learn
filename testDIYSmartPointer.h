//
// Created by zxzx on 2020/10/13.
//

#ifndef CPP_LEARN_TESTDIYSMARTPOINTER_H
#define CPP_LEARN_TESTDIYSMARTPOINTER_H

#include <iostream>
#include <memory>
#include <string>
using namespace std;

template <typename T>
class SmartPrt{
public:
    SmartPrt(T* p=0) {
        m_refCount = new int(1);// 我们假设这个传入的指针一定是刚刚分配的堆内存的值，如果传入一个已有的指针，那么应该报错，因为可能会重复释放
        m_p = p;
    };

    SmartPrt(const SmartPrt& sp){
        m_p = sp.m_p; // 指向同一个内存位置
        m_refCount = sp.m_refCount;
        ++*m_refCount; // 引用数加1
    }

    SmartPrt& operator=(SmartPrt& p){
        decr();
        ++*p.m_refCount;
        m_p = p.m_p;
        m_refCount = p.m_refCount;
        return *this;
    }

    T* operator->(){
        if(m_p) return m_p;
        throw runtime_error("null pointer1");
    };

    T& operator*(){
        if(m_p)
            return *m_p;
        throw runtime_error("null pointer2");
    }

    ~SmartPrt(){
        decr();
        cout << "deconstructor" << endl;
    }

    int getRefCount(){
        return *m_refCount;
    }
private:
    T* m_p;
    int* m_refCount; // 这个指针

    void decr(){
        (*m_refCount)--;
        if((*m_refCount) == 0){
            cout << " free" << endl;
            delete m_p;
            delete m_refCount;

        }
    }
};

class Test{
public:
    Test(){name = "";};

    Test(string& i) {
        name = i;
    }

    Test(string i) {
        name = i;
    }

    Test(char* i) {
        name = i;
    }

    ~Test(){}

    void showName(){
        cout << name << endl;
    }
    string& getName(){
        return name;
    }

private:
    string name;
};

#endif //CPP_LEARN_TESTDIYSMARTPOINTER_H


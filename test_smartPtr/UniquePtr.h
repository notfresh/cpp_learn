//
// Created by zxzx on 2020/10/17.
//

#ifndef ZZZ_SMARTPTR_H
#define ZZZ_SMARTPTR_H
#include <iostream>
#include <memory>
#include <string>
using namespace std;

template <typename T> //首先，这是一个泛型类
class UniquePrt{
public: // 2个构造函数，一个普通指针的有参，一个拷贝构造函数，重载拷贝运算符，重载->,重载星号运算符。
    UniquePrt(T* p= nullptr):m_p(p) {};
    UniquePrt(const UniquePrt& sp) = delete;
    UniquePrt& operator=(UniquePrt& p) = delete; // 改用reset命令，或者移动赋值

    UniquePrt(const UniquePrt&& other):m_p(other.m_p){ // 转移构造的写法
        other.m_p = nullptr;
    };

    UniquePrt<T>& operator=(UniquePrt<T>&& other){ // 转移赋值， 之前的是空的，所以不用处理。万一不是空的呢？这个系统会报异常的吗?
        swap(other); // other现在保存的是原来的指针，等离开命名空间，就会自动被析构，这块不用担心，这里我们也不用自己再释放了
        return *this; //
    };

    ~UniquePrt(){
        if(m_p) delete m_p;
        cout << "deconstructor" << endl;
    }

    T* operator->() const{ // 箭头重载
        cout << "-> reload" << endl;
        return m_p;
    };

    T& operator*() const{ // 指针解析运算符重载
        return *m_p;
    }

    T* release(){ // 释放指针并返回原来的指针
        T* ret = m_p;
        m_p = nullptr; //
        return ret;
    }

    void reset(T* p = nullptr){ // 释放以前的指针，换一个新的
        T* old = m_p;
        if(p != m_p){
            if(m_p) delete m_p;
        }
        m_p = p;
    }

    void swap(UniquePrt& p){
        using std::swap;
        swap(m_p, p.m_p); // 注意交换指针属性，而不是别的
    }

    explicit operator bool() const noexcept {
        return m_p != nullptr; // 这样就棒的多！！
    }
private:
    T* m_p;
};





#endif //ZZZ_SMARTPTR_H

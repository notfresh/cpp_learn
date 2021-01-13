//
// Created by zxzx on 2020/10/25.
//

#ifndef ZZZ_FULL_STRING_H
#define ZZZ_FULL_STRING_H

using namespace std;

#include <iostream>
//DIY_string
class MyStr{
public:
    MyStr(const char* chars=NULL);
    MyStr(const MyStr&);
    MyStr(const MyStr&, int n);
    MyStr(char c, int n);
    ~MyStr();
    MyStr& operator=(const char *chars);
    MyStr& operator=(MyStr &str);
    MyStr& operator+(MyStr &str);
    MyStr& operator+=(MyStr &str);
    char operator[](int index);
    // char operator[](int start, int end); // 胆子再大一点，实现类似python的 a[1:3]这样的
    MyStr& substr(int start, int offset);
    MyStr& index(MyStr &str, int start=0);  // 第一次出现的位置
    bool operator==(MyStr &str);
    friend ostream& operator<<(ostream &out, MyStr &str);
    friend istream& operator>>(istream &in, MyStr &str);
private:
    char * m_chars;
public:
    int size();
    int size_; // 成员函数不能和成员变量重名
};


#endif //ZZZ_FULL_STRING_H

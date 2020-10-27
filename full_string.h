//
// Created by zxzx on 2020/10/25.
//

#ifndef ZZZ_FULL_STRING_H
#define ZZZ_FULL_STRING_H

using namespace std;

#include <iostream>
//DIY_string
class String{
public:
    String(const char* chars=NULL);
    String(const String&);
    String(const String&, int n);
    String(char c, int n);
    ~String();
    String& operator=(const char *chars);
    String& operator=(String &str);
    String& operator+(String &str);
    String& operator+=(String &str);
    char operator[](int index);
    // char operator[](int start, int end); // 胆子再大一点，实现类似python的 a[1:3]这样的
    String& substr(int start, int offset);
    String& index(String &str, int start=0);  // 第一次出现的位置
    bool operator==(String &str);
    friend ostream& operator<<(ostream &out, String &str);
    friend istream& operator>>(istream &in, String &str);
private:
    char * m_chars;
public:
    int size();
    int size_; // 成员函数不能和成员变量重名
};


#endif //ZZZ_FULL_STRING_H

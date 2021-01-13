//
// Created by zxzx on 2020/12/6.
//

#include <string>
#include <iostream>
using namespace std;
#include "zxlib/my_str.h"

void testStringCut(){
    string a = "123456789";
    // 第二个参数表示的是 截取的长度
    string b = a.substr(1, 2); //@字符截取
    cout << b << endl; // 23
}


int f1(int, int);

void test_string_push_back(){
    string a;
    a.push_back('a');
    a.push_back(1+'0');
    cout << a << endl;
}


void testMystr(){
    MyStr a = "abc";
    const char c = a[1];
    cout << c << endl;

    const MyStr a2 = "def";
    char c2 = a2[1];
    cout << c2 << endl;

}


class Sample
{
public:
    void GetValue() const ; // 常量成员函数
    void func(){}
    int m_value;
    Sample();
};

Sample::Sample(){}

void Sample::GetValue() const // 常量成员函数
{
    // m_value = 0; // 出错
    // func(); // 出错
}

int test_const()
{
    const Sample obj;
//    obj.value = 100; // 出错，常量对象不可以被修改
//    obj.func();    // 出错,常量对象上面不能执行 非 常量成员函数
    obj.GetValue();   // OK,常量对象上可以执行常量成员函数
    return 0;
}

int main(){
    test_const();
}

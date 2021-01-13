//
// Created by zxzx on 2021/1/1.
//
#include <iostream>
using namespace std;

class MyException {
public:
    MyException(const char* str) {
        cout << "构造函数"<<endl;
        cout << this << endl;
    }

    //拷贝构造
//    MyException(const MyException& ex) {
//        cout << "拷贝构造"<<endl;
//        cout << this << endl;
//    }

    void what() {
        cout << "异常" << endl;
    }

    ~MyException() {
        cout << "析构函数"<<endl;
        cout << this << endl;
    }

private:
    char* error;
};

void func3() {
    //创建匿名对象并抛出
    throw MyException("有意思");
}

int main()
{
    try {
        func3();
    }
    catch (MyException e) {
        e.what();
    }
    return 0;
}



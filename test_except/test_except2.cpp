//
// Created by zxzx on 2021/1/1.
//
#include <iostream>
using namespace std;

class Person {
    const char *name;
public:
    Person(const char  *name_):name(name_){
        cout << name << "对象构建\n";
    }
    ~Person() {
        cout << name << "对象被销毁\n";
    }
};

int divide(int x,int y) throw(int, float, char){

    Person p1("a"), p2("b");
    if (y == 0) {
        throw "abc"; // libc++abi.dylib: terminating with unexpected exception of type char const*
    }
    return x / y;
}

void test() {
    try{
        divide(5,0);
    }
    catch (int e) {
        cout << "捕获异常";
    }
    catch (...) {
		cout<<"未知类型异常";
	}
}

int main()
{
    test();
    //a对象构建
    //b对象构建
    //b对象被销毁
    //a对象被销毁
}


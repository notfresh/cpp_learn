//
// Created by zxzx on 2021/1/1.
//
#include <iostream>
#include <string>
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

int divide(int x,int y) { // throw(int, float, char)

    Person p1("a"), p2("b");
    if (y == 0) {
        throw "abc"; // libc++abi.dylib: terminating with unexpected exception of type char const*
    }
    return x / y;
}

// 测试divide方法
void test() {
    try{
        divide(5,0);
    }
    // catch (int e) {
    //     cout << "捕获异常1";
    // }
    // catch (const char* msg) {
    //     cout << "捕获字符异常" << msg << endl;
    // }
    // catch (string str) {
    //     cout << "捕获字符异常";
    // }

    catch (...) {
		cout<<"未知类型异常";
	}
}


double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
 
int test2 ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
    //  z = division(x, y);
     divide(5,0);
    //  cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;
   }
 
   return 0;
}

int main()
{
    test();
    //a对象构建
    //b对象构建
    //b对象被销毁
    //a对象被销毁
}


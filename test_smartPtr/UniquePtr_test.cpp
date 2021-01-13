#include <memory>
#include <iostream>
#include "UniquePtr.h"
using namespace std;

class A{

public:
    ~A(){
        cout <<"kill A\n";
    }
};
// 如果程序执行过程中抛出了异常，unique_ptr就会释放它所指向的对象
// 传统的new 则不行
unique_ptr<A> fun1()
{
    unique_ptr<A> p(new A());
    //do something
    return p;
}

void fun2()
{   //  unique_ptr具有移动语义
    unique_ptr<A> p = fun1();// 使用移动构造函数
    // do something
}// 在函数退出的时候，p以及它所指向的对象都被删除释放


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


void test_ptr(){
    UniquePrt<Test> p1(new Test("abcd"));
    p1->showName();
//    UniquePrt<Test> p2;
//    p2 = UniquePrt<Test>(new Test("zzz"));
    p1.reset(new Test("124"));
    p1->showName();

    Test* t = p1.release();
    cout << "t:" <<  t->getName() << endl;
    // 这里做了一个很顽皮的实验，如果把 unique_ptr指向的元素取出来，然后获取它的指针，然后让另外一个unique_ptr接管，那么就出问题了
//    p1.reset( &(*p2)); // 报错了pointer being freed was not allocated
//    UniquePrt<Test> p3 (new Test("xxx"));



}


int main(){
    test_ptr();
}






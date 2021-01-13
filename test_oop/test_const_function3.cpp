//
// Created by zxzx on 2021/1/1.
//
#include <iostream>

using namespace std;

class A{

public:
    int size(){
        return 2;
    }
    int zzz = 3;
    static int v;
    void f1() const {
    	v = 4;
    }

    void print_v(){
    	cout << v << endl;
    }
};
int A::v = 3;

void test_update_static_in_const(){
	A a;
	a.f1();
	a.print_v();
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

int test_const(){
    const A a;
    const Sample obj; // const类型的对象一定要自定义构造函数,z
//    obj.value = 100; // 出错，常量对象不可以被修改
//    obj.func();    // 出错,常量对象上面不能执行非常量成员函数
//    obj.GetValue();   // OK,常量对象上可以执行常量成员函数
    return 0;
}

#include <iostream>
using namespace std;
void f1(int& i){
    cout << i << endl;
}

void f1(const int& i){ // 这是合法的！！
    cout << i << endl;
}

//void f2(int i){}
//void f2(const int i){} // 不构成重载


int main(){

//  std::cout << a.size(); // 会报错，const类型必须调用const方法，const方法也必须调用const方法
//  test_const();
//f2(3);
	test_update_static_in_const();

}


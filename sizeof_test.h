//
// Created by zxzx on 2020/10/25.
//

#ifndef ZZZ_SIZEOF_TEST_H
#define ZZZ_SIZEOF_TEST_H

#include <iostream>
using namespace std;

class Base{
    int a;
public:
    Base():a(0){
        // cout << "Base" << endl;
    }

    Base(int pa):a(pa){}
    virtual ~Base(){
        //cout << "Base deconstructor" << endl;
    };

    Base(const Base & item){
        cout << "copy Base" << endl;
    }

    virtual void f1(){
        cout << "Base f1" << endl;
    }
};

class Derived: public Base{
    int *b;
public:
    Derived(): b(new int(0)){
        // cout << "Derived" << endl;
    }

    Derived(int pb): b(new int(pb)){}

    ~Derived(){
        // cout << "Derived deconstructor" << endl;
    }

    void f1(){
        cout << "Derived f1" << endl;
    }
};


void main_f2(){
    Base *item = new Derived(1);
    delete item;
    // Derived deconstructor
    // Base deconstructor
}

void main_f3(){
    Base item = Derived(1);
    // 打印结果：
    // Derived deconstructor
    // Base deconstructor
    // Base deconstructor
}

void main_f4(){
    Base item = Derived();
    Base *item2 = &item;
    item2->f1();
    // 打印结果：
    // Derived deconstructor
    // Base deconstructor
    // Base deconstructor
}

void main_f5(){
    Base * item = new Derived;
    item->f1();
    delete item;
    // 打印结果：Derived f1
}

void main_f6(){ // 栈对象的虚函数调用
    Base item = Derived();
    item.f1();
    // 打印结果：
    // Base f1，如果不是用指针，或者引用
}


void main_f7(){ // 栈对象的虚函数调用，以引用形式
    Base item = Derived();
    Base& item2 = item;
    item2.f1();
    // 打印结果：
    // Base deconstructor
    // Base f1
    // Base deconstructor
}

void main_f7_1(){ // 栈对象的虚函数调用，以指针形式
    Base item = Derived(); // 这里是一个隐士的类型强转
    Base *item2 = &item;
    item2->f1();
    // 打印结果：
    // Base f1
}

void main_f7_2(){ // 栈对象的虚函数调用，以指针形式
    Derived item;
    Base *item2 = &item;  //这里没有类型强转
    item2->f1();
    // 打印结果：
    // Derived f1
}

void main_f7_3(){ // 栈对象的虚函数调用，以引用形式
    Derived item;
    Base &item2 = item;  //这里没有类型强转
    item2.f1();
    // 打印结果：
    // Derived f1
}

void main_f8(){
    Derived d;
    cout << sizeof(d) << endl;
    // 24
}

class Base2{ //测试sizeof 与 继承
    int a;
    int a2;
public:
    //int pa; //4
//    virtual void f1(){
//        cout << "Base f1" << endl;
//    }
};

class Derived2: public Base2{
public:
    int b;
//    virtual void f1(){
//        cout << "Derived f1" << endl;
//    }
};

void main_f9(){
    Derived2 d;
    cout << sizeof(d) << endl;
    // 24
    // 注释b，16 A的虚拟函数表 + Base2::a与 Derived2::a
    // 注释a，8，A的虚拟函数表
    // 加一个int，直接涨了8

    int * ptr=NULL;
    cout << sizeof(ptr) << endl; // 8
}

void main_f10(){
    int a;
    cout << sizeof(a) << endl;
    cout << sizeof(10) << endl;
}

class Member{
public:
    int m=10;
};

class Test{
public:
    int b;
    int *c;
    Member *m;
    Member m2;
    void f1(){
        cout << b << endl;
        cout << (c == NULL) << endl;
        cout << (m == NULL) << endl;
        cout << m2.m << endl;
    }
    void f2(){
        cout << "Test::f2" << endl;
    }
};

void main_f11(){
    Test* t = NULL;
    cout << t->b << endl;

    Test* t2 = new Test();
    cout << t2->b << endl;
    // 结果：
    // error, code 11
}

void test_f12(){
    // 注意一个Java程序员不能理解地方，如果一个对象是NULL，它是仍然可以调用这个方法的，只要这个方法可以避免使用this指针
    // 因为方法不用创建对象就已经存在
    Test* t = NULL;
    t->f2();

    // 结果：
    // Test::f2
}

void main_f12(){ // 初始化的值
    Test* t2 = new Test();
    t2->f1();
    // 10
    //1
    //1
    //10
}



#endif //ZZZ_SIZEOF_TEST_H

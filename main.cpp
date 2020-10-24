#include <iostream>
#include <typeinfo>
//
// Created by zxzx on 2020/10/13.
//
using namespace std;

#include "a.h"
#include "b.h"

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

void main_f1(){
    f1();
    f2();
}

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
    // 打印结果：
    // Derived deconstructor
    // Base deconstructor
    // Base deconstructor
}

void main_f5(){
    Base * item = new Derived;
    item->f1();
    delete item;
    // 打印结果：
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

int main() {
    main_f7_1();
    main_f7_2();
    main_f7_3();
    return 0;
}





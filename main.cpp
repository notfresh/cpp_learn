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
    Base():a(0){}
    Base(int pa):a(pa){}
    virtual ~Base(){
        cout << "Base deconstructor" << endl;
    };
};

class Derived: public Base{
    int *b;
public:
    Derived(): b(new int(0)){}
    Derived(int pb): b(new int(pb)){}
    ~Derived(){
        cout << "Derived deconstructor" << endl;
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

int main() {
    main_f4();
    return 0;
}

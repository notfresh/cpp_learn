//
// Created by zxzx on 2020/10/25.
//



#include <iostream>
using namespace std;

//template <typename T>
//void f1(T& t){
//    t.fa();
//}

template <typename T>
void f1(T& t){
    t.fa();
    t.fb();
}


class A{
public:
    void fa(){
        cout << "A fa" << endl;
    }
};


class B{
public:
    void fa(){
        cout << "B fa" << endl;
    }
    void fb(){
        cout << "B fb" << endl;
    }
};

int main(){
    A a1;
    f1(a1);
}




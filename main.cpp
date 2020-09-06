#include <iostream>
#include <map>
using namespace std;


class A{
public:
    int m_abc = 1;
    virtual void f1(int n){
        cout << "A.f1," << n << ", abc:" <<  abc << endl;
    }
};
class B: public A{
public:
    int abc = 2;
    virtual void f1(){
        cout << "B.f1," << endl;
    }

    virtual void f1(int n){
        this->A::f1(n);
    }
};

int main() {
    cout << "Hello, World!" << endl;
    A *b = new B;
    b->f1(1);
    return 0;
}


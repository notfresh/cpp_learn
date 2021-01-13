#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;



class A {
public:
    virtual void f() {}

public :
    A() {
        f();
    }
};

class B1 : public A
{
private:
    char *_s;
public:

    B1() {
        _s = new char[1024];
    }

private:

    void f() {
        delete[] _s;
        _s = NULL;
    }

};

class B2 : public A {
private:
    int *_m;
public:
    B2() {
        _m = new int(2016);
    }

private:
    virtual void f() {
        delete _m;
        _m = NULL;
    }
};

int main() {
    A *a1 = new B1();
    A *a2 = new B2();
    delete a1;
    delete a2;
    return 0;
}

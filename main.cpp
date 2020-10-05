#include <iostream>
#include <map>
using namespace std;


class A{
public:
    int m_abc = 1;

};

class B: public A{
public:
    int m_abc = 2;
    const int a = 10;
    B():a(3){}
    B(int x){}
};

int main() {
    cout << "Hello, World!" << endl;
    B *b = new B;
    cout << b->a << endl; // 3
    B *b2 = new B(3);
    cout << b2->a << endl; // 10
}


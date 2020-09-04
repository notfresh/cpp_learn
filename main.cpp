#include <iostream>
#include <map>
using namespace std;
void testLeftValue();
void testMap();
void TestOperater();

#include "test1.h"
#include "test2.h"



int main() {
    cout << "Hello, World!" << endl;
    // testLeftValue();
    //testMap();
     //findNum();
//     int a = 10;
//     func(a);
//
    test01();



    return 0;
}

void test01()
{
    Son s;

    cout << "Son下的m_A = " << s.m_A << endl;
    cout << "Base下的m_A = " << s.Base::m_A << endl;

    s.func();
    s.Base::func();
    s.Base::func(10);

    cout << "Son下的m_A = " << s.m_A << endl;
    cout << "Base下的m_A = " << s.Base::m_A << endl;
}


int& f1(){
    static int a = 10;
    return a;
}

void testLeftValue(){
    int &b = f1();
    f1() = 20;
    cout << b << endl;
}

void TestOperater(){
    A a1, a2;
    a1.a = 10;
    a2.a = 11;
    A a3 = a1 + a2;
    cout << a3.a << endl;
}

void testMap(){
    map<char,int> first;
    first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;

    for (map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << it->first << ":" << it->second << '\n';

}


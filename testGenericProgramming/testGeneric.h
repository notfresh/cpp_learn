//
// Created by zxzx on 2020/10/11.
//

#ifndef CPP_LEARN_TESTGENERIC_H
#define CPP_LEARN_TESTGENERIC_H

#include <iostream>
using namespace std;

template<class T1, class T2> class Point{
public:
    T1 a;
    T2 b;
    Point():a(0),b(0){}
    Point(T1 a1, T2 a2):a(a1),b(a2){};
    Point<T1,T2>& operator=(Point<T1, T2> const & p1);
    friend Point<T1, T2> operator+(Point<T1, T2>& p1, Point<T1, T2>& p2);
};

template<class T1, class T2>
Point<T1, T2>& Point<T1, T2>::operator=(Point<T1, T2> const & p1){
    this->a = p1.a;
    this->b = p1.b;
    return *this;
}

template<class T1, class T2>
Point<T1, T2> operator+(Point<T1, T2>& p1, Point<T1, T2>& p2){
    Point<T1,T2>* p = new Point<T1, T2>; // TODO
    p->a = p1.a+p2.a;
    p->b = p1.b + p2.b;
    return *p;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, Point<T1, T2>& p){
    cout << "(" << p.a << "," << p.b << ")" << endl;
    return out;
}

void generic_t1(){
    Point<int,int> p;
    cout << p << endl;
    Point<int, int> p2(10,2.0);
    Point<int, int> p3(10,5.0);
//    Point<int, int> p4 = p2+p3;
//    Point<int, int> p5 = p4;
    cout << p3 << endl;

}
#endif //CPP_LEARN_TESTGENERIC_H

//
// Created by zxzx on 2020/9/4.
//

#ifndef CPP_LEARN_TEST1_H
#define CPP_LEARN_TEST1_H

# include <iostream>


void func(int &a);
void func(const int &a);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isFlowerN(int n);
void findNum();

class A{
public:
    int a;
    A operator+(const A & a2){
        A a3;
        a3.a = this->a + a2.a;
        return a3;
    }
};



#endif //CPP_LEARN_TEST1_H

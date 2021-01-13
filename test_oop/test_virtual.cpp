//
// Created by zxzx on 2020/12/29.
//

#include <zxlib/test_class.h>

void test_virtual(){
    A* a = new B();
    a->f1();
}

int main(){
    test_virtual();
}
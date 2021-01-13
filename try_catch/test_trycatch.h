//
// Created by zxzx on 2020/12/9.
//

#ifndef ZZZ_TEST_TRYCATCH_H
#define ZZZ_TEST_TRYCATCH_H

#include <iostream>
using namespace std;

void catch_f1(){
    int a = 2;
    int b = 0;
    if(b==0){
        throw b;
    }
    int c = a / b;
}

void catch_f2(){
    try {
        catch_f1();
    }catch (int e){
        cout << "捕获异常" << endl;
    }
}


void test_catch(){
    catch_f2();
}

#endif //ZZZ_TEST_TRYCATCH_H

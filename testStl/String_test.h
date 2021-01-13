//
// Created by zxzx on 2020/10/25.
//

#ifndef ZZZ_STRING_TEST_H
#define ZZZ_STRING_TEST_H

#include <iostream>

using namespace std;


void test_str_len(){
    char c[3];
    char cc[3] = "ab";
    strcpy(c, cc); // C 的库函数，需要学习一下
    cout << c << endl;
}

void test_String_f1(){
    MyStr a = "abc";
    {
        MyStr b = a;
        // delete b; delete无法操作普通对象，只能操作指针
        MyStr *c = &a;
        // delete c; 注意！delete只能释放堆内存，不能释放栈内存，释放栈内存会报错：pointer being freed was not allocated

        MyStr null_str(NULL);
    }
    MyStr d = "aefg";
    a = d;
    // 打印结果
    // char pointer constructor
    //copy constructor
    //char pointer constructor
    //deconstructor
    //char pointer constructor
    //operator=
    //deconstructor
    //deconstructor
    //deconstructor
}


void default_null(char * chars=NULL){
    cout << "call" << endl;
}

void test_default_null(){
    default_null();
}
#endif //ZZZ_STRING_TEST_H

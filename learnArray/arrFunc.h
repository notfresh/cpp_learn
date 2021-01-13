//
// Created by zxzx on 2020/12/7.
//

#ifndef ZZZ_ARRFUNC_H
#define ZZZ_ARRFUNC_H

#include <iostream>
using namespace std;

void set_value(int *from, int *to, int val){
    for(;from != to; from++){
        (*from) = val;
    }
}

void print_array(int *arr, int len){
    for(int i=0;i<len; i++){
        cout << *(arr+i) << endl;
    }
}

void test_set_value(){
    int a[5] = {1,2,3, 4};
    set_value(a+1, a+3, 5);
    print_array(a, 5);

}

int replace(char* str, char c1, char c2){
    int count = 0;
    while( *str ){
        if( *str == c1 ){
            *str = c2;
            count++;
        }
        str++;
    }
    return count;
}


void test_replace(){
//    char a[10] = {'a', 'b', 'c', 'd'};
    char a[10] = "abcd";
    // cout << int(a) << endl; TODO
    int count = replace(a, 'c', 'f');
    cout << a << endl;
}

void test_f11(){
    int *a = new int[10]{1,2,3};
}


void test_1char_pointer(){
    char  *a = new char('a');
    char  *b = new char[3]{'a','b', '\0'};
    cout << a << endl;
    cout << b << endl;
};



void test_arr(){

}

#endif //ZZZ_ARRFUNC_H

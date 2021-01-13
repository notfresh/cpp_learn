//
// Created by zxzx on 2020/12/9.
//


#include <iostream>
using namespace std;

void test_cast1(){ //@cast
    int a = 98;
    char b = static_cast<char>(a);
    cout << b << endl;

    char a1 = 'f';
    int c = static_cast<int>(a1);
    cout << c << endl;
}

void cast_i2f(){
    int i = 1;
    float f = static_cast<float>(i);
    cout << f << endl;
}

void cast_f2i(){
    float i = 1.234;
    int f = static_cast<int>(i);
    cout << f << endl;
}



int main(){
    cast_f2i();
}



//
// Created by zxzx on 2021/1/6.
//


#include <iostream>
#include <fmt/core.h>

using namespace std;

using namespace fmt;

extern int a, b;
int main(){
    cout << a+ 3 + b<< endl;
    print("Hello, world 22222!\n");
    print( format("adfaf {}", 123) );
}


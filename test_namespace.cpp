//
// Created by zxzx on 2021/1/1. @namespace
//

namespace a{
    int a1 = 2;
    int a2 = 3;
    int a3 = 1;
}

#include <iostream>
int main(){
    int a1 = 5;
    using std::cout, std::endl;
    cout << a1 << endl;
    using namespace a;
    cout << a1 << endl;
    cout << a3 << endl;
}


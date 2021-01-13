//
// Created by zxzx on 2020/12/9.
//

#ifndef ZZZ_TESTMACRO_H
#define ZZZ_TESTMACRO_H

#define max_(a,b) ((a)<(b)?(b):(a))

#include <iostream>
using namespace std;

void test_macro_max(){
    cout << max_(1, 2) << endl;
}


#endif //ZZZ_TESTMACRO_H

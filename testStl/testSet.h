//
// Created by zxzx on 2020/11/18.
//

#ifndef ZZZ_TESTSET_H
#define ZZZ_TESTSET_H

#include <set>
#include <iostream>
using namespace std;
void test_set_count(){

    set<int> s;
    s.insert(2);
    cout << s.count(3) << endl;
    cout << s.count(2) << endl;
}
#endif //ZZZ_TESTSET_H

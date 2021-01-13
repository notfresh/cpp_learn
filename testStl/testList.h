//
// Created by zxzx on 2020/10/11.
//

#ifndef CPP_LEARN_TESTLIST_H
#define CPP_LEARN_TESTLIST_H

#include <list>
#include <iostream>
using std::list;
using namespace std;

void f1(){
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    for(list<int>::iterator it=l1.begin();it!=l1.end();it++){
        cout << *it << endl;
    }
}

void f2(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(3);
    list<int> l1(v1.begin(), v1.end());
    for(list<int>::iterator it=l1.begin();it!=l1.end();it++){
        cout << *it << endl;
    }
}

#endif //CPP_LEARN_TESTLIST_H

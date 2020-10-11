//
// Created by zxzx on 2020/10/11.
//

#ifndef CPP_LEARN_TESTMAP_H
#define CPP_LEARN_TESTMAP_H
#include <list>
#include <map>
#include <iostream>
using namespace std;

void map_f1(){
    map<int, int> m;
    typedef  map<int, int>::iterator map_iter;
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(2,1));
    m.insert(pair<int,int>(3,1));
    m.erase(m.begin()++);
    m.erase(3);
    for(map_iter it=m.begin();it != m.end(); it++){
        cout << it->first << "," << it->second << endl;
    }

}
#endif //CPP_LEARN_TESTMAP_H

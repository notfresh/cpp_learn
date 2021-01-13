//
// Created by zxzx on 2020/12/27.
//
#include <iostream>
#include <vector>

using namespace std;

void f1(int& i){
    cout << i << endl;
}

void f1(const int& i){
    cout << i << endl;
}

int main() {
    int a = 0;
    const int &b = 1;
    f1(a);
}





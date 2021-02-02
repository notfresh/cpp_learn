//
// Created by zxzx on 2020/12/28.
//
#include <iostream>
#include <string>
using namespace std;

int inline max_(int a, int b){
    return a>b?a:b;
}

class A{
	using std::string;
};
int main(){
    int a = 10, b = a+ 1;
    cout << "a is " << a << ", and b is " << b << endl;
    cout << "the greater one is " << max_(a, b) << endl;
    return 0;
}


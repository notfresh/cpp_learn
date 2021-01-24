//
// Created by zxzx on 2021/1/22.
//
#include "a.h"
void f1(){
	int a = 11;
}

struct x{
	int b;
	int c;
	int d;
};

#include <iostream>
using namespace std;
int main(){
	x a;
	a.c = 10;
	a.c = 3;
	cout << a.c << endl;
}

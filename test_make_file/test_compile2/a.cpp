//
// Created by zxzx on 2021/1/22.
//
#include "head.h"
#include <iostream>

using namespace std;

void f1(){
	int a = 11;
}

void f2(int& c);

int main(){
	int b = 10;
	f2(b);
	cout <<  b << endl;

}

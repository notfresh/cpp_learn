
#include <iostream>
#include "head.h"

using namespace std;

void f1(); // f1必须声明

void f2(int&& c){
	c = 100;
}

void f2(int& c){
	c = 2;
}


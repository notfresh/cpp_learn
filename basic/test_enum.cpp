//
// Created by zxzx on 2021/2/2.
//
#include <zxlib/print.h>

enum A{
	a, b, c // 结尾不能有 分号
};

class A2{
	enum method{GET, POST};
};

class B2{
	enum method{GET, POST}; // 无需使用 static 修饰，因为method是类型

	void f1(){
		A c2 = a;
		A b2 = b;
		print(b2, c2);

		method x = GET;
	}
};

void f1(){
	A c2 = a;
	A b2 = b;
	print(b2, c2);

	method x = GET;
}

int main(){
 	f1();
}

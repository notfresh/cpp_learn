//
// Created by zxzx on 2021/1/20.
//
#include <zxlib/using_std.h>

int main(){
//	cerr << 111 << endl;
	string a("abcdef");
	string_view v("a");
	print(a.find(v)); // Cpp23
	print("abcd", 124, "八成");
}

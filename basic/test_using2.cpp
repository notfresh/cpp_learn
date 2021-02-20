//
// Created by zxzx on 2020/12/28.
//
#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;
using std::cout; // std::cin;
using std::endl;


namespace x1{
	void f1(){
		string s1 = "abc\n";
		cout << s1;
	}

}

enum Method { // HTTP方法
	Invalid, Get, Post, Head, Put, Delete
};

int main(){

    cout << "a is \n" ;
	string a = "abc\n";
	cout << a;
	map<int, int> m_ = {{1,2}, {2,4}};

	for(auto i = m_.begin();i!=m_.end();i++){
		cout << i->first << ", " << i->second << "\n";
	}

	x1::f1();

	map<string, Method> m2_ {
			{"1", Get},
			{"2", Post}
	};
	for(auto i = m2_.begin();i!=m2_.end();i++){
		cout << i->first << ", " << i->second << "\n";
	}
	auto iter = m2_.find("3");

	cout << (iter == m2_.end()) << endl;
    return 0;
}


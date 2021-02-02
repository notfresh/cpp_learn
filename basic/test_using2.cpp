//
// Created by zxzx on 2020/12/28.
//
#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;
using std::cout; // std::cin;

namespace x1{
	void f1(){
		string s1 = "abc";
		cout << s1;
	}

}

int main(){

    cout << "a is \n" ;
	string a = "abc\n";
	cout << a;
	map<int, int> m_ = {{1,2}, {2,4}};

	for(auto i = m_.begin();i!=m_.end();i++){
		cout << i->first << ", " << i->second << "\n";
	}

	x1::f1();
    return 0;
}


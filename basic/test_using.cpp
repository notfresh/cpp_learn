//
// Created by zxzx on 2020/12/28.
//
#include <iostream>
#include <string>
#include <map>



class A{
	// using namespace std; 这是报错的!
	using string = std::string;
	using map = std::map<string, string>;
	string f1(){
		return "abc";
	}
};

int main(){
	// using std::string;
	// using std::cout;
	using namespace std;
    cout << "a is \n" ;
	string a = "abc\n";
	cout << a;
    return 0;
}


//
// Created by zxzx on 2021/1/20.
//
#include <zxlib/using_std.h>


void test_class1(){
	string url = "http://www.jianshu.com";
	print(url.substr(0,7) == "http://");
}

void test_find(){
	string url = "http://www.jianshu.com";
	print(url.find( "://"));
}


vector<string> splitx(const string& s, const string& spitter){
	vector<string> ret; // 1
	int p1 = 0;
	int p2;
	int len = spitter.size();
	int slen = s.size();
	while(true){
		p2 = s.find(spitter, p1);
		if(p2 == string::npos) p2 = slen;
		ret.push_back(s.substr(p1, p2-p1));
		p1 = p2+len;
		if(p1>slen) break;
	}
	return ret;
}


void test_splitx(){
	string s1 = "1 2 3 4 56";
	string spliter = string(" ");
	vector<string> aa = splitx(s1, spliter);
	for(string s: aa){
		cout << s << endl;
	}

	print("abc"+to_string(124) );
}

void print_stoi(){
	string a = "10a";
	print(stoi(a));
}

void print_substr1(){
	string a = "a10a";
	print(a.substr(1));

	string a2 = "a";
	print(a2.substr(1).size());
}

void test_append(){
	string a = "a10a";
	print(a.append("xxx"));
}

void test_append2(){
	print(string("a10a") + "abc" + "efg");
	print("a10a" + string("abc") + "efg");
}



int main(){
//	test_class1();
//	test_find();
//	print_stoi();
//	print_substr1();
//	test_append();
//	test_append2();
	test_splitx();
}
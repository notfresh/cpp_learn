//
// Created by zxzx on 2021/1/20.
//



#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
#define a 10
using std::string;

class str_util {
public:
	static string strip(const string &s, const string &chars = "") {
		if (s.empty())
			return s;

		string s1 = s;
		//默认为空字符
		if (chars.empty()) {
			string::iterator siter = s1.begin();
			while (siter != s1.end()) {
				if (isspace(*siter))
					siter = s1.erase(siter);
				else
					break;
			}

			if (s1.empty())
				return s1;

			siter = s1.end();
			while (siter != s1.begin()) {
				if (isspace(*--siter))
					siter = s1.erase(siter);
				else
					break;
			}
		}
		else {
			string::iterator siter = s1.begin(); //abcadefgabc abc
			while (siter != s1.end()) {
				//
				if (chars.find(*siter) != string::npos)
					siter = s1.erase(siter);
				else
					break;
			}

			if (s1.empty())
				return s1;

			siter = s1.end();
			while (siter != s1.begin()) {
				if (chars.find(*--siter) != string::npos)
					siter = s1.erase(siter);
				else
					break;
			}
		}

		return s1;
	}

	static string lstrip(const string &s, const string &chars = "") {
		if (s.empty())
			return s;

		string s1 = s;
		if (chars.empty()) { //默认为空字符
			string::iterator siter = s1.begin();
			while (siter != s1.end()) {
				if (isspace(*siter))
					siter = s1.erase(siter);
				else
					break;
			}
		} else {
			string::iterator siter = s1.begin();
			while (siter != s1.end()) {
				if (chars.find(*siter) != string::npos)
					siter = s1.erase(siter);
				else
					break;
			}
		}

		return s1;
	}
//
	static string rstrip(const string &s, const string &chars = ""){
		if (s.empty())
			return s;

		string s1 = s;
		if (chars.empty())  { //默认为空字符
			string::iterator siter = s1.end();
			while (siter != s1.begin()){
				if (isspace(*--siter))
					siter = s1.erase(siter);
				else
					break;
			}
		}
		else{
			string::iterator siter = s1.end();
			while (siter != s1.begin()){
				if (chars.find(*--siter) != string::npos)
					siter = s1.erase(siter);
				else
					break;
			}
		}

		return s1;
	}
};


int main() {
	string a2 = "";
	cout << "abc" + a2 + "efg" << endl;
	const char *PROGRAM_VERSION = "1.5";
	fprintf(stderr, "Webbench - Simple Web Benchmark %s %s \n", PROGRAM_VERSION,
			"Copyright (c) Radim Kolar 1997-2004, GPL Open Source Software.\n"
	);

	string str1 = "abcadefabc", str2 = "abc";
	string str3 = str_util::strip(str1, str2);
	cout << str3 << endl;
}
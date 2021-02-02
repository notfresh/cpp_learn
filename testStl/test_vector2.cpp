//
// Created by zxzx on 2020/11/18.
//


#include <vector>
#include <iostream>
#include <fstream>
#include <zxlib/print.h>
using namespace std;

void test_vector(){
	vector<int> tmp{2,1};
//    vector<vector<int,int> > vctr(3, tmp); //@双层vector
    vector<vector<int>> vctr(3); //@双层vector
//    for(int i=0; i<3; i++){
//    	print(vctr[i][0]);
//    	print(vctr[i][1]);
//    }
}

void test_vector1(){
//	vector<vector<int,int>> vctr(3); //@双层vector
//	for(int i=0; i<3; i++){
//		print(vctr[i][0]);
//		print(vctr[i][1]);
//	}
}

void overvisit(){
	vector<int> ivec(10,2);
	cout<<ivec[0]<<endl;
	auto p3 = ivec.begin()+3;
	cout << *p3 << endl;
	ivec.erase(ivec.begin()+2);
	cout << *p3 << endl;
}

void test_size(){
	std::vector<int> v;
	std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
	v.resize(100);
	std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
	v.clear();
	std::cout << "Capacity after clear() is " << v.capacity() << '\n';
	v.shrink_to_fit();
	std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
}

int main(){
//	test_vector();
//	overvisit();
	test_size();
}




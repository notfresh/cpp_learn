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

// 测试一下基本的 priority_queue的写法
#include <queue>
#include <zxlib/print.h>
void test_priority_queue(){
	std::priority_queue<int, std::vector<int>, greater<int>> q;
	q.push(1);
	q.push(3);
	q.push(5);
	q.push(2);
	while(!q.empty()){
		int t = q.top();
		print(t);
		q.pop();
	}
}


//测试查找
void test_find(){
	vector<vector<int>> tmp{{1,2,3}, {1,2}};
	vector<int> tmp2{1,2,5};
	// vector<int> tmp3{1,2,4};
	// tmp.push_back(tmp2);
	// print(tmp);
	print(find(tmp.begin(), tmp.end(), tmp2)!=tmp.end());
}

int main(){
//	test_vector();
//	overvisit();
//	test_size();
	// test_priority_queue();
	test_find();
}




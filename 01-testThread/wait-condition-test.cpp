//
// Created by zxzx on 2021/1/18.
//

# include <thread>
#include <iostream>

using namespace std;

int main(){
	thread t([]{
		cout << "111" << endl;
	});
	t.join();
	return 0;
}
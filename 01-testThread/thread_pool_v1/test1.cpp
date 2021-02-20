//
// Created by zxzx on 2021/1/19.
//
#include <zxlib/print.h>
#include <thread>

using namespace std;
int main(){
	print(thread::hardware_concurrency());
}

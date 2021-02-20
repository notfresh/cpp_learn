// #include "zxlib/using_std.h"
#include <future>
#include <zxlib/print.h>

using namespace std;

int find_the_answer_to_ltuae()
{
	int d = 0;
    return 42/d;
}

double get_double(double x)
{
    return 42 + x;
}
void* get_pointer(){
	return nullptr;
}

void do_other_stuff(){}

void f1(){
	future<int> the_answer=async(find_the_answer_to_ltuae);
	do_other_stuff();
	print(the_answer.get());
}

void f2(){
	// 这个future的类型跟函数返回值密不可分, 不能用错了
	// 这个async 类似于 thread, 只不过返回的是一个future类型, 如果没有返回类型, 用 thread 就好
	future<double> ret = async(get_double, 10);
	print(ret.get());
}

void f3(){
	future<void*> ret = async(get_pointer);
	print(ret.get());
}

int main()
{
	f1();
    // f2();
	// f3();
}

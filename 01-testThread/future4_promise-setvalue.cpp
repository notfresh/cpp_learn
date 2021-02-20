//
// Created by zxzx on 2020/12/8.
//
#include <zxlib/using_std.h>


void mysum(int k, promise<long>& promi){ // 注意要使用引用 @promise
	long sum = 0;
	for(long i=0;i<pow(10,k);i++){
		sum += i;
	}
	promi.set_value(sum);
}


void f1(){
	promise<long> promi;
	future<long> ret = promi.get_future();
	thread t1(&mysum, 5,  ref(promi)); // promise是一个对象
	print(ret.get());
	t1.join();
}

void test_set_value(future<int>& futu){
	int v = futu.get();
	print(v);
}

void f2(){
	promise<int> prom;
	future<int> futu = prom.get_future();
	thread t1(test_set_value, ref(futu));
	prom.set_value(100);
	t1.join();
}


int main() {
//	f1();
	f2();
}

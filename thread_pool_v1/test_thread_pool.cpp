//
// Created by zxzx on 2021/1/8.
//
# include <ctime>
# include <cmath>
# include <zxlib/print.h>
# include "thread_pool.h"
# include <string>

void time_wrap(std::function<void()> f){
	clock_t c1 = clock(); // @clock @time
	f();
	clock_t c2 = clock();
	print(double(c2-c1)/CLOCKS_PER_SEC);
}

void f1(){

	long sum = 0;
	for(long i=0;i<pow(10,8);i++){
		sum += i;
	}
	print(sum);

}

void f2(){
	long sum = 0;
	for(long i=0;i<pow(10,8);i++){
		sum += i;
	}
	print(sum);
}

void f3(){
	long sum = 0;
	for(long i=0;i<pow(10,8);i++){
		sum += i;
	}
	print(sum);
}


void f4_thread_pool(){ // @thread_pool
	thread_pool tp;
	tp.submit(f1);
	tp.submit(f2);
	tp.submit(f3);
	tp.submit(f3);
}


//# include "zxlib/test_class.h"
//std::string operator*(char c, int i){
//	return "";
//}

int main(){
	time_wrap(f1);
	time_wrap(f2);
	time_wrap(f3);
	time_wrap(f3);
	print("**************");
	time_wrap(f4_thread_pool);
	/**
	 *
	 * 经过测试，这个线程池不仅没有提速，反而减速了， 妙啊！！！
* 4999999950000000
2.69375
4999999950000000
2.55644
4999999950000000
2.52761
4999999950000000
2.54738
**************
线程数量：
4
4999999950000000
4999999950000000
4999999950000000
4999999950000000
15.4149
	 */

}

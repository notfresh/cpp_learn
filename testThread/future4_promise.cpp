//
// Created by zxzx on 2020/12/8.
//


#include <zxlib/print.h>
#include <future>
#include <cmath>
using namespace std;

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
	thread t1(&mysum, 5,  ref(promi)); // @ref
	print(ret.get());
	t1.join();
}

using namespace std;
int main() {
	f1();
}

/**	结果是随机的

enter f1,
abc
1
1

 ========
abcenter f1,
1
1

}
*/


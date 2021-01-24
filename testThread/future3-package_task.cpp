//
// Created by zxzx on 2020/12/8.
//


#include <zxlib/print.h>
#include <future>
using namespace std;

long mysum(int k){

	long sum = 0;
	for(long i=0;i<pow(10,k);i++){
		sum += i;
	}
	return sum;
}


void f1(){
	packaged_task<int(int)> task(mysum);
	future<long> ret = task.get_future();
	thread t1(task, 5 );
	print(ret.get());
	t1.join();
}

using namespace std;
int main() {
	A a;
	future<int> fu1 = async(&A::f1, &a, 1); //@future
	print("abc");
	print(fu1.get());
	print(1);
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


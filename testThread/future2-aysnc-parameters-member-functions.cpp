//
// Created by zxzx on 2020/12/8.
//


#include <zxlib/print.h>
#include <future>
using namespace std;

class A{

public:
	int f1(int i){
		print("enter f1,");
		return i;
	}

};

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


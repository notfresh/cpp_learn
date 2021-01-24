//
// Created by zxzx on 2020/12/8.
//

#include <zxlib/using_std.h>

int f1(int i){
	print("enter f1");
	return i;
}


int main(){
	future<int> fu1 = async(f1, 1); //@future
	print("abc");
	print(fu1.get());
	print(1);
/**
enter f1
abc
1
1
	 * */
}



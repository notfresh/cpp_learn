//
// Created by zxzx on 2021/1/12.
//

#include <iostream>
#include "threadsafe_logger.h"
#include "stdio.h"
//using namespace std;
void f1(){
	std::cout << 111 << std::endl;
	initLogger("info.txt", "warn.txt", "error.txt");
	LOG(INFO) << "Hello" ;
	printf("This fake error is in \"%s\" on function %s line %d.\n", __FILE__,__FUNCTION__,  __LINE__ );
}

int main(){
	f1();
}
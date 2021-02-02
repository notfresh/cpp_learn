//
// Created by zxzx on 2021/1/15.
//

#include "stdio.h"

int main(){
	a:{printf("%d", 111);
	}
	for(int i=0;i<10;i++){
		i++;
		goto a;
	}
}
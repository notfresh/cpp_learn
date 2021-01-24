//
// Created by zxzx on 2021/1/17.
//

#include "unistd.h"
#include "signal.h"
#include "stdio.h"

void handler(int num){
	printf("Hello\n");

}

int main(){
	int i;
	signal(SIGALRM, handler);
	alarm(3);
	for(int i=0;i<7;i++){
		printf("sleep %d..\n", i);
		sleep(1);
	}
}

//
// Created by zxzx on 2021/1/21.
//
#include "zxlib/print.h"

int main(){
	int arr[2][3];
	for(int i=0;i<2;i++) {
		for (int j = 0; j < 3; j++)
			arr[i][j] = i + j;
	}

	for(int i=0;i<2;i++) {
		for (int j = 0; j < 3; j++)
			print(arr[i][j]);
	}
}


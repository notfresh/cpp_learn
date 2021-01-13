
#include <ctype.h>
#include <stdio.h>

int main(){
	char str1[] = "C Language";
	char *str2 = "C Language";
	str1[1] = '-';
	*(str2+1) = '-';  //错！不能改变字符串常量的值
	printf("str1 = %s\n", str1);
	return 0;
}







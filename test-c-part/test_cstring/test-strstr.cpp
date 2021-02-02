//
// Created by zxzx on 2021/1/17.
//
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

//int main()
//{
//	const char* url = "http://abc.com";
//	int i;
//	i=strstr(url,"://")-url + 3;
//
//	printf("子字符串是： %d\n", i);
//
//	const char *ret;
//	ret = strchr(url+i,'/');
//	printf("zzz%s", ret);
//	return(0);
//}

int main ()
{
	int len;
	const char str[] = "https://www.runoob.com";
	const char ch = '1';
	char *ret;
	ret = const_cast<char* >(strrchr(str, ch));

	printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);


	int a = atoi('\0'+1);

	return(0);
}
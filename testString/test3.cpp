#include <iostream>

using namespace std;

#include <ctype.h>

char *strupr(char *str){
	char *orign=str;
	for (; *str!='\0 '; str++)
		*str = toupper(*str);
	return orign;
}

int main(int argc,const char* argv[])
{


    return 0;
}








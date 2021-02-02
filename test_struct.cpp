//
// Created by zxzx on 2021/1/22.
//
#include <zxlib/using_std.h>
typedef struct request{
	int port;
	char* host;
};

void print_request(struct request *req){
	print(req->port);
	print(req->host);
}

int main(){
	struct request a{8080, "127.0.0.1"};
	print_request(&a);


	struct request b;
	b.host= "abc";
	print_request(&b);

//	char* p = "abcd";
//	print(p);
}

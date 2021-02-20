//
// Created by zxzx on 2021/1/22.
//
#include <zxlib/using_std.h>
#include <zxlib/test_class.h>
struct request{
	int port;
	char* host;
};

void print_request(struct request *req){
	print(req->port);
	print(req->host);
}

void test_new_struct(){
	request* q = new request;
	SimpleClass* sc = new SimpleClass;
}



int main(){
	// struct request a{8080, "127.0.0.1"};
	// print_request(&a);


	// struct request b;
	// b.host= "abc";
	// print_request(&b);

	

//	char* p = "abcd";
//	print(p);
	test_new_struct();
}

//
// Created by zxzx on 2021/1/21.
//

#include <cstdio>
#include <getopt.h>
#include <unistd.h>
#include <zxlib/print.h>


void test_get_opt(int argc, char* argv[]){
	int opt;
	char *options = "a::bc";
	while((opt=getopt(argc, argv, options))!=-1){
		printf("opt = %c\t\t", opt);
		printf("optarg = %s\t\t",optarg);
		printf("optind = %d\t\t",optind);
		printf("argv[optind] = %s\n",argv[optind]);
	}
}

void test_get_opt_long(int argc, char* argv[]){
	int opt;
	int digit_optind = 0;
	int option_index = 0;
	char *optstring = "a:b:c:d";
	static struct option long_options[] = {
			{"aa", required_argument, NULL, 'a'},
			{"bb",  no_argument,       NULL, 'b'},
			{"cc", optional_argument, NULL, 'c'},
			{0, 0, 0, 0}
	};

	while ( (opt = getopt_long(argc, argv, optstring, long_options, &option_index)) != -1)
	{
		printf("opt = %c\t", opt);
		printf("optarg = %s\t", optarg);
		printf("optind = %d\t", optind);
		printf("argv[optind] = %s\t",  argv[optind]);
		printf("option_index = %d\n", option_index);
	}
}


int main(int argc, char* argv[]){
//	test_get_opt(argc, argv);
	test_get_opt_long(argc, argv);

}
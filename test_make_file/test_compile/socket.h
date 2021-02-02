/* $Id: socket.c 1.1 1995/01/01 07:11:14 cthuang Exp $
 *
 * This module has been modified by Radim Kolar for OS/2 emx
 */
#ifndef CPP_LEARN_A_H
#define CPP_LEARN_A_H
/***********************************************************************
  module:       socket.c
  program:      popclient
  SCCS ID:      @(#)socket.c    1.5  4/1/94
  programmer:   Virginia Tech Computing Center
  compiler:     DEC RISC C compiler (Ultrix 4.1)
  environment:  DEC Ultrix 4.3 
  description:  UNIX sockets code.
 ***********************************************************************/


#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define METHOD_GET 0
#define METHOD_HEAD 1
#define METHOD_OPTIONS 2
#define METHOD_TRACE 3

const char* PROGRAM_VERSION = "1.5";

//enum method_t { METHOD_GET, METHOD_HEAD, METHOD_OPTIONS, METHOD_TRACE };
//method_t method = METHOD_GET;

struct bench_request{
	int http10; // http版本，根据请求方法来定
	char* proxyhost;
	int proxyport; // 接受的代理服务器

	int method;
	char* url; // 用户传进来的url
	char* host;

	char *request;// 生成的请求报文

	int clients;
	int benchtime;

	int force;
	int force_reload;

	bench_request(){
		http10=1;
		method=METHOD_GET;
		clients=1; // 这是一个整数
		force=0;
		force_reload=0;
		proxyport=80;
		proxyhost=NULL;
		benchtime=30; // 默认执行30秒
	}
};

int Socket(const char *host, int clientPort)
{
    int sock;
    unsigned long inaddr;
    struct sockaddr_in ad;
    struct hostent *hp;
    
    memset(&ad, 0, sizeof(ad));
    ad.sin_family = AF_INET;

    inaddr = inet_addr(host); // 将一个点分十进制的IP字符串转化为网络字节序二进制位对应的无符号整型。
    if (inaddr != INADDR_NONE)
        memcpy(&ad.sin_addr, &inaddr, sizeof(inaddr));
    else
    {
        hp = gethostbyname(host);
        if (hp == NULL)
            return -1;
        memcpy(&ad.sin_addr, hp->h_addr, hp->h_length);
    }
    ad.sin_port = htons(clientPort);
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        return sock;
    if (connect(sock, (struct sockaddr *)&ad, sizeof(ad)) < 0)
        return -1;
    return sock;
}

#endif
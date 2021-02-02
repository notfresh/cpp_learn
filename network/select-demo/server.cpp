//
// Created by zxzx on 2021/1/11.
//

// socketaddr_in, sin_family, sin_port,sin_addr

// @network
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define SERV_PORT 6666

void perr_exit(const char *s)
{
	perror(s);
	exit(-1);
}

int main(void){
	struct sockaddr_in serv_addr, clie_addr;
	int listenfd, cfd, maxfd, maxi;
	int len;
	socklen_t clie_addr_len;
	int nready, client[FD_SETSIZE];

	char buf[BUFSIZ]; // BUFSIZ， 这是一个系统宏，指定缓存的大小

	listenfd = socket(AF_INET, SOCK_STREAM, 0);// man 7 ip 查看API接口

	bzero(&serv_addr, sizeof(serv_addr)); // 局部变量手动初试化为0，防止奇怪的事情发生 在 #<strings.h>
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // p87@LHPSP.pdf, 游双的Linux 高性能系统服务器编程
	serv_addr.sin_port = htons(SERV_PORT);

	bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	listen(listenfd, 128); // 默认值

	maxfd = listenfd;
	maxi = -1;
	for(i=0; i<FD_SETSIZE; i++){
		client[i] = -1;
	}

	fd_set rset, allset; // 不是指针，而是具体的位图
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);

	while(1){ // 每次循环都去一个有数据的套接字出来
		rest = allset;
		//
		nready = select(maxfd+1, &rset, NULL, NULL, NULL);
		if(nready < 0){
			perr_exit("select error");
		}

		if(FD_ISSET(listenfd, &reset)){  // 门口有客人来了， 门口就是listenfd
			clie_addr_len = sizeof(clie_addr);
			// 根据select返回的结果， 一定是有一个
			cfd = accept(listenfd, (struct sockaddr *)&clie_addr, &clie_addr_len);
			printf("recived from %s at PORT \n",
					inet_ntop(AF_INET, &clie_addr.sin_addr, str, sizeof(str)),
					ntohs(clie_addr.sin_port)
					);
		}

		for(i=0; i< FD_SETSIZE; i++){
			if(client[i] < 0){
				client[i] = cfd; // 把套接字存储起来
				break;
			}
		}

		if(i == FD_SETSIZE){
			fputs("too many clients");
			exit(1);
		}

		FD_SET(cfd, &allset); //
		if (cfd > maxfd) maxfd = cfd;
		if (i > maxi) maxi = i;

		if(--nready == 0) continue;
	}


	printf("server ready! wait for connection...");
	clie_addr_len = sizeof(clie_addr); // c语言早期版本先声明后定义，我们保持这个传统

	// 在 监听一个socket, 在此阻塞


	while(1){
		len = read(cfd, buf, sizeof(buf));
		for(int i=0; i<len; i++){
			buf[i] = toupper(buf[i]); // 来自 <ctype.h>
		}
		write(cfd, buf, len); // write函数也源自于 arpa net
	}

	// close(sfd); // 1次连接
	// close(cfd); // 同上
	return 0;

}
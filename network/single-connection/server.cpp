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

int main(void){
	struct sockaddr_in serv_addr, clie_addr;
	int sfd, cfd;
	int len;
	socklen_t clie_addr_len;

	char buf[BUFSIZ]; // BUFSIZ， 这是一个系统宏，指定缓存的大小

	sfd = socket(AF_INET, SOCK_STREAM, 0);// man 7 ip 查看API接口

	bzero(&serv_addr, sizeof(serv_addr)); // 局部变量手动初试化为0，防止奇怪的事情发生 在 #<strings.h>
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // p87@LHPSP.pdf, 游双的Linux 高性能系统服务器编程
	serv_addr.sin_port = htons(SERV_PORT);

	bind(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	listen(sfd, 128); // 默认值

	printf("server ready! wait for connection...");
	clie_addr_len = sizeof(clie_addr); // c语言早期版本先声明后定义，我们保持这个传统

	// 在 监听一个socket, 在此阻塞
	cfd = accept(sfd, (struct sockaddr *)&clie_addr, &clie_addr_len);

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
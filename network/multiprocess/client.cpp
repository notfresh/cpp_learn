//
// Created by zxzx on 2021/1/11.
//
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6666

int main(){
	int sfd, len;
	struct sockaddr_in serv_addr;
	char buf[BUFSIZ];
	socklen_t serv_addr_len;
	int n;

	sfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);
	serv_addr.sin_port = htons(SERV_PORT);
	serv_addr_len = sizeof(serv_addr);

	connect(sfd, (struct sockaddr *)&serv_addr, serv_addr_len);
	while(true){
		fgets(buf, sizeof(buf), stdin);
		write(sfd, buf, strlen(buf)); // #include <unistd.h>， 把buffer里的内容写到 socket里面去，传递给网络
		n = read(sfd, buf, sizeof(buf));
		write(STDOUT_FILENO, buf, n); // 打印到终端
	}
	close(sfd);
	return 0;
}


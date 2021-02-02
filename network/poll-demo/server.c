#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <errno.h>
#include <ctype.h>

#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000
#define OPEN_MAX 1024

int main(int argc, char *argv[])
{
    int i, j, maxi, listenfd, connfd, sockfd;
    int nready;                                 /*接收poll返回值, 记录满足监听事件的fd个数*/
    ssize_t n;

    char buf[MAXLINE], str[INET_ADDRSTRLEN];
    socklen_t clilen;
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in cliaddr, servaddr;

	// step1: 构建监听socket类型
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	// step2: 设置监听端口和IP（监听网上的任何IP报，也即是对外提供服务，这些几乎都是固定的了
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

	// step3: 绑定 socket 和监听的IP与端口，socket是一个容器，可以存放数据，而监听配置是设置，两者需要结合起来
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	// step4: 开始监听？是的，这里会阻塞，第一次监听,这里和普通单点socket编程一样
    Listen(listenfd, 128);

    // step5: 把 主套接字 加入待监听数组
    client[0].fd = listenfd;                    /* 要监听的第一个文件描述符 存入client[0]*/
    client[0].events = POLLIN;                  /* listenfd监听普通读事件 */

    // step6: 初始化其他未使用的坑位
    for (i = 1; i < OPEN_MAX; i++)
        client[i].fd = -1;                      /* 用-1初始化client[]里剩下元素 0也是文件描述符,不能用 */

    maxi = 0;                                   /* client[]数组有效元素中最大元素下标 */

    // 因为是服务器，所以要一直工作，接受外部的连接
    for ( ; ; ) {
    	// step7: 监听全部注册的套接字，目前只有一个主套接字
        nready = poll(client, maxi+1, -1);      /* 阻塞监听是否有客户端链接请求 */

        // step7.1: 监听主套接字
        if (client[0].revents & POLLIN) {       /* listenfd有读事件就绪 */

            clilen = sizeof(cliaddr);
            connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);/* 接收客户端请求 Accept 不会阻塞 */
            printf("received from %s at PORT %d\n",
                    inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
                    ntohs(cliaddr.sin_port));

            for (i = 1; i < OPEN_MAX; i++)
                if (client[i].fd < 0) {
                    client[i].fd = connfd;      /* 找到client[]中空闲的位置,存放accept返回的connfd */
                    break;
                }

            if (i == OPEN_MAX)                  /* 达到了最大客户端数 */
                perr_exit("too many clients");

            client[i].events = POLLIN;          /* 设置刚刚返回的connfd,监控读事件 */
            if (i > maxi)
                maxi = i;                       /* 更新client[]中最大元素下标 */
            if (--nready <= 0)
                continue;                       /* 没有更多就绪事件时,继续回到poll阻塞 */
        }
		// step8: 监听其他连接的套接字
        for (i = 1; i <= maxi; i++) {           /* 前面的if没满足,说明没有listenfd满足. 检测client[] 看是那个connfd就绪 */
            if ((sockfd = client[i].fd) < 0)
                continue;

            if (client[i].revents & POLLIN) {

                if ((n = Read(sockfd, buf, MAXLINE)) < 0) {
                    /* connection reset by client */
                    if (errno == ECONNRESET) {  /* 收到RST标志 */
                        printf("client[%d] aborted connection\n", i);
                        Close(sockfd);
                        client[i].fd = -1;      /* poll中不监控该文件描述符,直接置为-1即可,不用像select中那样移除 */
                    } else
                        perr_exit("read error");

                } else if (n == 0) {            /* 说明客户端先关闭链接 */
                    printf("client[%d] closed connection\n", i);
                    Close(sockfd);
                    client[i].fd = -1;
                } else {
                    for (j = 0; j < n; j++)
                        buf[j] = toupper(buf[j]);
                    Writen(sockfd, buf, n);
                }
                if (--nready <= 0)
                    break;
            }
        }
    }
    return 0;
}


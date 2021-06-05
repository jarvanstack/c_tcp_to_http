#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 9000
//socket -> bind -> listen
int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket error\n");
        return -1;
    }
    struct sockaddr_in lst_addr;
    lst_addr.sin_family = AF_INET;
    lst_addr.sin_port = htons(PORT);
    lst_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = bind(sockfd, (struct sockaddr *) &lst_addr, len);
    if (ret < 0) {
        perror("bind error\n");
        return -1;
    }
    if (listen(sockfd, 5) < 0) {
        perror("listen error\n");
        return -1;
    }
    while (1) {
        struct sockaddr_in cli_addr;
        int newfd = accept(sockfd, (struct sockaddr *) &cli_addr, &len);
        if (newfd < 0) {
            perror("accept error\n");
            continue;
        }
        char buff[1024] = {0};
        int ret = recv(newfd, buff, 1023, 0);
        if (ret > 0) {
            printf("req:%s\n", buff);
        }
        char *rsp = "OK";
        memset(buff, 0x00, 1024);
        sprintf(buff, "%s\r\n%s%d\r\n%s\r\n\r\n%s%", "HTTP/1.1 200 OK", "Content-Length: ", strlen(rsp),
                "Content-Type:text/html:charset=UTF-8", rsp);
        printf("%s", buff);
        send(newfd, buff, strlen(buff), 0);
        close(newfd);
    }
}
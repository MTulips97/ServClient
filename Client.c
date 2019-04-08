#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 444

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sockfd = 0, vread;
    struct sockaddr_in servaddr;
    char *annyeong = "annyeong from client";
    char buff[1111] = {0};
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error..try again \n");
        return -1;
    }
    memset(&servaddr, '0', sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    
    //convet IPv4 AND IPv6 address from text to binary form
    if (inet_pton(AF_INET, "192.168.216.128", &servaddr.sin_addr) <=0)
    {
        printf("\n Heyy! Your address is invalid \n");
        return -1;
    }
    
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) <0)
    {
        printf("\n Your connection failed!!!! \n");
        return -1;
    }
    send(sockfd, annyeong , strlen(annyeong) , 0);
    printf("annyeong my bae\n");
    vread = read(sockfd , buff , 1111);
    printf("%s\n",buff);
    return 0;
}

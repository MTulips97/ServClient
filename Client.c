#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<string.h>
#define PORT 4444

int main()
{
     printf("this is a client program\n");
     
     struct sockaddr_in myaddr,clientaddr;
     int newsockid;
     int len;
     int sockid,client_add;
     sockid=socket(AF_INET,SOCK_STREAM,0);
     
     // Create Socket
	sockid = socket(AF_INET, SOCK_STREAM , 0);
	if(sockid < 0) {
		perror("Failed to create socket");
		exit(1);
	}
     
     memset(&myaddr,0,sizeof myaddr);
     
     myaddr.sin_port=htons(4444);
     myaddr.sin_family=AF_INET;
    
     if (inet_pton(AF_INET, "192.168.216.128", &myaddr.sin_addr) <=0)
    {
        printf("\n Heyy! Your address is invalid \n");
        exit (1);
    }
    
     len=sizeof myaddr;
      if(bind(sockid,(struct sockaddr*)&myaddr,sizeof (myaddr)))
      {
        perror("bind failed");
        exit (1);
      }
     int p=connect(sockid,(struct sockaddr*)&myaddr,len);
     if(p==-1)
     perror("connect");
     char msg[200];
     int i=0;
     char c;int l=0; char *buffer=(char *)(malloc(sizeof(char)*200)); int buffsize;
     while(i<10)
     {l=0;
                printf("Client: ");
                while((c=getchar())!='\n')
                {
            msg[l++]=c;
                }
                msg[l]='\0'; l++;
                send(sockid,msg,l,0);
                fflush(stdin);
                newsockid=accept(sockid,(struct sockaddr*)&clientaddr,&client_add);
                recv(newsockid,buffer,buffsize,0);
                   l=0;
                 fprintf(stdout, "server: %s", buffer);
                  printf("\n");
                i++;
     }
     close(sockid);
     return 0;
}

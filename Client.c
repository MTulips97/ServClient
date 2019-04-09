#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 5555

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sockfd;
    struct sockaddr_in servaddr;
    int MySock;
    char buff[1111] ;
    int rval;
    char Client_message[256];
	
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("\n Socket creation error..try again \n");
        exit (1);
    }
    memset(&servaddr, '0', sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    
    //convet IPv4 AND IPv6 address from text to binary form
    if (inet_pton(AF_INET, "192.168.216.128", &servaddr.sin_addr) <=0)
    {
        printf("\n Heyy! Your address is invalid \n");
        exit (1);
    }
    
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)))
    {
        printf("\n Your bind failed!!!! \n");
        exit (1);
    }
    
    listen(sockfd , 10);

	// Accept

	do{
		MySock = connect(sockfd , (struct sockaddr *) 0, 0);	
			 
	        Previous:
	 
		if(MySock == -1)
		{
			perror("connect failed");
		}
		else
		{

		memset(buff, 0, sizeof(buff));

		if((rval = recv(MySock, buff, sizeof(buff), 0)) < 0)
		{ perror("reading stream message failed");    }
		
		else if (rval == 0)
		{ printf("Ending connection");  }

		else 
  		{

        	 recv(MySock, buff, sizeof(buff), 1);
		 printf("From Server: %s", buff);
		 recv(MySock, buff, sizeof(buff), 0);
		 printf("%s",buff);
		 printf("\n");
		 
		//goto Previous; 
		
		scanf ("%[^\n]%*c", Client_message);
			 
                send(MySock,Client_message,strlen(Client_message),0);
		}
		
		close(MySock);
		}
	}while(1);

	return 0;

}

#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h> 
#define PORT 4444

int main( int argc, char *argv[] )

{
	// Variables 
	int sock ;
	struct sockaddr_in server;
	struct sockaddr_in address;
	int msock;
	char buff [1024];
	int rval;
	char client_message[256] ;

	// Create Socket
	sock = socket(AF_INET, SOCK_STREAM , 0);
	if(sock < 0) {
		perror("Failed to create socket");
		exit(1);
	}


	server.sin_family = AF_INET;
	server.sin_port =htons(PORT);
	
	//convert Ipv4 and Ipv6 add from text to binary form
	if (inet_pton(AF_INET, "192.168.216.128", &server.sin_addr) <=0)
        {
        printf("\n Heyy! Your address is invalid \n");
        return -1;
        }

	// Call Bind 
	if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
	{
		perror("Bind Failed");
		exit(1);
	}

	// Listen
	listen(sock , 10);

	// Accept

	do{
		msock = accept(sock , (struct sockaddr *) 0, 0);	
			 
	        Previous:
	 
		if(msock == -1)
		{
			perror("accept failed");
		}
		else
		{

		memset(buff, 0, sizeof(buff));

		if((rval = recv(msock, buff, sizeof(buff), 0)) < 0)
		{ perror("reading stream message failed");    }
		
		else if (rval == 0)
		{ printf("Ending connection");  }

		else 
  		{

        	 recv(msock, buff, sizeof(buff), 1);
		 printf("From Server: %s", buff);
		 recv(msock, buff, sizeof(buff), 0);
		 printf("%s",buff);
		 printf("\n");
		 
		//goto Previous; 
		
		scanf ("%[^\n]%*c", client_message);
			 
                send(msock,client_message,strlen(client_message),0);
		}
		
		close(msock);
		}
	}while(1);

	return 0;

}

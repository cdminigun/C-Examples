#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#define TARGET_PORT 20009
#define BUFFSIZE 90

int main(int argc, char *argv[])
{
    	int sockfd = 0;
    	char buffer[BUFFSIZE];
    	struct sockaddr_in serv_addr;

    	if(argc != 2)
    	{
            	printf("\n Usage: %s <ip of server> \n",argv[0]);
            	return -1;
        }

    	if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    	{
       		printf("\n Error : Could not create socket \n");
            	return -1;
    	}
      /* Initialize variables and zero out the structures*/
      	memset(&serv_addr, '0', sizeof(serv_addr));
      	memset(buffer, '0',sizeof(buffer));
      	serv_addr.sin_family = AF_INET;
      	serv_addr.sin_port = htons(TARGET_PORT);

      	/* Sets the server Address */
	if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    	{
            	printf("\n inet_pton error occured\n");
            	return -1;
        }
      	/* Connects to the server */
    	if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    	{
           	  printf("\n Error : Connect Failed \n");
           	  return -1;
        }
        sprintf(buffer, "%s","vog010 Christopher Doege \n");
        /* Sends data to the server */
        if(send(sockfd, buffer, BUFFSIZE, 0) <0)
        {
              printf("Send failed.");
		          return -1;
	      }
	 /* Receive the data previously sent */
	 if(recv(sockfd, buffer, BUFFSIZE, 0) < 0 )
	 {
		printf("Recv error.");

	 }
	 printf("%s", buffer);
    	 return 0;
}

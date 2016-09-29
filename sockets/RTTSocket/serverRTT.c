nclude <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>

#define TARGET_PORT 99999
#define BUFFSIZE 90

int main(int argc, char *argv[]){


	/* Declared variables. */
    	int listenfd = 0, connfd = 0, n=0, size;
    	struct sockaddr_in serv_addr;
    	char recvBuff[BUFFSIZE];

	/* Binds the UDP socket to the listenfd*/
    	if((listenfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
	    	printf("Socket Error");
		exit(-1);
    	}
	/*Zeros out the struct and buffer */
	memset(&serv_addr, '0', sizeof(serv_addr));
	/*Fills the serv_addr struct with information needed for binding */
    	serv_addr.sin_family = AF_INET;
    	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    	serv_addr.sin_port = htons(TARGET_PORT);
	/* Sets the port and interface for the server to listen on*/
    	if(bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) <0){
		close(listenfd);
		printf("An issue occured with bind, check the struct and inputs");
	      	exit(-1);
    	}
	/* Sets a maxium of 10 corruent connections */
    	listen(listenfd, 10);

	/* Continiously waits for input from the socket.*/
    	printf("Server starting...waiting for input.\n");
	while(1)
    	{
		/* Receives input from any client connection to this IP address
		 * (INADDRY_ANY is bound to all interfaces, 127.0.0.1 and any
		 * ip address on a NIC. Doesn't error out on bad input, however
		 * it doesn't print out bad inputs. */
		if(recvfrom(listenfd, recvBuff, BUFFSIZE , 0, (struct sockaddr*)&serv_addr,0) > 0){
			printf("%s", recvBuff);
		}
    	sleep(1);
    	}
}

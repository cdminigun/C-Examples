#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#define TARGET_PORT 22200
/* Define lossy 22201  ip is 66.25.178.199. */
#define BUFFSIZE 90

pthread_t tid;
struct sockaddr_in serv_addr;
int sockfd;
int packetsReceived;
void *recvFunc();
int totalTime;
int timeTaken;

/* Takes input from argv  */
int main(int argc, char *argv[])
{
	/* Declares variables */
    	int i, err;
	struct timespec curTime;
    	char serv_ip[BUFFSIZE];
	char sendBuf[BUFFSIZE];
	double packetPercentage = 0.00;
	double rttAvg = 0.00;
	struct sockaddr_in client_addr;
    	socklen_t server_len = sizeof(serv_addr);

	strcpy(serv_ip, argv[1]);

	/*  If there aren't enough inputs for argv, exit. */
    	if(argc != 2)
    	{
            	printf("\n Usage: %s <ip of server> \n",argv[0]);
            	return 1;
        }


	/* Fills out the server and client with family, port and ip address.  */
	serv_addr.sin_family = AF_INET;
    	serv_addr.sin_port = htons(TARGET_PORT);
    	serv_addr.sin_addr.s_addr = inet_addr(serv_ip);
    	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(0);
	client_addr.sin_addr.s_addr = htonl(INADDR_ANY);


	/* Creates a UDP socket. */
    	if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    	{
        	printf("An erorr occured with the creation of the socket.");
		exit(-1);
	}

	/* Binds the socket to the client's INADDR_ANY and selects a random port.*/
	if(bind(sockfd, (struct sockaddr*)&client_addr, sizeof(client_addr)) <0 ){
		close(sockfd);
		printf("An error occured with bind, check all inputs th client_addr");
		exit(-1);
	}

	err = pthread_create(&tid, NULL, recvFunc, NULL);
	if (err != 0)
		printf("\nCan't create thread::[%s]", strerror(err));
	for(i=0;i<1000000;i++){
		/* Sends the designated data to the IP Address designated by user input from ARGC/ARGV. */
		clock_gettime(CLOCK_MONOTONIC, &curTime);
		if(sendto(sockfd, &curTime, sizeof(curTime), 0,(struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0 ){
			printf("Error sending to serv_addr, check address and availability");
			exit(-1);
		}
	}
        sleep(5);
        rttAvg = ((double)timeTaken /1000)/(double)packetsReceived;
        packetPercentage = (double)packetsReceived/PACKETS_SENT;
        printf("Total Packets Received: %lf.5\n", packetPercentage*100);
        printf("The average RTT is %lf.5 ms", rttAvg);
	return 0;
}

void *recvFunc( ){
	struct timespec curTime, oldTime;
	packetsReceived = 0;
	while(1)
	{
		if(recvfrom(sockfd, oldTime, BUFFSIZE, 0, (struct sockaddr*)&serv_addr, 0)){
			clock_gettime(CLOCK_MONOTONIC, &curTime);
			timeTaken += (curTime.tv_sec - oldTime.tv_sec) * 1000000 + (curTime.tv_nsec - oldTime.tv_nsec) / 1000);
			packetsReceived++;
				
		}
	}
}

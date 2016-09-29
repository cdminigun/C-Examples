#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TARGET_PORT 22201
/* Team port is 22201 */
#define BUFFSIZE 1024
#define GROUP join_group.imr_multiaddr.s_addr
#define INTERFACE join_group.imr_interface.s_addr

/* Takes input from argv  */
int main(int argc, char *argv[])
{
	/* Declares variables */
  int i, err;
  int sockfd;
  char serv_ip[BUFFSIZE];
  char client_ip[BUFFSIZE];
	char broadcastMessage[BUFFSIZE];
  struct ip_mreq join_group;
  int x;
  int flag_on = 1;
	struct sockaddr_in client_addr, serv_retrn;
  socklen_t server_len = sizeof(join_group), client_len = sizeof(client_addr);

	/*  If there aren't enough inputs for argv, exit. */
  if(argc != 2)
  {
		printf("\n Usage: ./clientRTT <ip of server> \n");
		return 1;
	}
	strcpy(serv_ip, argv[1]);
	/* Fills out the server and client with family, port and ip address.  */
  join_group.imr_multiaddr.s_addr = inet_addr("239.10.5.1");
  join_group.imr_interface.s_addr = INADDR_ANY;
  client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(22201);
	client_addr.sin_addr.s_addr = htonl(INADDR_ANY);


	/* Creates a UDP socket. */
  if((sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
  {
		printf("An erorr occured with the creation of the socket.");
		exit(-1);
	}
  if((setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &flag_on, sizeof(flag_on))) < 0 ){//set up to where multipe binds are applicable
   perror("setsockopt() failed");
   exit(-1);
  }
	/* Binds the socket to the client's INADDR_ANY and selects a random port.*/
	if(bind(sockfd, (struct sockaddr*)&client_addr, client_len) <0 ){
	  close(sockfd);
	  printf("An error occured with bind, check all inputs th client_addr");
		exit(-1);
	}
  printf("Start of data received\n");
  /* join the specified multicast group */
  if(setsockopt(sockfd,IPPROTO_IP,IP_ADD_MEMBERSHIP, (void *)&join_group, server_len) < 0){
    printf("Group joined failed with error %d\n",errno);
    perror("");
    exit(-1);
  }
  while(1)
  {
    int addrlen = sizeof(serv_retrn);
		printf("stuff");
    x = recvfrom(sockfd, &broadcastMessage, BUFFSIZE, 0, (struct sockaddr*)&serv_retrn, &addrlen);
    if(x < 0) {
      printf("Not received.");
      exit(-1);
    }
    printf("%s\n", broadcastMessage);
  }
	return 0;
}

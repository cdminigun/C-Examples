#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Used for Memset
#include <unistd.h>

#define TARGET_PORT 22201
#define BUFFSIZE 1024

int main(int argc, char *argv[])
{

    /* Declared variables. */
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;
    char sendBuff[BUFFSIZE];
    int addresslength;
    int ttl = 32;
    int i = 1;
    if(argc != 2)
    {
        printf("Requires group number. Standard invocation: ./multicastProj2a {group number}");
        exit(-1);
    }
    int group_number = 1;
    /* Binds the UDP socket to the listenfd*/
    if((listenfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Socket Error");
    		exit(-1);
    }

    if(setsockopt(listenfd, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl)) <0)
    {
        printf("An error occured with setsockopt");
    }

    /* Assign neccessary struct params */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(TARGET_PORT);
    /* Continiously waits for input from the socket.*/
    printf("Server starting... waiting for connections.\n");
    while(1)
    {
        addresslength = sizeof(serv_addr);
        sprintf(sendBuff, "This is message %d from the group %d beacon.\n", i, group_number);
        /* Sends data Multicast data
        * (INADDRY_ANY is bound to all interfaces, 127.0.0.1 and any
        * ip address on a NIC. Doesn't error out on bad input, however */
        sendto(listenfd, (char *)sendBuff, sizeof(sendBuff) , 0, (struct sockaddr*)&serv_addr, addresslength);
        printf("%s", sendBuff);
        i++;
        sleep(1);
    }
}

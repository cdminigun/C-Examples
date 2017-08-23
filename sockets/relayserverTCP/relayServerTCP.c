#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#define TARGET_PORT 20009
#define BUFFSIZE 90

int main(int argc, char *argv[])
{
    	int listenfd = 0, connfd = 0;
    	struct sockaddr_in serv_addr;
	    pid_t pid;
   	  char buffer[BUFFSIZE];

    	listenfd = socket(AF_INET, SOCK_STREAM, 0);
    	memset(&serv_addr, '0', sizeof(serv_addr));
    	memset(buffer, '0', sizeof(buffer));

    	serv_addr.sin_family = AF_INET;
    	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    	serv_addr.sin_port = htons(TARGET_PORT);

    	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

      /* Sets a Queue of 10 */
    	listen(listenfd, 10);

    	while(1)
    	{
            	/* Accepts an incoming connection and sends the same informatin back */
        	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
   		if(connfd > 0 ){
			if((pid = fork())){
				if(pid == 0){
                        close(listenfd);
                        close(connfd);
                        break;
                }else{
					close(listenfd);
					recv(connfd, buffer, BUFFSIZE, 0);
   					send(connfd, buffer, BUFFSIZE, 0);
    	                    		printf("%s", buffer);
					exit(0);
				}
			}
		}
		close(connfd);
        exit(0);
      }
}

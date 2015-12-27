#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]){
	int fd1, fd2, fd3, n1, n2, n3, arg3_flag;
	if(argc < 2)
	{
	 		printf("Invalid call. Usage: ./kit <file1> <file2> [file3].");
			return -1;
		}
        fd1 = open(argv[1], O_RDONLY);
       	if(fd1<0){
			perror(argv[2]);
	 	}
	fd2 = open(argv[2], O_RDONLY);
	if(fd2<0)
	{
			close(fd1);
			perror(argv[2]);
		}
	if(argc > 2)
	{
			arg3_flag = 1;
			fd3 = open(argv[3], O_WRONLY, O_CREAT);
			if(fd3<0)
			{
						close(fd1);
						close(fd2);
						close(fd3);
						perror(argv[3]);
					}
		}

}

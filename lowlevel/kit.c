#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]){
	int fd1, fd2, fd3, n, arg3_flag, f1_dash_flag=0, f2_dash_flag=0;
	char buf[BUFSIZE];
	if(argc < 3 || argc > 4)
	{
		if (write(1, "Error. Usage: ./kit <file1> <file2> [file3]\n", 45) != 45) {
        		write(2, "There was an error writing to standard out on line 14\n", 44);
       	 		return -1;
    		}
		return -1;
	}
	if(strcmp(argv[1], "-")==0)
		f1_dash_flag = 1;
	if(strcmp(argv[2], "-")==0)
		f2_dash_flag = 1;
	if(f1_dash_flag == 1 && f2_dash_flag == 1){
		if (write(1, "Error. Both files cannot be from stdin.\n", 41) != 41) {
                         write(2, "There was an error writing to standard out on line 25\n", 44);
                         return -1;
                 }
                 return -1;
	}
	if(f1_dash_flag == 0){
		fd1 = open(argv[1], O_RDONLY);
       		if(fd1<0){
			close(fd1);
			perror(argv[1]);
			return -1;
 		}
	}
	if(f2_dash_flag ==0){
		fd2 = open(argv[2], O_RDONLY);
		if(fd2<0)
		{
			close(fd1);
			close(fd2);
			perror(argv[2]);
			return -1;
		}
	}
	if(argc == 4)
	{
		arg3_flag = 1;
		fd3 = open(argv[3], O_WRONLY|O_CREAT, 0750);
		if(fd3<0)
		{
			close(fd1);
			close(fd2);
			close(fd3);
			perror(argv[3]);
			return -1;
		}
	}
	if(f1_dash_flag == 0){
		while((n= read(fd1, buf, BUFSIZE)) > 0)
		{
			if(arg3_flag ==0)
			{
				if(write(STDOUT_FILENO, buf, n) != n)
				{
					close(fd1);
					close(fd2);
					perror("Write error at line 68.");
				}
			}
			else{
				if(write(fd3, buf, n) != n)
				{
					close(fd1);
					close(fd2);
					close(fd3);
					perror("Write error at line 69.");
				}
			}
		}
		if(n<0){
			close(fd1);
			close(fd2);
			if(arg3_flag ==1)
				close(fd3);
			perror("read error at line 66");
		}
	}
	else {
		while((n = read(STDIN_FILENO, buf, BUFSIZE))> 0)
		{
			if(arg3_flag == 0 )
			{
				if(write(STDOUT_FILENO, buf, n) !=n)
				{
					close(fd1);
					close(fd2);
					perror("Write error occured at line.");
				}
			}
			else
			{
				if(write(fd3, buf, n) !=n)
				{
					close(fd1);
					close(fd2);
					close(fd3);
					perror("Write error occured at line.");
				}
			}
		}
	}
	if(f2_dash_flag == 0){
		while((n = read(fd2, buf, BUFSIZE)) > 0)
		{
			if(arg3_flag ==0)
			{
				if(write(STDOUT_FILENO, buf, n) !=n)
				{
					close(fd1);
					close(fd2);
					perror("Write error at line 82.");
				}
			}
			else
			{
				if(write(fd3, buf, n) !=n)
				{
					close(fd1);
					close(fd2);
					close(fd3);
					perror("Write error at line.");
				}
			}
		}
		if(n<0)
		{
			close(fd1);
			close(fd2);
			if(arg3_flag ==1)
				close(fd3);
			perror("Read error at line 80.");
		}
	}
	else {
		while((n = read(STDIN_FILENO, buf, BUFSIZE))>0)
		{
			if(arg3_flag == 0)
			{
				if(write(STDOUT_FILENO, buf, n) !=n)
				{
					close(fd1);
					close(fd2);
					perror("Write error occured at line.");
				}
			}
			else
			{
				if(write(fd3, buf, n) !=n)
				{
					close(fd1);
					close(fd2);
					close(fd3);
					perror("Write error at line.");
				}
			}
		}
		if(n<0)
		{
			close(fd1);
			close(fd2);
			if(arg3_flag == 1)
				close(fd3);
			perror("Read error at line.");
		}
	}
	close(fd1);
	close(fd2);
	if(arg3_flag == 1)
		close(fd3);
	return 0;
}

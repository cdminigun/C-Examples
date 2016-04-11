#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define PROCESS_NUM 20

int main(){
	int i,n, j, num;
	int fd[PROCESS_NUM][2];
	int child_process = 0;
	pid_t pid;

	for(i=0;i<PROCESS_NUM;i++){
		if(pipe(fd[i]) < 0)
			perror("Pipe error.");
	}
	while(child_process < PROCESS_NUM){
		if((pid = fork())<0)
			perror("Forking error.");
		if(pid==0)
			break;
		child_process++;
	}
	if(pid==0){
		for(i=0;i<PROCESS_NUM;i++){
			if(i==child_process)
				close(fd[i][1]);
			else
				close(fd[i][0]);
		}
		srand(71917133*child_process);
		for (n=0; n < 11; n++) {
			do{
				num = rand();
				j = num%9;
			}
			while(child_process == j);
			char output[1024];
                        sprintf(output, "process%d", child_process);
                        if(write(fd[j][1],output,10)!=10)
                        	perror("Write error.");
		}
		for(i=0;i<PROCESS_NUM;i++){
			if(i != child_process)
				close(fd[i][1]);
		}
		char buf[1024];
		while((n=read(fd[child_process][0], &buf,10))!=0){

			if(n<0){
				perror("read error.");
			}
			printf("process%d has received a message from %s \n"
				, child_process, buf);

		}
	}
	close(fd[child_process][0]);
	exit(0);
	return 0;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(){
	struct timeval t1, t2;
	int i;
	for(i=0;i<10;i++){
		gettimeofday(&t1, NULL);
		sleep(1);
		gettimeofday(&t2, NULL);
		printf("%ld\n", t2.tv_usec - t1.tv_usec);
	}

}

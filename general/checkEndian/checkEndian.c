#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	unsigned long x;
	x =  htonl(1);
	printf("%lu\n", x);
	if (x==1){
		printf("You're using Big Endian format.");
	}
        else {
		printf("You're using Little Endian format.");
	}
	x = ntohl(x);
	printf("%lu\n", x);

}

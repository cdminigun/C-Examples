#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, i;
	int mod;
	for(i=0;i<100;i++)
	{
		mod = rand() % i;
	}
	x = mod;
	printf("Your number is: %d", x);

}

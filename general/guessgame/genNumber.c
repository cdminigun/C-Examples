#include <stdio.h>
#include <stdlib.h>
#include "random.h"


int main()
{
	int x, i;
	Randomize();
	for(i=1;i<100;i++){
		x = RandomInteger(1,i);
	}
	printf("Your random number is: %d", x);
}

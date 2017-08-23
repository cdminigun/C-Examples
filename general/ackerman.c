#include <stdio.h>
#include <stdlib.h>



long long naive_ackermann(long long m, long long n);

int main()
{
	long long i, j;
	for(i=0; i<6;i++)
	{
		for(j=0;j<6;j++){
			printf("%lld\n", naive_ackermann(i,j));
		}
	}
}



long long naive_ackermann(long long m, long long n) {
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return naive_ackermann(m - 1, 1);
    else
        return naive_ackermann(m - 1, naive_ackermann(m, n - 1));
}

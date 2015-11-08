#include "stdio.h"

int main(int argc, char const *argv[])
{
	long long unsigned int i=0, j=1, k=1, sum=0, temp=0;

	for(;k < 4000000; k = i + j)
	{
		//temp = k;
		i = j;
		j = k;

		if(k % 2 == 0)
		{
			sum += k;
		}

		printf("%llu\n", sum);

	}

	return 0;
}
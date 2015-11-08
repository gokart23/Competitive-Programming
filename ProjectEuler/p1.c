#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i=0, sum1=0, sum2=0, sum3=0;
	
	for (i = 0; i < 1000; i += 3)
	{
		sum1 += i;		
	}

	for (i = 0; i < 1000; i += 5)
	{
		sum2 += i;		
	}

	for (i = 0; i < 1000; i += 15)
	{
		sum3 += i;		
	}

	printf("%d\n", sum1 + sum2 - sum3);

	return 0;
}
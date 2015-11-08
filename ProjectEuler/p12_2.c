#include "stdio.h"

int main(int argc, char const *argv[])
{
	unsigned int i = 1, factors = 0;
	unsigned long triangleNumber = 7000;	

	while(factors < 500)
	{
		switch(triangleNumber)
		{
			case 6000: printf("6000\n");
			break;
			case 7000:printf("7000\n");
			break;
			case 8000:printf("8000\n");
			break;
			case 9000:printf("9000\n");
			break;
			case 10000:printf("10000\n");
			break;

		}
		triangleNumber++;
		factors = 0;
		unsigned long long int num = ((triangleNumber * (triangleNumber+ 1))/2);
		for(i = 1; i < num ; i++)
		{
			if(num % i == 0)
			{
				factors++;
			}
		}
		factors++;
	}

	printf("%llu (%lu) : %u\n", (unsigned long long int)(triangleNumber * (triangleNumber + 1))/2, triangleNumber, factors);

	return 0;
}
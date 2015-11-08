#include "stdio.h"
#include "stdlib.h"
#include "math.h"

//Uses Sieve of Eratosthenes

unsigned long int * getPrimesBySieveOfEratosthenes(unsigned long int limit, int *sizeOfPrimes);

int main(int argc, char const *argv[])
{
	
	unsigned int factors = 1, triangleNumber = 7000;
	unsigned long int j = 2;
	
	do
	{
		triangleNumber++;
		factors = 1;
		switch(triangleNumber)
		{
			case 8000: printf("8000\n");
			break;
			case 9000:printf("9000\n");
			break;
			case 10000:printf("10000\n");
			break;
			case 11000:printf("11000\n");
			break;
			case 12000:printf("12000\n");
			break;
			case 13000:printf("13000\n");
			break;
			case 14000:printf("14000\n");
			break;

		}

		int size = 0, i=0;
		unsigned long int num = (triangleNumber * (triangleNumber + 1))/2;
		unsigned long int temp = num;

		for(j = 2; temp%j == 0;)
		{
			temp /= 2;
		}

		j = 3;
		while(j != num)
		{
			if(num % j == 0)
			{
				num /= j;
			}
			else
			{
				j += 2;
			}
		}

		unsigned long int *primes = getPrimesBySieveOfEratosthenes((unsigned long int)j, &size);
		unsigned int *expVector = (unsigned int*)calloc(size, sizeof(unsigned int));
		for(i=0; i < size; i++)
		{
			if(num % primes[i] == 0)
			{
				unsigned long int temp = primes[i] * primes[i];
				expVector[i]++;
				int flag = 1, j=0;
				for(j=2;flag;j++)
				{
					if(num % temp == 0)
					{
						expVector[i]++;
						temp *= primes[i];
					}
					else
					{
						flag = 0;
					}
				}
				
			}
		}
		
		for (i = 0; i < size; ++i)
		{
			//printf("%llu\n", num);
			if(expVector[i] != 0)
			{
				factors *= (expVector[i] + 1);
				//printf("%lu^%lu\n", primes[i], expVector[i]);
			}
		}

		free(primes);
		free(expVector);
		//printf("\n%u\n-------------------\n", factors);
	}while(factors < 500);

	printf("%lu : %u\n", (unsigned long int)(triangleNumber * (triangleNumber + 1))/2, factors);

	return 0;
}

unsigned long int* getPrimesBySieveOfEratosthenes(unsigned long int limit, int *sizeOfPrimes)
{
	unsigned long int *nums, *primes, i=0, index=0, k=0, maxI=0;

	nums = (unsigned long int*)malloc(limit * sizeof(unsigned long int));
	primes = (unsigned long int*)malloc(limit * sizeof(unsigned long int));

	for(i=0;(2*i+3) < limit; i++)
	{
		nums[i] = 2*i + 3;
	}

	maxI = i;

	for(i=0; i < limit; i++)
	{
		primes[i] = -1;
	}

	primes[index] = 2;
	index++;

	for(i=0; i < maxI; i++)
	{
		if(nums[i] == -1)
		{
			continue;
		}
		else
		{
			unsigned long int j = nums[i];

			primes[index] = j;
			index++;
			//printf("%lu\n", j);

			for(k = i; k < maxI; k += primes[index-1])
			{
			    //printf("%lu : %lu\n", primes[index-1], nums[k]);
				nums[k] = -1;
			}
		}
	}

	*sizeOfPrimes = index;
	unsigned long int *primesList = (unsigned long int*)malloc(index * sizeof(unsigned long int));

	for(i=0; i < index; i++)
	{
		primesList[i] = primes[i];		
	}

	free(nums);
	free(primes);
	
	return primesList;
}
#include "stdio.h"

#define LIMIT 2000000
#define PRIME_EST 200000

int main(int argc, char const *argv[])
{
	unsigned long int *nums, *primes, i=0, index=0, k=0, maxI=0;

	nums = (unsigned long int*)malloc(LIMIT * sizeof(unsigned long int));
	primes = (unsigned long int*)malloc(PRIME_EST * sizeof(unsigned long int));

	for(i=0;(2*i+3) < LIMIT; i++)
	{
		nums[i] = 2*i + 3;
	}

	maxI = i;

	for(i=0; i < PRIME_EST; i++)
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

	long long int sum=0;

	for(i=0; i < index; i++)
	{
		sum += primes[i];
	}

	printf("%llu\n", sum);

	return 0;
}

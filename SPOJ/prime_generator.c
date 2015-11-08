#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	int testcases=0;
	scanf("%d", &testcases);
	
	//printf("%d\n", testcases);
	while(testcases)
	{
		unsigned int start=0, end=0;
		scanf("%d %d", &start, &end);
		//printf("%d %d\n", start, end);
		
		unsigned long int *nums, *primes, i=0, index=0, k=0, maxI=0;
	
		nums = (unsigned long int*)malloc(end * sizeof(unsigned long int));
		primes = (unsigned long int*)malloc(end * sizeof(unsigned long int));
	
		for(i=0;(2*i+3) <= end; i++)
		{
			nums[i] = 2*i + 3;
		}
	
		maxI = i;
	
		for(i=0; i <= end; i++)
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
		
		for(i=0; i < index; i++)
		{
			if(primes[i] >= start && primes[i] <= end)
			{
				printf("%lu\n", primes[i]);
			}
		}
		printf("\n");		
		free(nums);
		free(primes);

		testcases--;
	}
	
	return 0;
}

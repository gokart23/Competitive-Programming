#include "stdio.h"
#include "stdlib.h"
//Logic behind this algo is dividing the grid horizontally into levels.
//Separate out the first layer as the starting point on this is defined
//Starting from the bottom-most layer, add the number of paths possible to the destination from that given point
//Do this for every layer considering only the layer below it for the number of paths
//It eventually assumes the structure of the loop written below

//For grid of 2x2, use N as 3!!
#define N 21

int main(int argc, char const *argv[])
{
	int i = 0, j = 0, k = 0;
	unsigned long long int *array = (unsigned long long int*) malloc(N * sizeof(unsigned long long int)), *temp = (unsigned long long int*) malloc(N * sizeof(unsigned long long int));

	for(i= 0; i < (N - 1); i++)
	{		
		if(!i)
		{
			for(j = 0; j < N; j++)
			{
				array[j] = 1;
				temp[j] = 1;
			}
		}
		else
		{
			for(j = 0; j < N; j++)
			{
				temp[j] = array[j];
			}

			for(j = 0; j < N; j++)
			{
				array[j] = 0;
				for(k=0; k <= j; k++)
				{
					array[j] += temp[k];
				}
			}
		}

		// for (k = 0; k < N; ++k)
		// {
		// 	printf("%ld ", array[k]);
		// }
		// printf("\n");
	}

	unsigned long long int sum=0;

	for(j=0; j < N; j++)
	{
		sum += array[j];
	}

	printf("%llu\n", sum);

	free(temp);
	free(array);

	return 0;
}
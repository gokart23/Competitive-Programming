#include <stdio.h>

void countingSort(int*, int, int, int*);
void printArray(int*, int);

int main()
{
	int numSize=0, i=0, range=0;

	printf("Enter number of elements\t:");
	scanf("%d", &numSize);

//	printf("Enter upper bound\t:");
	//scanf("%d", &range);

	int numbers[numSize];
	printf("Enter elements\n");

	for(i=0;i<numSize;i++)
	{
		scanf("%d", &numbers[i]);
		if(range < numbers[i])
			range=numbers[i];
	}

	int result[numSize];
	countingSort(numbers, numSize, range, result);

	printArray(result, numSize);

	return 0;
}

void printArray(int* result, int size)
{
	int i=0;

	printf("\n\n");
	for (i = 0; i < size; ++i)
	{
		printf("%d\n", result[i]);
	}
}

void countingSort(int *numbers, int size, int range, int* resultArray)
{
	int rangeArray[range], i=0;

	for (i = 0; i < range; ++i)
	{
		rangeArray[i] = 0;		
	}

	for (i = 0; i < size; ++i)
	{
		resultArray[i] = 0;
	}

	for (i = 0; i < size; ++i)
	{
		rangeArray[numbers[i]]++;
	}

	int temp=rangeArray[0];
	for (i = 0; i < (range-1); ++i)
	{	
		int temp2 = rangeArray[i+1];
		rangeArray[i+1] = temp;
		temp += temp2;
	}

	for(i=0;i<size;i++)
	{
		resultArray[rangeArray[numbers[i]]] = numbers[i];
		rangeArray[numbers[i]]--;		
	}	
}
#include <stdio.h>
#include <math.h>

void countingSort(int*, int, int, int*, int);
void radixSort(int*, int, int, int*);
void printArray(int*, int);
int getDigit(int, int);

int main()
{
	int numSize=0, i=0;

	printf("Enter number of elements\t:");
	scanf("%d", &numSize);

	int numbers[numSize],max=0;
	printf("Enter elements\n");

	for(i=0;i<numSize;i++)
	{
		scanf("%d", &numbers[i]);
		if(max < numbers[i])
			max = numbers[i];
	}

	int result[numSize];
	radixSort(numbers, numSize, max, result);

	//printArray(result, numSize);

	return 0;
}

int getDigit(int num, int pos)
{
	if(pos != -1)
	{
		num = num/(pow(10, pos--));
		return num%10;
	}
	else
	{
		int i=0;
		while(num != 0)
		{
			i++;
			num /= 10;
		}

		return i;
	}
}

void radixSort(int* numbers, int size, int max,int* result)
{
	int maxDigit = getDigit(max, -1), i=0;
	for (i = 0; i < maxDigit; ++i)
	{
		if(i%2==0)
		{
			if(i != 0)
			{
				int j = 0;
				for(;j<size;j++)
				{
					result[i] = numbers[i];
				}
			}
			countingSort(numbers, size, 10, result,i);
		}	
		else
		{
			int j = 0;
				for(;j<size;j++)
				{
					numbers[i] = result[i];
				}
			countingSort(result, size, 10, numbers,i);
		}
	}
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

void countingSort(int *numbers, int size, int range, int* resultArray, int digit)
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
		int temp = getDigit(numbers[i], digit);
		rangeArray[temp]++;
	}

	printArray(rangeArray, range);

	//int temp=rangeArray[0];
	for (i = 0; i < (range-1); ++i)
	{	
		//int temp2 = rangeArray[i+1];
		rangeArray[i+1] += rangeArray[i];
		//temp += temp2;
	}

	printArray(rangeArray, range);

	for (i = 0; i < range; ++i)
	{
		rangeArray[i]--;
	}
	for(i=size-1;i>=0;i--)
	{
		printf("%d\n", getDigit(numbers[i], digit));
		resultArray[rangeArray[getDigit(numbers[i], digit)]] = numbers[i];
		rangeArray[getDigit(numbers[i], digit)]--;		
	}

	printArray(resultArray, size);
}
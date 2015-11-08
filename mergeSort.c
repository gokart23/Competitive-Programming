#include <stdio.h>

int* mergeSort(int*, int, int);
int* linearMerge(int*, int, int, int*, int, int);

int main(int argc, char const *argv[])
{
	int num=0, i=0;

	printf("Enter number of elements\t:");
	scanf("%d", &num);

	int numbers[num];
	printf("Enter elements:\n");

	for(i=0;i<num;i++)
	{
		scanf("%d", &numbers[i]);
	}

	int* result = mergeSort(numbers, 0, num);

	for(i=0;i<num;i++)
	{
		printf("%d\n", numbers[i]);
	}

	return 0;
}

int* linearMerge(int* arrayOne, int startOne, int endOne, int* arrayTwo, int startTwo, int endTwo)
{
	int p1=arrayOne[startOne], p2=arrayTwo[startTwo], i=0, result[(endOne-startOne) + (endTwo-startTwo) + 2];

	for(i=0;i<((endOne-startOne) + (endTwo-startTwo) + 2);i++)
	{
		if(p1 < p2)
		{
			result[i] = p1;
			startOne++;
			p1 = arrayOne[startOne];
		}
		else
		{
			result[i] = p2;
			startTwo++;
			p2 = arrayTwo[startTwo];
		}
	}

	if(startOne != endOne)
	{
		result[(endOne-startOne) + (endTwo-startTwo) + 2] = arrayOne[startOne];
	}
	else
	{
		result[(endOne-startOne) + (endTwo-startTwo) + 2] = arrayTwo[startTwo];
	}
}

int* mergeSort(int* numbers, int start, int end)
{
	if(start == (end-1))
	{
		return numbers;
	}
	else
	{
		if((end-start)%2 == 0)
		{
			return linearMerge(mergeSort(numbers, start, start + ((end-start)/2)), start, start+((end-start)/2), mergeSort(numbers, start + (end-start)/2, end), start+(end-start)/2, end);
		}
		else
		{
			int* temp = linearMerge(mergeSort(numbers, start, start + (end+start-1)/2), start, (end+start-1)/2, mergeSort(numbers, start + (end-start-1)/2, (end)), start + (end-start-1)/2, end);
			return (linearMerge(temp, start, (end-1), numbers, end, end+1));
		}
	}
}
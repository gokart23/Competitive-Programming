#include <stdio.h>

void selectionSort(int*, int);
void printArray(int*, int);

int main(int argc, char const *argv[])
{
	int num=0, i=0;

	printf("Enter number of elements to sort\t:");
	scanf("%d", &num);

	int numbers[num];
	printf("Enter numbers:\n");

	for(i=0;i<num;i++)
	{
		scanf("%d", &numbers[i]);
	}

	selectionSort(numbers, num);	

	return 0;
}

void printArray(int* numbers, int size)
{
	int i=0;

	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", numbers[i]);
	}
}

void selectionSort(int numbers[], int size)
{
	int j=0,i=0, i_min=0;

	for(j=0;j<size;j++)
	{
		for(i=j;i<size;i++)
		{
			if(numbers[i_min] > numbers[i])
				i_min = i;
		}

		int temp=0;
		temp = numbers[i_min];
		numbers[i_min] = numbers[j];
		numbers[j] = temp;

		printArray(numbers, size);
	}
}
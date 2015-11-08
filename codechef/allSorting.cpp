#include <bits/stdc++.h>

using namespace std;

int* bubbleSort(int *array, int size)
{
	int cpyArray[size];
	copy(begin(array), end(array), begin(cpyArray));
	for(int i = (size-1); i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(array[j] > array[j+1])
				swap(array[j], array[j+1]);
		}
	}
}

void printArray(int *array, int size)
{
	for(int i = 0; i < size; i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int array[] = {10, 4, 5, 2, 3, 7, 1, 8, 9, 6};
	cout<<"Org ";
	printArray(array, 10);
	printArray(bubbleSort(array, 10), 10);
	return 0;
}
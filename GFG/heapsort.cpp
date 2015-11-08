#include <bits/stdc++.h>

using namespace std;

void heapify(int *array, int size, int index)
{
	if(index >= size || index < 0)
		return;
	int largest=0;
	if((2*index+1)<size && array[index] > array[2*index+1])
		largest = 2*index+1;
	if((2*index+2)<size && array[index] > array[2*index+2])
		largest = 2*index+2;
	if(largest)
		{ swap(array[index], array[largest]); heapify(array, size, largest); }
}

void makeHeap(int *array, int size)
{
	for(int i = (size>>1); i>=0; i--)
		heapify(array, size, i);
}

int deleteElement(int *array, int size, int index)
{
	if(index >= size || index < 0)
		return size;
	swap(array[index], array[size-1]);
	heapify(array, size-1, index);
	return size-1;
}

void heapSort(int *array, int size)
{
	for(;size>0;size--)
		deleteElement(array, size, 0);
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int array[n];
	for (int i = 0; i < n; ++i)
		cin>>array[i];
	makeHeap(array, n);
	heapSort(array, n);
	for (int i = 0; i < n; ++i)
		cout<<array[i]<<" ";
	return 0;
}
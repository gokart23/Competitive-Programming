#include <bits/stdc++.h>

using namespace std;

void wiggleSort(int *array, int size)
{
	if(size == 1)
		return;
	if(size == 2 && array[0] > array[1])
		{ swap(array[0], array[1]); return; }
	for(int i = 0; i < (size); i+=2)
	{
		if(i > 0 && array[i] < array[i-1])
			swap(array[i], array[i-1]);
		if(i < size-1 && array[i] < array[i+1])
			swap(array[i], array[i+1]);
	}
}

int main(int argc, char const *argv[])
{
	int n=0; cin>>n;
	int array[n];
	for(int i = 0; i < n; i++)
		cin>>array[i];
	wiggleSort(array, n);
	for(int i = 0; i < n; i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
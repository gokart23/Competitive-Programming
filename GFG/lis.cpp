#include <bits/stdc++.h>

using namespace std;

int lisLength(int *array, int size)
{
	if(!array || !size)
		return -1;
	int maxSoFar[size]; memset(maxSoFar, 0, size*sizeof(int));
	maxSoFar[0] = 1;
	for(int i = 1; i < size; i++)
		for(int j = 0; j < i; j++)
			if(array[j] < array[i] && (maxSoFar[i]) < (maxSoFar[j]+1) )
				maxSoFar[i] = maxSoFar[j] + 1;	
	for(int i = 0; i < size; i++)
		maxSoFar[0] = max(maxSoFar[0], maxSoFar[i]);
	return maxSoFar[0];
}

int main(int argc, char const *argv[])
{
	int elem[] = {10 ,22, 9, 33, 21, 50, 41, 60, 80};
	cout<<lisLength(elem, 9);
	return 0;
}
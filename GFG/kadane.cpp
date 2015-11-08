#include <bits/stdc++.h>

using namespace std;

int largestSum(int *array, int size)
{
	int max_so_far=0, max_ending_here=0;

	for(int i = 0; i < size; i++)
	{
		max_ending_here = max(0, max_ending_here + array[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
}

int main(int argc, char const *argv[])
{
	int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<largestSum(array, 8);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int combine(int *array, int sIdx, int eIdx)
{
	if(sIdx >= eIdx)
		return INT_MIN;
	int mid = (sIdx+eIdx)>>1;
	int leftMax = INT_MIN, rightMax = INT_MIN, sum = 0;
	for(int i = mid; i >= sIdx; i--)
	{
		cout<<"lprev:"<<leftMax;
		sum += array[i];
		if(sum < leftMax)
			break;
		else
			leftMax = sum;
		cout<<" lcur:"<<leftMax<<endl;
	}	
	for(int i = (mid+1), sum = 0; i < eIdx; i++)
	{
		cout<<"rprev:"<<rightMax;
		sum += array[i];
		if(sum < rightMax)
			break;
		else
			rightMax = sum;
		cout<<" rcur:"<<rightMax<<endl;
	}
	sum = 0;
	if(leftMax != INT_MIN)
		sum += leftMax;
	if(rightMax != INT_MIN)
		sum += rightMax;
	return sum;
}

int maxSum(int *array, int sIdx, int eIdx)
{
	if(sIdx >= eIdx)
		return 0;
	if((eIdx-sIdx) == 1)
	{	 
		cout<<sIdx<<","<<eIdx<<": ";
		cout<<array[sIdx]<<endl;
		return array[sIdx]; 
	}
	int mid = (sIdx+eIdx)>>1;
	int leftMax = maxSum(array, sIdx, mid);
	int rightMax = maxSum(array, mid, eIdx);
	int crossMax = combine(array, sIdx, eIdx);
	cout<<sIdx<<","<<eIdx<<": ";
	cout<<"l:"<<leftMax<<" r:"<<rightMax<<" c:"<<crossMax<<" max:"<<max(leftMax, max(rightMax, crossMax))<<endl;
	return max(leftMax, max(rightMax, crossMax));
}

int main(int argc, char const *argv[])
{
	int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	// int array[] = {5, -2, 4};
	cout<<maxSum(array, 0, 16);
	return 0;
}
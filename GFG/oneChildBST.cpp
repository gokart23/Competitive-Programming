#include <bits/stdc++.h>

using namespace std;

bool isOneChild(int *preorder, int size, int pIdx, int max, int min)
{
	if(!preorder || !size)
		return false;
	if(pIdx >= size)
		return true;
	if(preorder[pIdx] < max && preorder[pIdx] > min)
	{
		return (isOneChild(preorder, size, pIdx+1, preorder[pIdx], min) || isOneChild(preorder, size, pIdx+1, max, preorder[pIdx]));
	}
	else
		return false;
}

bool isOneChildTwo(int *preorder, int size)
{
	if(!preorder || !size)
		return false;
	for(int i = 0; i < size-1; i++)
	{
		if((preorder[i+1]-preorder[i])*(preorder[size-1]-preorder[i]) < 0)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int array[] = {20, 10, 11, 13, 12};
	cout<<isOneChild(array, 5, 0, INT_MAX, INT_MIN)<<endl;
	cout<<isOneChildTwo(array, 5)<<endl;

	return 0;
}
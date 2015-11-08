#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int mergeCombine(vector<int>& array, int sIdx, int eIdx)
{
	int mid = sIdx + (eIdx - sIdx)/2;
	int inversions = 0, curOne = sIdx, curTwo = mid, count = 0;
	vector<int> tempArray(eIdx - sIdx, 0);

	while(curOne < mid && curTwo < eIdx)
	{
		if(array[curOne] < array[curTwo])
			tempArray[count++] = array[curOne++];
		else
		{
			inversions += (mid - curOne);
			tempArray[count++] = array[curTwo++];
		}
	}
	while(curOne < mid)
		tempArray[count++] = array[curOne++];
	while(curTwo < mid)
		tempArray[count++] = array[curTwo++];
	for(int i = 0; i < count; i++)
		array[sIdx + i] = tempArray[i];
	return inversions;
}

int mergeCount(vector<int>& array, int sIdx, int eIdx)
{
	if(sIdx >= eIdx)
		return 0;
	if((eIdx - sIdx) == 1)
		return 0;
	int mid = sIdx + (eIdx - sIdx)/2;
	int lMerge = mergeCount(array, sIdx, mid);
	int rMerge = mergeCount(array, mid, eIdx);
	int combine = mergeCombine(array, sIdx, eIdx);

	return lMerge + rMerge + combine;
}

int countInv(vector<int>& array)
{
	if(!array.size())
		return 0;
	return mergeCount(array, 0, array.size());
}

int main()
{
	int temp;
	vector<int> array;
	while( cin>>temp && temp != -1)
		array.push_back(temp);
	cout<<countInv(array)<<endl;
}
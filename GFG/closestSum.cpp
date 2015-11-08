#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>

using namespace std;

int closestSum(vector<int>& array, int x)
{
	if(!array.size())
		return 0;
	sort(array.begin(), array.end());
	int leftIdx=0, rightIdx=array.size()-1, diff=INT_MAX, closeSum=0;
	while(leftIdx < rightIdx)
	{
		int sum = array[leftIdx] + array[rightIdx];
		if(abs(x-sum) < diff)
			{ closeSum = sum; diff =abs(x-sum); }
		else if(sum < x)
			leftIdx++;
		else
			rightIdx--;
	}
	return closeSum;
}

int main()
{
	vector<int> array;
	int temp;
	while( cin>>temp && temp != -1 )
		array.push_back(temp);
	cin>>temp;
	cout<<closestSum(array, temp)<<endl;
	return 0;
}
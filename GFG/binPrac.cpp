#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int>& array, int key)
{
	if(!array.size())
		return -1;
	int lIdx = 0, rIdx = array.size(), mid;

	while(lIdx <= rIdx)
	{
		int mid = lIdx + (rIdx - lIdx)/2;
		if(array[mid] == key)
			return mid;
		else if(array[mid] < key)
			lIdx = mid+1;
		else
			rIdx = mid-1;
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> array;
	int temp;
	while(cin>>temp && temp != -1)
		array.push_back(temp);
	sort(array.begin(), array.end());
	cin>>temp;
	cout<<binSearch(array, temp);	
	return 0;
}
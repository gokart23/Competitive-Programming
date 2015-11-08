#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(vector<int>& array, int key)
{
	int l=0, r=(array.size()-1), mid=0;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(array[mid] == key)
			return mid;
		else if(array[mid] < key)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

int floorSearch(vector<int>& array, int key)
{
	int l=0, r=array.size()-1, mid;
	if(array[l] > key)
		return -1;
	while(l <= r)
	{
		if(key >= array[r])
			return r;		
		if(key < array[l])
			return -1;
		mid = (l+r)>>1;
		if(array[mid] == key)
			return mid;
		else if(array[mid] < key)
		{
			if((mid+1) <= r && array[mid+1] > key)
				return mid;
			else
				l = mid+1;
		}
		else
			r = mid - 1;
	}
}

int main()
{
	int array[] = {1, 2, 8, 10, 10, 12, 19};
	vector<int> a(array, array+7);
	// cout<<binSearch(a, 3)<<" "<<binSearch(a,4)<<" "<<binSearch(a, 1)<<" "<<binSearch(a, 10)<<endl;
	cout<<floorSearch(a, 0)<<" "<<a[floorSearch(a, 1)]<<" "<<a[floorSearch(a, 5)]<<" "<<a[floorSearch(a, 20)]<<endl;
}
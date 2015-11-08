#include <vector>
#include <iostream>

using namespace std;

void printAllSubsets(vector<int>& array, int setElems, int max)
{
	if(setElems >= max)
		return;
	for(int i = 0; i < array.size(); i++)
	{
		if(setElems&(1<<i))
			cout<<array[i]<<" ";
	}
	cout<<endl;
	setElems++;
	printAllSubsets(array, setElems, max);
}

int main(int argc, char const *argv[])
{
	int ar[] = {1, 2, 3};
	vector<int> array(ar, ar+sizeof(ar)/sizeof(ar[0]));
	printAllSubsets(array, 0, 1<<array.size());
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

void combine(int *array, int start, int end)
{
	int mid = (start+end)>>1;
	int curOne=start, curTwo=mid, curT=0;
	int *temp = new int[end-start];
	// cout<<"\ts:"<<start<<" e:"<<end<<"\n\t";
	for(int ctr = 0; ctr < (end-start) && (curOne < mid) && (curTwo < end); ctr++, curT++)
	{
		// cout<<"\t\tc1:"<<curOne<<" c2:"<<curTwo<<" a1:"<<array[curOne]<<" a2:"<<array[curTwo];
		if(array[curOne] < array[curTwo])
			temp[curT] = array[curOne++];
		else
			temp[curT] = array[curTwo++];
		// cout<<" t[cT]"<<temp[curT]<<endl;
	}
	while(curOne < mid)
		temp[curT++] = array[curOne++];
	while(curTwo < end)
		temp[curT++] = array[curTwo++];
	for(int ctr = 0; ctr < (end-start); ctr++)
		{array[ctr+start] = temp[ctr];}// cout<<temp[ctr]<<" ";}
	//cout<<endl;
}

void mergesort(int *array, int start, int end)
{
	// cout<<"in "<<start<<"-"<<end<<" mid "<<((end+start)>>1)<<endl;
	if(!array)
		return;
	if(start >= end || (end-start) == 1)
		return;
	mergesort(array, start, (start+end)>>1);
	mergesort(array, (start+end)>>1, end);
	combine(array, start, end);
}

int main(int argc, char const *argv[])
{
	int t=0;
	cin>>t;
	int array[t];
	for(int i = 0; i < t; i++)
		cin>>array[i];
	mergesort(array, 0, t);
	for(int i = 0; i < t; i ++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
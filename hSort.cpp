#include <bits/stdc++.h>

#define lint long long int
#define parent(i) (i-1)>>1
#define lChild(i) ((i<<1)+ 1)
#define rChild(i) ((i<<1) + 2)

using namespace std;

void buildHeap(vector<lint> &input, int n)
{
	if(!n)
		return;
	for (int i = (n-1)/2; i >= 0; i--)
	{
		cout<<i<<" "<<lChild(i)<<" "<<rChild(i)<<endl;
		if(lChild(i) < n && input[i] < input[lChild(i)])
			swap(input[i], input[lChild(i)]);
		if(rChild(i) < n && input[i] < input[rChild(i)])
			swap(input[i], input[rChild(i)]);
	}
	for(int i = 0; i < n; i++)
		cout<<input[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<lint> input(n);
	for(int i = 0; i < n; i++)
		cin>>input[i];
	buildHeap(input, n);
	for(int i = 0; i < n; i++)
		cout<<input[i]<<" ";
	return 0;
}
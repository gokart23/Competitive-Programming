#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
//Sorry, just LIS over here :p
int lis(vector<int>& array)
{
	int dp[array.size()], print[array.size()], maxIdx=0;
	for(int i = 0; i < array.size(); i++)
	{
		dp[i] = 1;
		print[i] = -1;
	}
	dp[0] = 1; print[0] = -1;
	for(int i = 1; i < array.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(array[j] < array[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				print[i] = j;
			}
		}
		if(dp[maxIdx] < dp[i])
			maxIdx = i;
	}
	int temp = maxIdx;
	cout<<"LIS: "<<dp[maxIdx]<<endl;
	while(maxIdx >= 0)
	{
		cout<<array[maxIdx]<<" ";
		maxIdx = print[maxIdx];
	}
	cout<<endl;
	return dp[temp];
}

int main()
{
	int input;
	vector<int> array;
	while(cin>>input && input != -1)
		array.push_back(input);
	lis(array);
	return 0;
}
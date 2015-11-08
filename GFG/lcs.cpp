#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <climits>

using namespace std;

int lcs(string strOne, string strTwo)
{
	int dp[strOne.size()+1][strTwo.size()+1];	
	stack<char> common;

	for(int i = 0; i < (strTwo.size() + 1); i++)
		dp[0][i] = 0;
	for(int j = 0; j < (strOne.size() + 1); j++)
		dp[j][0] = 0;

	for(int i = 1 ; i <= strOne.size(); i++)
	{
		for(int j = 1; j <= strTwo.size(); j++)
		{
			if(strOne[(i-1)] == strTwo[(j-1)])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	int i=strOne.size(), j=strTwo.size();
	while(i && j)
	{
		if(strOne[i-1] == strTwo[j-1])
		{
			common.push(strOne[i-1]);
			i--; j--;
		}
		else if(dp[i][j-1] > dp[i-1][j])
			j--;
		else
			i--;
	}
	while(!common.empty())
		{ cout<<common.top(); common.pop(); }
	cout<<endl;
	return dp[strOne.size()][strTwo.size()];
}

int kadane(vector<int>& array)
{
	int max_so_far=0, max_ending_here=0;
	for(int i = 0; i < array.size(); i++)
	{
		max_ending_here += array[i];
		if(max_ending_here < 0)
			max_ending_here = 0;
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
}

int main()
{
	string s1, s2;
	cin>>s1>>s2;
	cout<<lcs(s1, s2);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

int matrixChain(vector< pair<int, int> >& matrices)
{
	int dp[matrices.size()][matrices.size()];
	for(int i = 0; i < matrices.size(); i++)
		for(int j = 0; j < matrices.size(); j++)
			dp[i][j] = INT_MAX;
	for(int i = 0; i < matrices.size(); i++)
		dp[i][i] = 0;
	for(int length = 2; length <= matrices.size(); length++)
	{
		for(int i = 0; i <= (matrices.size() - length); i++)
		{
			int j = (i + length - 1);
			for(int k = i; k < j; k++)
				if(dp[i][k] + dp[k+1][j] + matrices[i].first*matrices[k].second*matrices[j].second < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k+1][j] + matrices[i].first*matrices[k].second*matrices[j].second;
		}
	}
	return dp[0][matrices.size()-1];
}

int main()
{
	//Parse input
	int t1, t2;
	vector< pair<int, int> > matrices;
	while((cin>>t1) && (t1!=-1) && (cin>>t2))
		matrices.push_back(make_pair(t1, t2));
	cout<<matrixChain(matrices);
	return 0;
}
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define ulint unsigned long long int
#define lint long long int
#define VI vector<int>
#define VLL vector<lint>
#define VB vector<bool>
#define VVLL vector< VLL >
#define ci(i) cin>>i
#define co(i) cout<<i<<endl
#define FOR(i,j,n) for(lint i=j;i<n;i++)
#define pb push_back
#define s(v) v.size()
#define S(i) scanf("%d",&i)
#define SL(i) scanf("%lld",&i)
#define PL(i) printf("%lld\n",i)
#define P(i) printf("%d\n",i)
#define MOD 1000000007
#define gc getchar_unlocked

int main()
{	_	
	string inp;
	cin>>inp;
	int dp[inp.length()][inp.length()];

	FOR(i, 0, inp.length())
		dp[i][i] = 0;

	FOR(length, 2, inp.length()+1)
	{
		FOR(i, 0, inp.length()-length+1)
		{
			lint j = i + length - 1;
			if(((inp[i] - '0' + inp[j] - '0') == 10) && length == 2)
				dp[i][j] = 2;
			else if((inp[i] - '0' + inp[j] - '0') == 10)
				dp[i][j] = dp[i+1][j-1] + 2;
			else
				dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
		}
	}

	cout<<(dp[0][inp.length() - 1]>0?dp[0][inp.length()-1]:0);

	return 0;
}
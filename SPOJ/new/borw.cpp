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
#define FORR(i,j,n) for(lint i=j;i>=n;i--)
#define pb push_back
#define s(v) v.size()
#define S(i) scanf("%d",&i)
#define SL(i) scanf("%lld",&i)
#define PL(i) printf("%lld\n",i)
#define P(i) printf("%d\n",i)
#define MOD 1000000007
#define gc getchar
#define MAX 205
#define INF 0x1fffffff

void scanint(lint &x)
{
    register lint c = gc();
    x = 0;
    lint neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

//Fast output for long long int
inline void Print_f (long long n)
{
    char buffer[sizeof(n) * 8 * 3 / 10 + 3];  // 3 digits per 10 bits + two extra and space for terminating zero.
    int index = sizeof(buffer)-1;
    int end = index;
    buffer[index--] = 0;
    do {
       buffer[index--] = (n % 10) + '0';
       n /= 10;
    } while(n);
    puts(&buffer[index+1]);
}

int main()
{
	lint n=0, vals[MAX];
	vector< vector< vector<lint> > > dp;
	vals[0] = -INF;
	scanint(n);
	while(n != -1)
	{
		if(n == 1)
			scanint(vals[1]),Print_f(0); 
		else
		{
			dp.resize(n+2);
			FOR(i, 1, n+1) scanint(vals[i]), dp[i].resize(n+2);
			vals[n+1] = INF;		
			FOR(j, 0, n)
			{
				dp[n][j].resize(n+2, -INF);
				FOR(k, 1, n)
				{
					if(vals[n] > vals[j] || vals[n] < vals[k])
						dp[n][j][k]=1;
					else
						dp[n][j][k]=0;
				}
				dp[n][j][n+1] = 1;
			}
			// FOR(i, 1, n) cout<<"-INF,"<<vals[i]<<":"<<vals[n]<<"-"<<dp[n][0][i]<<" "; cout<<dp[n][0][n+1];
			// FOR(i, 1, n) { cout<<endl; FOR(j, 1, n) cout<<vals[i]<<","<<vals[j]<<":"<<vals[n]<<"-"<<dp[n][i][j]<<" "; cout<<dp[n][i][n+1]; }
			for(lint i = n-1; i>1; i--)
			{
				FOR(j, 0, i)
				{
					dp[i][j].resize(n+2, -INF);
					FOR(k, 1, i)
					{
						// cout<<i<<","<<j<<","<<k<<endl;
						dp[i][j][k] = dp[i+1][j][k];
						if(vals[i] > vals[j]) dp[i][j][k] = max(dp[i][j][k], 1+dp[i+1][i][k]);
						if(vals[i] < vals[k]) dp[i][j][k] = max(dp[i][j][k], 1+dp[i+1][j][i]);
					}
					dp[i][j][n+1] = max(dp[i+1][j][n+1], 1+dp[i+1][j][i]);
					if(vals[i] > vals[j]) dp[i][j][n+1] = max(dp[i][j][n+1], 1+dp[i+1][i][n+1]);
				}
			}
			lint res = max(dp[2][0][n+1], max(1+dp[2][1][n+1], 1+dp[2][0][1]));
			Print_f(n-res);
		}
		scanint(n);
	}
	return 0;
}
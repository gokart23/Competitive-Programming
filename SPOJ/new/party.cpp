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
#define dbg(p) cout<<#p ":"<<p<<" "
#define dbgn(p) cout<<#p ":"<<p<<endl
#define MOD 1000000007
#define MAX1 103
#define MAX2 503
#define gc getchar

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
	lint n=0, b=0;
	lint p[MAX1], f[MAX2], dp[MAX1][MAX2], ct[MAX1][MAX2];	
	scanint(b), scanint(n);
	while(n || b)
	{
		FOR(i, 1, n+1) scanint(f[i]), scanint(p[i]);
		FOR(i, 0, n+1)
		{
			FOR(c, 0, b+1)
			{
				if(!i || !c)
					dp[i][c] = 0, ct[i][c] = 0;
				else if(f[i] <= c)
				{
					if(p[i]+dp[i-1][c-f[i]] > dp[i-1][c])
						dp[i][c] = p[i]+dp[i-1][c-f[i]], ct[i][c] = ct[i-1][c-f[i]]+f[i];
					else if (p[i]+dp[i-1][c-f[i]] == dp[i-1][c])
						dp[i][c] = dp[i-1][c], ct[i][c] = min(ct[i-1][c], ct[i-1][c-f[i]]+f[i]);
					else
						dp[i][c] = dp[i-1][c], ct[i][c] = ct[i-1][c];
					// dbg(dp[i][c]); dbgn(ct[i][c]);
				}
				else
					dp[i][c] = dp[i-1][c], ct[i][c] = ct[i-1][c];
			}
		}
		printf("%lld %lld\n",ct[n][b], dp[n][b]);
		scanint(b), scanint(n);
	}
	return 0;
}
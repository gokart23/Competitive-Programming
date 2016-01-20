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
#define MAX 102

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
	lint t=0, n=0, res=0, idx[MAX];	
	bool dp[MAX][MAX], vals[MAX][MAX];
	char tmp;
	scanint(t);
	while(t--)
	{	
		res=0;
		scanint(n);
		FOR(i, 0, n) 
		{
			FOR(j, 0, n) 
			{
				tmp=gc();
				if(tmp == '1')	vals[i][j] = true; else vals[i][j] = false;
				if(j == (i+1)%n) dp[i][i] = false, dp[i][j] = true;			
			}
			tmp=gc();
		}
		// FOR(i, 0, n) { cout<<endl; FOR(j, 0, n) cout<<vals[i][j]<<" "; }
		FOR(l, 2, n) FOR(i, 0, n)
		{
			dp[i][(i+l)%n] = false;
			FOR(j, 1, l) 
				if( (vals[i][(i+j)%n] || vals[(i+l)%n][(i+j)%n]) && dp[i][(i+j)%n] && dp[(i+j)%n][(i+l)%n] ) { dp[i][(i+l)%n] = true; break; }
		}		
		// FOR(i, 0, n) { cout<<endl; FOR(j, 0, n) cout<<dp[i][j]<<" "; }
		FOR(i, 0, n) FOR(j, 0, n)
			if(vals[i][j] && dp[i][j] && dp[j][i]) { idx[res++] = i; break; }
		Print_f(res);
		FOR(i, 0, res) Print_f(idx[i]+1);					
	}
	return 0;
}
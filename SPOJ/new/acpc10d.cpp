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
#define gc getchar
#define MAX (lint)(1e5+1)

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

const int x_dir[4] = {-1, -1, 0, -1}, y_dir[4] = {-1, 0, -1, 1}, dir[3]={3,4,3};
struct triple { lint t[3]; };

inline bool is_valid(int x, int y)
{
	if(x < 0 || y > 2 || y < 0)
		return false;	
	return true;
}

int main()
{
	lint n=0, t=1;
	vector<triple> graph;
	vector<triple> dp;
	scanint(n);
	while(n)
	{
		graph.resize(n), dp.resize(n);
		FOR(i, 0, n) FOR(j, 0, 3) scanint(graph[i].t[j]);
		dp[0].t[0] = -1, dp[0].t[1] = graph[0].t[1], dp[0].t[2] = graph[0].t[2] + graph[0].t[1];
		FOR(i, 1, n)
		{
			dp[i].t[0] = graph[i].t[0]+min((i==1)?3000000:dp[i-1].t[0], dp[i-1].t[1]);
			// cout<<i<<",0-"<<dp[i].t[0]<<endl;			
			FOR(j, 1, dir[0])
			{
				dp[i].t[j] = 1000005;
				lint st = (i==1 && j==1)?1:0;
				FOR(k, st, dir[j])
					if(is_valid(i+x_dir[k], j+y_dir[k]))
						{ dp[i].t[j] = min(dp[i].t[j], dp[i+x_dir[k]].t[j+y_dir[k]] + graph[i].t[j]); } // cout<<i+x_dir[k]<<":"<<j+y_dir[k]<<"-"<<dp[i+x_dir[k]].t[j+y_dir[k]]<<" "<<graph[i].t[j]<<"  "; }
				// cout<<i<<","<<j<<"-"<<dp[i].t[j]<<endl;
			}
		}
		printf("%lld. %lld\n", t, dp[n-1].t[1]);					
		t++, scanint(n);
	}
	return 0;
}
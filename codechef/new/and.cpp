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

#define BITS 32

int main()
{		
	vector<lint> bitCount(BITS, 0);
	lint n, inp;
	scanint(n);
	FOR(i, 0, n)
	{
		scanint(inp);
		FOR(j, 0, BITS)
		{
			if(inp&1)
				bitCount[j]++;
			inp = inp>>1;
		}
	}

	lint ans = 0, mul = 1, val = 1;
	FOR(i, 0, BITS)
	{
		if(bitCount[i] > 1)
		{
			mul = (bitCount[i] * (bitCount[i] - 1))>>1;
			ans += (mul*val);
		}
		val = val<<1;
	}
	printf("%lld", ans);
	return 0;
}
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
#define MAX (lint)(1e6+1)

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
//REF: http://codeforces.com/blog/entry/7262
//Can write own blog post detailing the method
int main()
{
	lint t=0, a=0, b=0, g=0, ctr=0, res=1, pfs[30];
	vector<bool> visited(MAX, false);
	VLL sp(MAX, 0), mod(MAX, 0);	
	sp[1]=1;
	for(lint i = 2; i < MAX; i+=2)
		sp[i]=2, visited[i]=true;
	for(lint i = 3; i < MAX; i+=2)
		if(!visited[i])
		{
			sp[i] = i;
			for(lint j = i; j*i < MAX; j+=2)
				if(!visited[j*i])
					visited[j*i]=true, sp[j*i]=i;	
		}
	// FOR(i, 1, 31) cout<<i<<": "<<sp[i]<<endl;
	scanint(t);
	while(t--)
	{
		ctr=0, res=1;
		scanint(a), scanint(b);
		g=__gcd(a,b);
		while(g != 1)
		{
			// cout<<"g:"<<g<<" sp[g]:"<<sp[g]<<endl;
			pfs[ctr++] = sp[g];
			mod[sp[g]]++;
			g /= sp[g];
		}
		FOR(i, 0, ctr)
			if(mod[pfs[i]])
				res *= (mod[pfs[i]]+1), mod[pfs[i]] = 0;
		Print_f(res);
	}
	return 0;
}
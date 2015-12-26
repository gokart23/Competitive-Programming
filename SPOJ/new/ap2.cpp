#include <bits/stdc++.h>
using namespace std;
#define lint long long int
#define FOR(i,j,n) for(lint i=j;i<n;i++)
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

int main()
{
	lint t=0, a=0, b=0, c=0, d=0, s=0, n=0;
	scanint(t);
	while(t--)
	{
		scanint(b), scanint(c), scanint(s);
		n = 2*s/(b+c);
		d = (c - b)/(n-5);
		a = (b - 2*d);
		printf("%lld\n", n);
		FOR(i, 0, n) { printf("%lld ", a); a+=d; }
		printf("\n");
	}
	return 0;
}
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
#define co(x,i) cout<<x<<" "<<i<<endl
#define FOR(i,j,n) for(lint i=j;i<n;i++)
#define pb push_back
#define s(v) v.size()
#define S(i) scanf("%d",&i)
#define SL(i) scanf("%lld",&i)
#define PL(i) printf("%lld\n",i)
#define P(i) printf("%d\n",i)
#define MOD 1000000007
#define gc getchar//_unlocked

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
	lint n=0;
	scanint(n);
	char *a = (char*)calloc(n, sizeof(char)), *b = (char*)calloc(n, sizeof(char));
	int *table = (int*)calloc(n, sizeof(int));

	if(n == 1)
	{
		PL(0);
		return 0;
	}

	FOR(i, 0, n)
		scanf("%c", &a[i]);
	FOR(i, 0, n)
		scanf("%c", &b[i]);
	
	table[0] = -1, table[1] = 0;
	lint pos = 2, cnd = 0;
	while(pos < n)
	{
		if(a[pos-1] == a[cnd])
			{ cnd++, table[pos] = cnd, pos++; }
		else if(cnd)
			{ cnd = table[cnd]; }
		else
			{ table[pos] = 0, pos++; }
	}

	lint max = 0, maxStart = 0, curBeg = 0, offset = 0;

	while( curBeg + offset < n )
	{
		if( a[offset] == b[offset + curBeg] )
			offset++;
		else
		{
			if(table[offset] > -1)
				{ offset = 0, curBeg = (curBeg + offset - table[offset]), offset = table[offset]; }
			else
				{ offset = 0, curBeg++; }
		}
		if(offset > max)
			{ max = offset; maxStart = curBeg; }
	}
	PL(maxStart), PL(max);
	return 0;
}
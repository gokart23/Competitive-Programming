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

#define MAX 3000

vector<bitset<MAX> > compute;
lint maxSoFar=0;

lint gcd(lint a, lint b)
{
    while(b)
    {
        if(a <= maxSoFar && b <= maxSoFar)
            return compute[a][b];
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main()
{_	
	lint t=0, n=0, maxSoFar=0;
    compute.reserve(MAX);
    FOR(i, 0, MAX)
    {
        FOR(j, 0, MAX)
        {
            if(i > j)
                compute[i][j] = compute[j][i];
            compute[i][j] = gcd(j, i)==1?1:0;
        }
        maxSoFar++;
    }

    //cin>>t;
	while(t--)
	{
		cin>>n;
		vector<lint> elements(n);
		FOR(i, 0, n)	cin>>elements[i];
		lint maxSizeSoFar=1, maxSizeCur=1,gcdCur=elements[0];
		FOR(i, 1, n)
		{
			lint t = gcd(max(elements[i], gcdCur), min(elements[i], gcdCur));
			
			if(t != 1)
			{
				gcdCur = elements[i];
				maxSizeCur=1;
			}
			else
			{
				maxSizeCur++;
				gcdCur = t;
			}
			maxSizeSoFar = max(maxSizeSoFar, maxSizeCur);
			cout<<i<<" elements[i]:"<<elements[i]<<" t:"<<t<<" gcdCur:"<<gcdCur<<" maxSizeCur:"<<maxSizeCur<<" maxSizeSoFar:"<<maxSizeSoFar<<endl;
		}
		cout<<(maxSizeSoFar==1?-1:maxSizeSoFar)<<endl;			
	}	
	return 0;
}
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
#define putchar putchar_unlocked

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

#define MAX_V 103
#define MAX_R 12

int main()
{
	bool flag = false;
	lint t, n, k, c=0;
	lint v[MAX_V], rs[MAX_R];
	scanint(t);
	while(t--)
	{		
		flag = false, c=0;
		scanint(n), scanint(k);
		FOR(i, 0, n)
		{
			scanint(v[i]);
			rs[i] = v[i] % (k+1);
			if (!rs[i]) c++;
		}

		if(c >= (n-1))
			printf("YES\n");
		else
		{
			FOR(r, 1, k+1)
			{
				c=0;
				FOR(i, 0, n)
				{
					rs[i] = (rs[i] + k) % (k+1);
					if (!rs[i]) c++;
				}
				if (c >= (n-1))
					{ flag = true; break; }
			}
			if (flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}	
	return 0;
}


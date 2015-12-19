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
#define MAX (lint)(1e5+1)
int main()
{	
	bitset<MAX> nums;
	vector<int> primes;
	nums[0]=1, nums[1]=1;
	FOR(i, 1, MAX)
	{
		if(!nums[i])
		{
			primes.push_back(i);
			for(lint j = i<<1; j < MAX; j+=i)
				nums[j] = 1;
		}
	}

	lint t=0, m=0, n=0;
	scanint(t);

	while(t--)
	{
		scanint(m), scanint(n);
		if(n < MAX)
		{
			FOR(i, m, n+1)
				if(!nums[i])
					Print_f(i);
		}
		else
		{
			vector<bool> range(n-m+1, 0);
			for(lint i = 0; i < primes.size(); i++)
			{
				lint lower = primes[i]*(m/primes[i]);				
				if(lower < m)
					lower += primes[i];
				for(lint j = lower; j <= n; j += primes[i])
					range[j-m] = 1;
			}
			FOR(i, 0, n-m+1)
				if(!range[i])
					Print_f(m+i);
		}
        putchar_unlocked('\n');
	}	
	
	return 0;
}
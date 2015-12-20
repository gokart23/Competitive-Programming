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
#define pc putchar_unlocked

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
	lint t=0, n=0, c=0;
	scanint(t);
	while(t--)
	{
		scanint(n), scanint(c);
		VLL stalls(n);
		FOR(i, 0, n) scanint(stalls[i]);
		sort(stalls.begin(), stalls.end());
		lint low=1, high=(stalls.back() - stalls.front()), mid=0;
		if(n == 2)
			Print_f(high);
		else
		{
			while((high-low) != 1)
			{
				assert(high != low);
				//Predicate: Can all cows be assigned to stalls, if the min dist b/n 2 cows is at least x?
				mid = low + (high-low)/2;
				lint c_sat=1, prev=stalls.front();
				for(lint i=0; i<n && c_sat<c; i++)
					if(stalls[i] - prev >= mid)
						{ c_sat++; prev = stalls[i]; }
				if(c_sat == c)
					low = mid;
				else
					high = mid;
			}
			Print_f(low);
		}
	}
	return 0;
}
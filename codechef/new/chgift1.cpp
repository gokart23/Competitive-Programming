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
#define MAX 12
int main()
{
	lint t, n, v[MAX], cs[2], ps[2];
	scanint(t);
	while(t--)	{
		scanint(n);
		FOR(i, 0, n) scanint(v[i]);
		ps[0]=v[0], ps[1]=v[0];
		FOR(i, 1, n) {
			cs[0]=(lint)1e15,cs[1]=(lint)-1e15;
			FOR(j, 0, 2) {
				cs[0]=min(cs[0], ps[j]*v[i]);
				cs[0]=min(cs[0], ps[j]+v[i]);
				cs[0]=min(cs[0], ps[j]-v[i]);
				cs[1]=max(cs[1], ps[j]*v[i]);
				cs[1]=max(cs[1], ps[j]+v[i]);
				cs[1]=max(cs[1], ps[j]-v[i]);
				// cout << v[i] << " j " << j << " 0-" << cs[0] << " 1-" << cs[1] << endl;
			}
			ps[0]=cs[0],ps[1]=cs[1];
		}
		printf("%lld\n", ps[0]);
		// Print_f(ps[0]);
	}	
	return 0;
}


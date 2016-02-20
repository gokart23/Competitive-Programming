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
#define FORR(i,j,n) for(lint i=j;i>=n;i--)
#define dbgn(p) cout<<#p ":"<<p<<endl;
#define dbg(p) cout<<#p ": "<<p<<" ";
#define pb push_back
#define s(v) v.size()
#define MOD 1000000007
#define INF 1e9
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
	lint n=0, res=0, tmp=0, l=0;
	vector<lint> vals;
	stack<lint> hist;
	scanint(n);
	while(n)
	{
		assert(hist.empty());
		res = 0, vals.clear(), vals.pb(-INF), hist.push(0);
		FOR(i, 1, n+1)
		{
			scanint(tmp), vals.pb(tmp);
			if(vals[hist.top()] <= tmp)
				hist.push(i);
			else
			{
				while(vals[hist.top()] > tmp)
				{
					l = hist.top(); hist.pop();
					res = max(res, vals[l]*(i-hist.top()-1));
					// dbg(l); dbg(i); dbg(hist.top()); dbg(vals[l]*(i-hist.top()-1)); dbg(res); dbgn(vals[l]);
				}
				hist.push(i);
			}
		}
		vals.pb(INF), tmp=n+1;
		while(hist.size() != 1)
		{
			l = hist.top(), hist.pop();
			res = max(res, vals[l]*(tmp-hist.top()-1));
			// dbg(l); dbg(tmp); dbg(hist.top()); dbg(vals[l]*(tmp-hist.top()-1)); dbg(res); dbgn(vals[l]);
		}
		hist.pop();
		Print_f(res);
		scanint(n);
	}
	return 0;
}
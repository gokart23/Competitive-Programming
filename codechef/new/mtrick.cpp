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
#define pb push_back
#define s(v) v.size()
#define S(i) scanf("%d",&i)
#define SL(i) scanf("%lld",&i)
#define PL(i) printf("%lld\n",i)
#define P(i) printf("%d\n",i)
#define MOD 1000000007
#define MAX 1010
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
    fputs(&buffer[index+1], stdout);
}

inline lint multiply(lint a, lint b, lint c){
	unsigned lint r=0;
	while (b) {
		if (b & 1)
			r += a;
		r %= c;
		b >>= 1, a = (a<<1)%c;
	}
	return r;
}

int main()
{
	lint t, n, a, b, c, cr, d, d1, d2, x, y;
	lint v[MAX];
	char s[MAX];
	scanint(t);
	while(t--)	{
		scanint(n);
		cr=0, d=1, d1=0, d2=(n-1), x=0, y=1;
		FOR(i, 0, n) scanint(v[i]);
		scanint(a), scanint(b), scanint(c);
		a %= c, b %= c;
		FOR(i, 0, n) scanf("%c", &s[i]);
		FOR(i, 0, n) {
			if (s[i] == 'A') {
				x = (x + a)%c;
			}
			else if (s[i] == 'M') {
				y = multiply(y, b, c);
				x = multiply(x, b, c);				
			}
			else {
				if (d == 1)
					d1 = cr, cr = d2;
				else
					d2 = cr, cr = d1;
				d = -d;
			}
			// cout << "cr " << cr << " v[cr] " << v[cr] << " add " << x << " mul " << y << " d1 " << d1 <<" d2 " << d2 << " d " << d << endl;
			Print_f( (multiply(v[cr], y, c) + x)%c );
			putchar(' ');
			cr += d;
		}
		putchar('\n');
	}
	return 0;
}
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

#define VPLL vector< pair<lint, lint> >

bool comp(pair<lint, lint> a, pair<lint, lint> b){
	return a.first < b.first;
}

lint ic (VPLL& c, VPLL& t, int l, int r){
	if ((l+1) >= r)	{ 
		// cout << l << " " << r << " " << 0 << endl;
		return 0; 
	} 
	else{
		int cn = 0, lp = l, rr = (l+r)/2, rp = rr, tp = l;
		int p = ic(c, t, l, rr);
		int q = ic(c, t, rr, r);

		while(lp < rr && rp < r) {
			if (c[lp].second <= c[rp].second)
				t[tp++] = c[lp++];
			else{
				cn += (rr - lp);
				t[tp++] = c[rp++];
			}
		}

		while(rp < r)
			t[tp++] = c[rp++];

		while(lp < rr) 
			t[tp++] = c[lp++];

		FOR(i, l, r) c[i] = t[i];
		// FOR(i, l, r) cout << i << "-" << c[i].second << " ";
		// cout <<endl;
		// cout << l << " " << r << " " << cn + p + q << endl;
		return cn + p + q;
	}
}

int main(){
	lint n=0, p, q;
	scanint(n);
	VPLL c(n);
	FOR(i, 0, n){
		scanint(p), scanint(q);
		c[i] = make_pair(p, q);
	}
	sort(c.begin(), c.end(), comp);	
	VPLL t(c);
	cout << ic(c, t, 0, n) << endl;	
	return 0;
}


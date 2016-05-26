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

int main()
{	
	lint n, t, cn, rs;
	scanint(n);
	VLL v(n, 0);
	vector<bool> cv(n,false);
	set<lint> c;
	FOR(i, 0, n)
	{	
		scanint(v[i]); c.insert(i);
	}
	for(int r_i = 31; r_i >= 0; r_i--)
	{	
		unsigned lint r = 1<<r_i;
		// cout << "round " << r_i << endl;
		cn=0;
		for (set<lint>::iterator i = c.begin(); i != c.end(); i++)
		{	
			// cout << "\t" << v[*i] << ":" << (v[*i] & r);
			if (v[*i] & r)
				cn++, cv[*i] = true;
			else
				cv[*i] = false;
			// cout << " " << cv[*i] << endl;
		}
		// cout << "cn " << cn << endl;
		
		if (cn > 1)
		{			
			for (set<lint>::iterator i = c.begin(); i != c.end();)
			{	
				// cout << v[*i] << "-" << cv[*i] << endl;
				if (cv[*i])
					cv[*i] = false, ++i;
				else
					c.erase(i++);
			}
			if (cn == 2)
			{
				t=0;
				for (set<lint>::iterator i = c.begin(); i != c.end(); i++)
				{
					if (!t)
						t++, rs=v[*i];
					else
						rs &= v[*i];					
					// cout << v[*i] << "," << rs << endl;
				}
				Print_f(rs);
				return 0;
			}
		}
		// cout << "set contents" << endl;
		// for (set<lint>::iterator i = c.begin(); i != c.end(); i++)
		// 	cout << v[*i] << " ";
		// cout << endl;
	}
	t = 0;
	for (set<lint>::iterator i = c.begin(); i != c.end(); i++)
	{
		if (!t)
			t++, rs=v[*i];
		else
			rs &= v[*i];
		// cout << rs << endl;
	}
	Print_f(rs);
	return 0;
}


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
#define gc getchar
#define putchar_unlocked putchar
#define getchar_unlocked getchar

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

//Fast Input for int
inline int fast_scan() {
    int n=0;
    int ch=getchar_unlocked();
    while( ch <48 ) {
        ch=getchar_unlocked();
    }
    while( ch >47 ) {
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    }
    return n;
}
//Fast output for int
inline void fast_print(int n) {
    char ch[15];
    int ind=0;
    if(n<0) {
        putchar_unlocked('-');
        n *= -1;
    }
    if(n == 0) {
        putchar_unlocked('0');
    }
    while(n > 0) {
        ch[ind] = n%10 + '0';
        n /= 10;
        ind++;
    }
    while(ind--) putchar_unlocked(ch[ind]);
    putchar_unlocked('\n');
}

//Fast input for long long int
inline long long Scan_f()
{
    int c;
    do
        c = fgetc(stdin);
    while ( (c < '0' || c > '9') && c != EOF );

    long long a = 0;
    while ( c >= '0' && c <= '9' )
    {
        a = a*10 + (c - '0');
        c = fgetc(stdin);
    }
    return a;
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

bool compare(pair<lint, lint> p1, pair<lint, lint> p2)
{
	if(p1.first <= p2.first)
		return true;
	return false;
}
#define MAX_COUNT 2001
int main()
{	
	lint t=0, n=0, new_l=-1, new_r=-1, cur_l=-1, cur_r=-1;
	scanint(t);
	
	while(t--)
	{
		lint t1=0, t2=0, bombs_required=0;
		scanint(n);
		vector< pair<lint, lint> > kingdoms(n);
        int count[MAX_COUNT];
        memset(count, -1, MAX_COUNT);

		FOR(i, 0, n)
		{
			scanint(t1), scanint(t2);
			kingdoms[i] = make_pair(t1, t2);
		}
		
		sort(kingdoms.begin(), kingdoms.end(), compare);
		cur_l=-1, cur_r=-1, new_l=kingdoms[0].first, new_r=kingdoms[0].second;		
		
		FOR(i, 0, n)
		{
			new_l=kingdoms[i].first, new_r=kingdoms[i].second;
			if( new_l > cur_r)
			{
				bombs_required++;
				cur_l = new_l, cur_r = new_r;
			// 	#ifdef DEBUG
			// 	cout<<"Changed overlap segment"<<endl;
			// 	#endif
			}
			else
			{
				if ( cur_l < new_l )
					cur_l = new_l;
				if ( new_r < cur_r )
					cur_r = new_r;
			}
			// #ifdef DEBUG
			// 	cout<<"Cur segment: "<<cur_l<<","<<cur_r<<endl;
			// #endif
		}
		Print_f(bombs_required);		
		// FOR(i, 0, n)
		// 	cout<<kingdoms[i].first<<" "<<kingdoms[i].second<<endl;

	}
	return 0;
}
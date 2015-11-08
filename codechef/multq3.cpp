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

lint n=0,q=0;

lint queryTree(vector<lint>& segTree, lint a, lint b, lint node, lint min, lint max)
{
    if(b < min || a > max)
		return 0;
	if(max == min)
		return segTree[node];	
	if(min >= a && max <= b)
		return segTree[node];
	return queryTree(segTree, a, b, 2*node+1, min, min+(max-min)/2) + queryTree(segTree, a, b, 2*node+2, min+1+(max-min)/2, max);	
}

void updateTree(vector<lint>& segTree, vector<lint>& vals, lint a, lint b, lint node, lint min, lint max)
{
    if(b < min || a > max)
		return;
	if(min == max)
    {
        //cout<<"node"<<node<<" min"<<min<<endl;
        vals[min] = (vals[min] + 1)%3;
        vals[min]==0?segTree[node]=1:segTree[node]=0;
        return;
    }
	updateTree(segTree, vals, a, b, 2*node+1, min, min+(max-min)/2);
	updateTree(segTree, vals, a, b, 2*node+2, min+1+(max-min)/2, max);
	segTree[node] = segTree[2*node+1] + segTree[2*node+2];
}

int main()
{	
	lint ch=0,a=0,b=0, tmp=0;
	scanint(n),scanint(q);
    tmp=ceil(log2(n));
	vector<lint> segTree(1<<(1+tmp), 1);
    vector<lint> vals(n, 0);
    
    for(lint i=(tmp-1);i>=0;i--)
    {
        for(lint j=(1<<i)-1;j<((1<<(i+1))-1);j++)
        { if(j>=n-1) break; segTree[j] = segTree[2*j+1] + segTree[2*j+2];}
    }
    
	while(q--)
	{
		scanint(ch),scanint(a),scanint(b);		
		if(ch)
			Print_f(queryTree(segTree, a, b, 0, 0, (n-1)));
		else
			updateTree(segTree, vals, a, b, 0, 0, (n-1));
	}	
	return 0;
}
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
#define MAX 1000
int main()
{
	lint n=0, top=0, vals[MAX];
	stack<lint> side_stack;
	scanint(n);
	while(n)
	{
		top=1; while(!side_stack.empty()) side_stack.pop();
		FOR(i, 0, n) scanint(vals[i]);
		FOR(i, 0, n)
		{
			for(;!side_stack.empty() && (side_stack.top() == top);top++, side_stack.pop());
			if(top == vals[i]) top++;
			else side_stack.push(vals[i]);
		}
		for(;!side_stack.empty() && (side_stack.top() == top);top++, side_stack.pop());
		
		if(!side_stack.empty()) printf("no\n");
		else printf("yes\n");
		
		scanint(n);
	}
	return 0;
}
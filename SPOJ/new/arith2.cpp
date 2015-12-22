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

int isOperator(char c)
{
	if (c == ' ')
		return -1;
	else if(c == '=')
		return 1;
	else if(c == '+' || c == '-' || c == '*' || c == '/')
		return 2;
	else
		return 0;
}

lint operate(lint a, lint b, char op)
{
	if(a == -1)
		return b;
	switch(op)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;		
	}
	assert(false);
	return 0;
}

int main()
{
	lint t=0, a=-1, b=0, ctr=0;
	char inp[64], tmp, op='#';
	scanint(t);
	while(t--)
	{
		ctr = 0; a = -1; op = '#';
		while((tmp = gc()) != '=')
		{
			if(!isOperator(tmp))
				inp[ctr++] = tmp;
			else if(isOperator(tmp) > 0)
			{
				inp[ctr] = '\0';
				ctr = 0;
				b = atoll(inp);
				a = operate(a, b, op);
				// cout<<"partial "<<a<<endl;
				op = tmp;
			}
		}
		inp[ctr] = '\0';		
		b = atoll(inp);
		// cout<<op<<" "<<a<<" "<<b<<endl;
		a = operate(a, b, op);		
		Print_f(a);
	}
	return 0;
}
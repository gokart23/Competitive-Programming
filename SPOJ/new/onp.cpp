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
#define MAX 401

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

bool isGreater(char a, char b)
{
	if(b == '(')
		return true;
	switch(a)
	{
		case '^':
			return true;
		case '/':
			if(b == '^') return false;
			else return true;
		case '*':
			if(b == '^' || b == '/') return false;
			else return true;
		case '-':
			if(b == '^' || b == '/' || b == '*') return false;
			else return true;
		case '+':
			return false;
	}
}

int main()
{
	lint t=0; scanint(t);
	char expr[MAX];
	stack<char> expression;
	while(t--)
	{
		assert(expression.empty());
		expression.push('(');
		gets(expr);
		for(int i = 0; expr[i] != '\0'; i++)
		{
			switch(expr[i])
			{
				case ')':
					for(;expression.top() != '(';expression.pop())
						pc(expression.top());
					expression.pop();
					break;
				case '(':
				case '^':
					expression.push(expr[i]);
					break;
				case '/':
				case '*':
				case '-':
				case '+':
					for(;!isGreater(expr[i], expression.top());expression.pop())
						pc(expression.top());
					expression.push(expr[i]);
					break;
				default:
					pc(expr[i]);
					break;
			}
		}
		for(;!expression.empty();expression.pop())
			if(expression.top() != '(')
				pc(expression.top());
		pc('\n');
	}
	return 0;
}
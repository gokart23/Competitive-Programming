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
#define MOD 1000000007
#define gc getchar
#define MAX 100003

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
{	_
	bool zero_flag=false;
	lint n=0, exp=0, l=0, i=0; scanint(n);
	char in[MAX], val[MAX];
	val[0]='1',val[1]='\0';
	while(n--)
	{
		cin>>in;
		if(!zero_flag)
		{
			l=strlen(in);
			if(l==1 && in[0] == '0')
				zero_flag=true;
			else
			{
				for(i=(l-1);i>=0;i--)
					{ if(in[i] != '0') break; else exp++; }
				if(i || (!i && in[i]!='1')) in[i+1]='\0', strcpy(val, in);						
				// cout<<exp<<":"<<val<<endl;
			}
		}	
	}
	if(zero_flag)
		cout<<"0";
	else
	{
		cout<<val;
		FOR(i, 0, exp) cout<<"0";
	}
	cout<<endl;
	return 0;
}
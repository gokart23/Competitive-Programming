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
#define MAX 102

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
{_
	char op[2*MAX], buffer[MAX], tmp;
	const char *error = "Error!";
	while(cin>>buffer)
	{
		bool caps=false, success=true;
		lint i=0, j=0;
		while(buffer[i] >= 'a' && buffer[i] <= 'z')
				op[j++] = buffer[i++];
		if(!i)
			success=false;
		else if(buffer[i] == '_')
		{
			for(;buffer[i] != '\0';i++)
			{
				if(buffer[i] == '_') 
					{ if(buffer[i+1] < 'a' || buffer[i+1] > 'z') { success=false; break; } else caps = true; }
				else if(buffer[i] <= 'z' && buffer[i] >= 'a')
					{ op[j++] = (char)((int)buffer[i] - (caps?32:0)); caps=false; op[j] = '\0';}
				else
					{ success=false; break; }
			}			
		}
		else if(buffer[i] >= 'A' && buffer[i] <= 'Z')
		{
			for(;buffer[i] != '\0';i++)
			{
				if(buffer[i] <= 'z' && buffer[i] >= 'a')
					op[j++] = buffer[i];
				else if(buffer[i] <= 'Z' && buffer[i] >= 'A')
					{ op[j++] = '_'; op[j++] = buffer[i]+32; }
				else
					{ success=false; break; }
			}			
		}
		if(success)
		{
			op[j++] = '\0';
			puts(op);
		}
		else
			puts(error);
	}
	return 0;
}
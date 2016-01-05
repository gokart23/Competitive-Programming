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
#define MAX 1002
#define MAX_LEVEL 11

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

struct entry
{
	lint first, second, idx;
} L[MAX];

bool cmp(entry a, entry b)
{
    if(a.first > b.first)
        return false;
    else if(a.first == b.first && a.second > b.second)
        return false;    
    return true;
}

bool eq(entry a, entry b)
{
    if(a.first == b.first && a.second == b.second)
        return true;
    return false;
}

int main()
{
	lint t=0, n=0, lt=0, res=0;
	char inp[MAX];
	lint P[MAX_LEVEL][MAX], O[MAX], LCP[MAX];
    scanint(t);
	while(t--)
	{
        gets(inp);
		n = strlen(inp), res=0;
        lt = ceil(log2(n));
        if(n == 1)
            Print_f(1);
        else if(n == 2)
        {
            if(inp[0] == inp[1])
                Print_f(2);
            else
                Print_f(3);
        }
        else
        {
    		FOR(i, 0, n) P[0][i] = inp[i] - 'A';
    		FOR(k, 1, lt)
    		{
                FOR(i, 0, n) 
                { 
                    L[i].first = P[k-1][i];
                    L[i].second = i+(1<<k-1)<n?P[k-1][i+(1<<k-1)]:-1;
                    L[i].idx = i;
                }
                sort(L, L+n, cmp);
                FOR(i, 0, n)
                    P[k][L[i].idx] = (i>0 && eq(L[i], L[i-1]))?P[k][L[i-1].idx]:i;
                // FOR(i, 0, n)
                //     cout<<"("<<L[i].first<<","<<L[i].second<<","<<L[i].idx<<"):"<<P[k][L[i].idx]<<endl;
                // cout<<endl;
    		}
            FOR(i, 0, lt) 
            {
                FOR(j, 0, n) cout<<P[i][j]<<" ";
                cout<<endl;
            }
            cout<<endl;
            FOR(i, 0, n){
                O[ P [lt-1] [i] ] = i;
                cout<<"O["<<P[lt-1][i]<<"]="<<i<<endl;
            }
            cout<<endl;
            LCP[O[0]] = 0;
            FOR(i, 1, n)
            {
                lint k=lt-1, res=0, x=O[i], y=O[i-1];
                if(P[0][x] != P[0][y])
                    LCP[O[i]] = 0;
                else
                {
                    for(;k>=0 && x<n && y<n;k--)
                        if(P[k][x] == P[k][y])
                        {   res += 1<<k; x += 1<<k; y += 1<<k;   }
                    LCP[O[i]] = res;
                }                
            }
            FOR(i, 0, n)
                printf("%lld - O[%lld]:%lld %s:%lld\n", i, i, O[i], inp+O[i], LCP[O[i]]);
            FOR(i, 0, n)
                res += (n-i-LCP[i]);
            Print_f(res);
        }
	}
	return 0;
}
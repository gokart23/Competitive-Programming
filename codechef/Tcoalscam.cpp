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

typedef struct EdgeTag {
    bool is_chef;  lint cost, src, dst;
} Edge;

typedef struct NodeTag {
    lint colour, length; Edge *edge;
} Node;

bool comp(Edge a, Edge b) {
    if(a.is_chef && !b.is_chef)
        return 1;
    if(!a.is_chef && b.is_chef)
        return -1;
    if(a.is_chef && b.is_chef)
    {
        if(a.cost > b.cost)
            return 1;
        else
            return -1;    
    }
    if(a.cost < b.cost)
        return 1;
    return -1;
}

int main()
{   
    lint t=0, tmp1=0, tmp2=0, n=0, m1=0, m2=0;
    scanint(t);
    while(t--)
    {
        vector<Edge> edges(m1+m2);
        vector<Node> nodes(n);
        scanint(n),scanint(m1),scanint(m2);        
        FOR(i, 0, m1) { scanint(edges[i].src), scanint(edges[i].dst), scanint(edges[i].cost); edges[i].is_chef=false; }        
        FOR(i, 0, m2) { scanint(edges[m1+i].src), scanint(edges[m1+i].dst), scanint(edges[m1+i].cost); edges[m1+i].is_chef=true; }
        FOR(i, 0, n) { nodes[i].colour = i; nodes[i].length=1; nodes[i].edge = NULL; }
        sort(edges.begin(), edges.end(), comp);
        FOR(i,0,m1+m2) cout<<edges[i].src<<" "<<edges[i].dst<<" "<<edges[i].cost<<endl;            
    }
    return 0;
}
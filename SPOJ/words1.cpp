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

int main()
{   
    lint t=0, m=0;
    scanint(t);

    while(t--)
    {
        scanint(m);
        lint first[26], last[26], graph[26][26], count=0, lastSeen=0;
        vector<bool> dupl(26, false);
        char temp[1005];
        lint inExtra=0, outExtra=0;
        bool flag=true;
        
        if(m==2)
        {
            char temp2[1005];
            scanf("%s%s", temp,temp2);
            if(temp[0] == temp2[strlen(temp2) - 1] || temp2[0] == temp[strlen(temp) - 1])
                printf("Ordering is possible.\n");
            else
                printf("The door cannot be opened.\n");            
        }
        else
        {        
             FOR(i, 0, 26)
            {
                first[i]=0, last[i]=0;
                FOR(j, 0, 26)
                    graph[i][j] = 0;
            }
             FOR(i, 0, m)
            {
                scanf("%s", temp);
                
                if(temp[0] == temp[strlen(temp) - 1])
                    dupl[temp[0] - 'a'] = true;
                else
                    {first[temp[0] - 'a']++;last[temp[strlen(temp) - 1] - 'a']++;graph[temp[0] - 'a'][temp[strlen(temp) - 1] - 'a'] = 1;graph[temp[strlen(temp) - 1] - 'a'][temp[0] - 'a'] = 1; lastSeen=(temp[0]-'a');}
            }
            
            FOR(i, 0, 26)
            {
                //cout<<i<<": "<<first[i]<<" "<<last[i]<<" "<<dupl[i]<<endl;
                if(first[i] > last[i])
                    inExtra++;
                else if(first[i] < last[i])
                    outExtra++;
                else if(first[i] == 1 && dupl[i])
                {
                    inExtra++; outExtra++;
                    flag=false;
                    break;
                }            
            }
            cout<<inExtra<<" "<<outExtra<<endl;
            if(flag && inExtra <= 1 && outExtra <= 1)
            {
                FOR(in,0,26){
                    FOR(inn, 0, 26){
                        if(graph[in][inn] == 1){
                            count++;
                            break;
                        }
                    }
                }                
                
                long top;
                stack<lint> myStack;
                bool visited[26], over;
                FOR(j,0,26)
                    visited[j] = false;
                visited[lastSeen] = true;
                count--;
                myStack.push(lastSeen);
                while(!myStack.empty()){
                    over = false;
                    top = myStack.top();
                    FOR(i, 0, 26){
                        if(graph[top][i] == 1 && !visited[i] && i != top){
                            myStack.push(i);
                            over = true;    
                            visited[i] = true;
                            count--;
                            break;          
                        }
                    }
                    if(!over)
                        myStack.pop();
                }
    
                if(count == 0)
                    printf("Ordering is possible.\n");
                else
                    printf("The door cannot be opened.\n");
            }
            else
                printf("The door cannot be opened.\n");            
        }
    }
    
    return 0;
}
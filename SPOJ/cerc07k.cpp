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
	lint row, col;	
	
    scanf("%lld %lld\n", &row, &col);
	while(row && col)
	{
        vector< vector<char> > map(row);
		vector< vector< pair<lint, lint> > > state(row);
        lint initX=0, initY=0, curX=0, curY=0;
        bool success=false, red=false, green=false, blue=false, yellow=false;

		FOR(i, 0, row)
		{
			map[i].reserve(col);
			state[i].reserve(col);
		}        
        
		FOR(i, 0, row)
		{
			FOR(j, 0, col)
			{
				scanf("%c", &map[i][j]);
				
                if(map[i][j] == '*')
                {
                    initX=i,initY=j;
                    state[i][j].first = 0;
                    state[i][j].second = 0;
                }
                else
                {
                    state[i][j].first = -1;
                    state[i][j].second = -1;
                }
			}
		}

		/*FOR(i, 0, row)
		{
			FOR(j, 0, col)
			{
				printf("\'%c\'\t", map[i][j]);
			}
            printf("\n");
		} */
        queue<lint> first, second;
        
        first.push(initX),second.push(initY);
        
        
        while(!queue.empty())
        {
            curX=first.pop(), curY=second.pop();
            if((curX-1)>=0)
            {
                if((curY-1)>=0 && map[curX-1][curY-1] != '#' && (state[curX][curY].second != state[curX-1][curY-1].second))
                {
                    switch(map[curX-1][curY-1])
                    {
                        case 'r':
                            red=true;
                            state[curX-1][curY-1].first=state[curX][curY].first+1;
                            state[curX-1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY-1);
                            break;
                        case 'g':
                            green=true;
                            state[curX-1][curY-1].first=state[curX][curY].first+1;
                            state[curX-1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY-1);
                            break;
                        case 'b':
                            blue=true;
                            state[curX-1][curY-1].first=state[curX][curY].first+1;
                            state[curX-1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY-1);
                            break;
                        case 'y':
                            yellow=true;
                            state[curX-1][curY-1].first=state[curX][curY].first+1;
                            state[curX-1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY-1);
                            break;
                        case 'R':
                            if(red)
                            {
                                first.push(curX-1),second.push(curY-1);
                                state[curX-1][curY-1].first=state[curX][curY].first+1;
                                state[curX-1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'G':
                            if(green)
                            {
                                first.push(curX-1),second.push(curY-1);
                                state[curX-1][curY-1].first=state[curX][curY].first+1;
                                state[curX-1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'B':
                            if(blue)
                            {
                                first.push(curX-1),second.push(curY-1);
                                state[curX-1][curY-1].first=state[curX][curY].first+1;
                                state[curX-1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'Y':
                            if(yellow)
                            {
                                first.push(curX-1),second.push(curY-1);               
                                state[curX-1][curY-1].first=state[curX][curY].first+1;
                                state[curX-1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'X':
                            printf("Escape possible in %lld steps.", state[curX][curY].first+1);
                        default:
                            first.push(curX-1),second.push(curY-1);               
                            state[curX-1][curY-1].first=state[curX][curY].first+1;
                            state[curX-1][curY-1].second=state[curX][curY].second;    
                            
                    }
                }
                if((curY+1)<col && map[curX-1][curY+1] != '#' && (state[curX][curY].second != state[curX-1][curY+1].second))
                {
                    switch(map[curX-1][curY+1])
                    {
                        case 'r':
                            red=true;
                            state[curX-1][curY+1].first=state[curX][curY].first+1;
                            state[curX-1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY+1);
                            break;
                        case 'g':
                            green=true;
                            state[curX-1][curY+1].first=state[curX][curY].first+1;
                            state[curX-1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY+1);
                            break;
                        case 'b':
                            blue=true;
                            state[curX-1][curY+1].first=state[curX][curY].first+1;
                            state[curX-1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY+1);
                            break;
                        case 'y':
                            yellow=true;
                            state[curX-1][curY+1].first=state[curX][curY].first+1;
                            state[curX-1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX-1),second.push(curY+1);
                            break;
                        case 'R':
                            if(red)
                            {
                                first.push(curX-1),second.push(curY+1);
                                state[curX-1][curY+1].first=state[curX][curY].first+1;
                                state[curX-1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'G':
                            if(green)
                            {
                                first.push(curX-1),second.push(curY+1);
                                state[curX-1][curY+1].first=state[curX][curY].first+1;
                                state[curX-1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'B':
                            if(blue)
                            {
                                first.push(curX-1),second.push(curY+1);
                                state[curX-1][curY+1].first=state[curX][curY].first+1;
                                state[curX-1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'Y':
                            if(yellow)
                            {
                                first.push(curX-1),second.push(curY+1);               
                                state[curX-1][curY+1].first=state[curX][curY].first+1;
                                state[curX-1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'X':
                            printf("Escape possible in %lld steps.", state[curX][curY].first+1);
                        default:
                            first.push(curX-1),second.push(curY+1);               
                            state[curX-1][curY+1].first=state[curX][curY].first+1;
                            state[curX-1][curY+1].second=state[curX][curY].second;    
                            
                    }
                }
            }
            if((curX+1)<row)
            {
                if((curY-1)>=0 && map[curX+1][curY-1] != '#' && map[curX-1][curY-1] != '#' && (state[curX][curY].second != state[curX+1][curY-1].second))
                {
                    switch(map[curX+1][curY-1])
                    {
                        case 'r':
                            red=true;
                            state[curX+1][curY-1].first=state[curX][curY].first+1;
                            state[curX+1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY-1);
                            break;
                        case 'g':
                            green=true;
                            state[curX+1][curY-1].first=state[curX][curY].first+1;
                            state[curX+1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY-1);
                            break;
                        case 'b':
                            blue=true;
                            state[curX+1][curY-1].first=state[curX][curY].first+1;
                            state[curX+1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY-1);
                            break;
                        case 'y':
                            yellow=true;
                            state[curX+1][curY-1].first=state[curX][curY].first+1;
                            state[curX+1][curY-1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY-1);
                            break;
                        case 'R':
                            if(red)
                            {
                                first.push(curX+1),second.push(curY-1);
                                state[curX+1][curY-1].first=state[curX][curY].first+1;
                                state[curX+1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'G':
                            if(green)
                            {
                                first.push(curX+1),second.push(curY-1);
                                state[curX+1][curY-1].first=state[curX][curY].first+1;
                                state[curX+1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'B':
                            if(blue)
                            {
                                first.push(curX+1),second.push(curY-1);
                                state[curX+1][curY-1].first=state[curX][curY].first+1;
                                state[curX+1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'Y':
                            if(yellow)
                            {
                                first.push(curX+1),second.push(curY-1);               
                                state[curX+1][curY-1].first=state[curX][curY].first+1;
                                state[curX+1][curY-1].second=state[curX][curY].second;
                            }
                            break;
                        case 'X':
                            printf("Escape possible in %lld steps.", state[curX][curY].first+1);
                            
                        default:
                            first.push(curX+1),second.push(curY-1);               
                            state[curX+1][curY-1].first=state[curX][curY].first+1;
                            state[curX+1][curY-1].second=state[curX][curY].second;    
                            
                    }
                }
                if((curY+1)<col && map[curX+1][curY+1] != '#' && (state[curX][curY].second != state[curX+1][curY+1].second))
                {
                    switch(map[curX+1][curY+1])
                    {
                        case 'r':
                            red=true;
                            state[curX+1][curY+1].first=state[curX][curY].first+1;
                            state[curX+1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY+1);
                            break;
                        case 'g':
                            green=true;
                            state[curX+1][curY+1].first=state[curX][curY].first+1;
                            state[curX+1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY+1);
                            break;
                        case 'b':
                            blue=true;
                            state[curX+1][curY+1].first=state[curX][curY].first+1;
                            state[curX+1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY+1);
                            break;
                        case 'y':
                            yellow=true;
                            state[curX+1][curY+1].first=state[curX][curY].first+1;
                            state[curX+1][curY+1].second=state[curX][curY].second+1;
                            first.push(curX+1),second.push(curY+1);
                            break;
                        case 'R':
                            if(red)
                            {
                                first.push(curX+1),second.push(curY+1);
                                state[curX+1][curY+1].first=state[curX][curY].first+1;
                                state[curX+1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'G':
                            if(green)
                            {
                                first.push(curX+1),second.push(curY+1);
                                state[curX+1][curY+1].first=state[curX][curY].first+1;
                                state[curX+1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'B':
                            if(blue)
                            {
                                first.push(curX+1),second.push(curY+1);
                                state[curX+1][curY+1].first=state[curX][curY].first+1;
                                state[curX+1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'Y':
                            if(yellow)
                            {
                                first.push(curX+1),second.push(curY+1);               
                                state[curX+1][curY+1].first=state[curX][curY].first+1;
                                state[curX+1][curY+1].second=state[curX][curY].second;
                            }
                            break;
                        case 'X':
                            printf("Escape possible in %lld steps.", state[curX][curY].first+1);
                            success=true;
                            break;
                        default:
                            first.push(curX-1),second.push(curY+1);               
                            state[curX-1][curY+1].first=state[curX][curY].first+1;
                            state[curX-1][curY+1].second=state[curX][curY].second;    
                            
                    }
                }
            }
        }
        
        scanf("%lld, %lld\n", &row, &col);
	}
	return 0;
}
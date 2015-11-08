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
	lint t=0;
	scanint(t);
	while(t--)
	{
		lint p=0, l=0, minR=10, flag=0, pTime=0, prevTime=0, paratha=0, maxTime=0, leftEnd=1, rightEnd=1;
		scanint(p), scanint(l);
		vector<lint> chefs(l);
		FOR(i, 0, l)
		{
			scanint(chefs[i]);
			if(chefs[i] < minR)
				minR = chefs[i];
		}
		maxTime = minR * ((p * (p+1))/2);
		pTime = maxTime/2;
        rightEnd = maxTime;
		
		FOR(i, 0, l)
		{	
            //cout<<(lint)(((lint)sqrt((8*pTime/chefs[i]) + 1) - 1)/2)<<endl;
			paratha += (lint)(((lint)sqrt((8*pTime/chefs[i]) + 1) - 1)/2);
		}
		
		if(paratha > p)
            flag = -1;
		else
		 	flag = 1;
        
		while((rightEnd-leftEnd)>1 && pTime >= leftEnd && pTime <= rightEnd)
		{
            //cout<<"pTime: "<<pTime<<" lEnd: "<<leftEnd<<" rEnd:"<<rightEnd<<endl;
		 	paratha=0;
		 	FOR(i, 0, l)
		 	{
		 		paratha += (ulint)(((ulint)sqrt((8*pTime/chefs[i]) + 1) - 1)/2);
		 	}
            //cout<<" "<<paratha<<endl;
            prevTime = pTime;
                        
            if(paratha-p < 0)
            {
                leftEnd = pTime;                
            }
            else
            {
                rightEnd = pTime;                
            }
            pTime = leftEnd + (rightEnd - leftEnd + 1)/2;
		 	
		}
        if(leftEnd == rightEnd)
            Print_f(leftEnd);
        else
        {
            lint lEnd = 0, rEnd=0;
            FOR(i, 0, l)
            {
                    lEnd += (ulint)(((ulint)sqrt((8*leftEnd/chefs[i]) + 1) - 1)/2);
                    rEnd += (ulint)(((ulint)sqrt((8*rightEnd/chefs[i]) + 1) - 1)/2);
            }
            //cout<<leftEnd<<" lEnd: "<<lEnd<<" "<<rightEnd<<" rEnd:"<<rEnd<<endl;
            if(lEnd-p < 0)
                Print_f(rightEnd);
            else
            {
                if((lEnd-p) <= (rEnd-p))
                    Print_f(leftEnd);
                else
                    Print_f(rightEnd);
            }
        }
	}	
	
	return 0;
}
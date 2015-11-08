#include "bits/stdc++.h"

using namespace std;

#define FOR(i, j, k) for(lint i = j; i < k; i++)

typedef unsigned long long int ulint;
typedef long long int lint;
// Fast Input for int
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
	t = Scan_f();
	
	while(t--)
	{
        string h, temp;
		cin>>h;
        
		// while(!h.empty())
		{
			lint index=0;
			temp.clear();

			vector< vector<lint> > dp;
            vector< vector< vector<lint> > > posns;
            dp.resize(h.length());
            posns.resize(h.length());
            
			FOR(i, 0, h.length())
			{
				dp[i].resize(h.length());
                posns[i].resize(h.length());
				dp[i][i] = 1;               
                posns[i][i].push_back(i);
			}
            
            FOR(subPalLength, 2, h.length()+1)
			{
				FOR(i, 0, (h.length() - subPalLength + 1))
				{
					lint j = i + subPalLength - 1;
					if(h[i] == h[j])
					{
						if(subPalLength == 2)
                        {
							dp[i][j] = 2;
                            posns[i][j].push_back(i);
                            posns[i][j].push_back(j);
                        }
						else
                        {
							dp[i][j] = 2 + dp[i+1][j-1];
                            copy(posns[i+1][j-1].begin(), posns[i+1][j-1].end(), back_inserter(posns[i][j]));
                            posns[i][j].push_back(i);
                            posns[i][j].push_back(j);
                        }
                       
					}
					else
					{
                        int w = dp[i+1][j]>dp[i][j-1]?1:0;
						dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                        if(w)
                            copy(posns[i+1][j].begin(), posns[i+1][j].end(), back_inserter(posns[i][j]));
                        else
                            copy(posns[i][j-1].begin(), posns[i][j-1].end(), back_inserter(posns[i][j]));
					}
                    //cout<<i<<", "<<j<<" "<<dp[i][j]<<endl;   
                     cout<<i<<","<<j<<": ";
                        for(lint k : posns[i][j])
                            cout<<k<<" ";
                        cout<<"("<<dp[i][j]<<")"<<endl;
				}
			}
			Print_f(dp[0][h.length() - 1]);
            for(lint k : posns[0][h.length() - 1])
                cout<<k<<" ";
                
        }

  	}

	

	return 0;
}
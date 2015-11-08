#include "bits/stdc++.h"

using namespace std;

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
	ulint n=0, m=0;
	n = Scan_f(), m = Scan_f();
	
	while(n && m)
	{
		pair<int, int> matrix[n][m];
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				matrix[i][j].first = Scan_f();							
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				matrix[i][j].second = Scan_f();							
			}
		}

		for (int i = 0; i < (n-1); ++i)
		{
			for (int j = 0; j < (m-1); ++j)
			{
				matrix[i][j+1].first = matrix[i][j+1].first + matrix[i][j].first;
				matrix[i+1][j].second = matrix[i+1][j].second + matrix[i][j].second;                
			}            
		}
        for(int j=0; j < (m-1); j++)
            	matrix[n-1][j+1].first = matrix[n-1][j+1].first + matrix[n-1][j].first;
        for(int i=0; i < (n-1); i++)
            	matrix[i+1][m-1].second = matrix[i+1][m-1].second + matrix[i][m-1].second;
        
        
		lint i=--n, j=--m, max=0;

		while(i >= 0 && j >= 0)
		{
			if(matrix[i][j].first > matrix[i][j].second)
			{
				max += matrix[i][j].first;
                cout<<matrix[i][j].first<<" added: "<<max<<" i,j:"<<i<<","<<j<<endl;
				i--;
			}
			else
			{
				max += matrix[i][j].second;
                cout<<matrix[i][j].first<<" added: "<<max<<" i,j:"<<i<<","<<j<<endl;
				j--;
			}
		}

		Print_f(max);

		n = Scan_f(), m = Scan_f();
	}
	return 0;
}
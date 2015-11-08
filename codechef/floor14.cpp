#include "bits/stdc++.h"
#define MAX 1e10

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
	ulint t = 0, n=0, m=0;
	t = Scan_f();

	while(t--)
	{
		n = Scan_f(), m = Scan_f();
		ulint ans=0, temp=0;

		if(n&1)
		{
			ans += (((n/2)%m)*(n+1))%m;			
		}
		else
		{
			ans += ((((n+1)/2)%m)*n)%m;
		}
		ans *= ans;
		ans %= m;

		// for(ulint i = 2; i <= n; i++)
		// {
		// 	ulint temp = (i*i*i)%m;
		// 	ulint farji = (n%i)%m;
		// 	ans += (temp * farji)%m;
		// 	ans %= m;
		// }
		// ans %= m;
		Print_f(ans);
	}

	return 0;
}
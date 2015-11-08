#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;
// Fast Input for int
// inline int fast_scan() {
//     int n=0;
//     int ch=getchar_unlocked();
//     while( ch <48 ) {
//         ch=getchar_unlocked();
//     }
//     while( ch >47 ) {
//         n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//     }
//     return n;
// }
// //Fast output for int
// inline void fast_print(int n) {
//     char ch[15];
//     int ind=0;
//     if(n<0) {
//         putchar_unlocked('-');
//         n *= -1;
//     }
//     if(n == 0) {
//         putchar_unlocked('0');
//     }
//     while(n > 0) {
//         ch[ind] = n%10 + '0';
//         n /= 10;
//         ind++;
//     }
//     while(ind--) putchar_unlocked(ch[ind]);
//     putchar_unlocked('\n');
// }

// //Fast input for long long int
// inline long long Scan_f()
// {
//     int c;
//     do
//         c = fgetc(stdin);
//     while ( (c < '0' || c > '9') && c != EOF );

//     long long a = 0;
//     while ( c >= '0' && c <= '9' )
//     {
//         a = a*10 + (c - '0');
//         c = fgetc(stdin);
//     }
//     return a;
// }

// //Fast output for long long int
// inline void Print_f (long long n)
// {
//     char buffer[sizeof(n) * 8 * 3 / 10 + 3];  // 3 digits per 10 bits + two extra and space for terminating zero.
//     int index = sizeof(buffer)-1;
//     int end = index;
//     buffer[index--] = 0;
//     do {
//        buffer[index--] = (n % 10) + '0';
//        n /= 10;
//     } while(n);
//     puts(&buffer[index+1]);
// }

int main()
{
	short tc=0;
	ulint m=0, n=0;
	scanf("%llu", &tc);

	while(tc--)
	{
		scanf("%llu%llu", &m, &n);
		vector<bool> bPrimes;
		vector<ulint> basePrimes;
		bPrimes.resize(ceil(sqrt(n)) + 2, false);

		for (ulint i = 2; i <= ceil(sqrt(n)); ++i)
		{
			if(bPrimes[i])
				continue;
			basePrimes.push_back(i);

			for (ulint j = 2*i; j < floor(sqrt(n)); ++j)
			{
				bPrimes[j] = true;
			}
		}

		vector<bool> primes(n-m ,false);
		for (ulint i = 0; i < basePrimes.size(); ++i)
		{
			ulint t = m - (m%basePrimes[i]);
			for (ulint j = (t); j <= n; j += basePrimes[i])
			{
				if(j < m)
					continue;
				primes[j - m] = true;
			}
		}

		for (int i = 0; i < basePrimes.size(); ++i)
		{
			if(basePrimes[i] >= m && basePrimes[i] <= n)
				printf("%llu\n", basePrimes[i]);
		}
		for (int i = 0; i < bPrimes.size(); ++i)
		{
			if(!primes[i] && (i+m)!=1)
				printf("%llu\n", (i+m));
		}
		printf("\n");
	}

	return 0;
}
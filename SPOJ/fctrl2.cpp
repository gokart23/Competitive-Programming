//Template violated source code restrictions
#include "bits/stdc++.h"

#define FOR(i, j, k) for(lint i = j; i < k; i++)
#define lint long long int

using namespace std;

int main()
{
	lint t=0, n=0;

	scanf("%lld", &t);

	while(t--)
	{
		lint carry = 0, finalDigit = 1;
		vector< lint > factorial(158, 0);
		factorial[0] = 1;

		scanf("%lld", &n);
		
		FOR(i, 1, n+1)
		{
            //printf("%lld:\t", i);
			FOR(j, 0, finalDigit)
			{
				factorial[j] *= i;
				factorial[j] += carry;
				carry = factorial[j] / 10;
				factorial[j] %= 10;
                //printf("%lld ", factorial[j], carry);
				if(j == (finalDigit - 1) && carry > 0)
					finalDigit++;
			}
            //printf("\n");
		}
        
        for(lint i = finalDigit-1; i >= 0; i--)
            printf("%lld", factorial[i]);
        printf("\n");

	}

	return 0;
}
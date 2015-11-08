#include "stdio.h"

#define DIVISOR 1000000007

int main(int argc, char const *argv[])
{
	int t=0;

	scanf("%d", &t);

	while(t--)
	{
		unsigned long long int n=0, m=0, i=0, prev=0, sum=0, num=1, temp=0;
		scanf("%llu %llu", &n, &m);

		for(i=2; i <=m ; i++)
		{
			temp = num;
			num += prev;
			prev = temp;
			// printf("%llu\n", num);
			
			if(i >= n)
			{
				sum += num;
				sum %= DIVISOR;
			}
		}
		printf("%llu\n", sum);

	}

	return 0;
}
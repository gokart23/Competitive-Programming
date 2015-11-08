#include "cstdio"

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long int n=0, M=0;
	scanf("%llu%llu", &n, &M);

	while(M--)
	{
		unsigned long long int q=0;
		scanf("%llu", &q);

		if(q <= n+1 || q > 3*n)
		{
			printf("0\n");
			continue;
		}
		else if(q-n < n+1)
		{
			printf("%llu\n", (q-n-1));
		}
		else
		{
			printf("%llu\n", (3*n+1-q));
		}
	}
	return 0;
}
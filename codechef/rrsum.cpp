#include "cstdio"
#include "map"

using namespace std;

typedef unsigned long long int ulint;

int main(int argc, char const *argv[])
{
	ulint N=0, M=0;
	map<ulint, ulint> pairs;
	scanf("%llu %llu", &N, &M);

	for(ulint i = 0; i < N; i++)
	{
		pairs[2 + N + i] = (i + 1);
	}
	ulint count = N-1;
	for(ulint i = 2; i <= N; i++)
	{
		pairs[(2*N) + i] = count--;
	}

	while(M--)
	{
		ulint q=0;
		scanf("%llu", &q);
		if(pairs.count(q) > 0)
		{
			printf("%llu\n", pairs[q]);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
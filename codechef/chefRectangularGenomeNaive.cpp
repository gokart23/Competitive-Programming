#include "cstdio"

using namespace std;

typedef unsigned long long int ulint;

int main(int argc, char const *argv[])
{
	ulint testcases=0;

	scanf("%llu", &testcases);

	while(testcases--)
	{
		ulint N=0, M=0, K=0;
		bool flag=true;
		scanf("%llu %llu %llu", &N, &M, &K);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if(flag)
				{
					printf("A");
					if(j % 2 == 0)
						flag = false;
				}
				else
				{
					printf("G");
					if(j % 2 == 0)
						flag = true;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
#include "iostream"
#include "cstdio"
#include "string"

using namespace std;

int main(int argc, char const *argv[])
{
	int N = 0;
	unsigned long long int count = 0;
	scanf("%d", &N);
	string matrix[N];
	
	for(int i = 0; i < N; i++)
	{
		cin>>matrix[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(matrix[i][j] == '1')
			{
				// printf("%d: %d ->", i, j);
				for (int k = 0; k < N; ++k)
				{
					if(matrix[j][k] == '1' && k != i && matrix[i][k] != '1')
					{
						// printf("  %d:%d  ", j, k);
						count++;
					}
				}
				// printf("\n");
			}
		}
	}

	printf("%llu\n", count);
	return 0;
}
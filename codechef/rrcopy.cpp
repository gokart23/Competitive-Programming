#include "cstdio"
#include "vector"

using namespace std;

typedef unsigned long long int ulint;

int main(int argc, char const *argv[])
{
	short int testCases = 0;
	
	ulint N=0;
	
	scanf("%u", &testCases);

	while(testCases--)
	{
		// for (int i = 0; i < 10000; ++i)
		// {
		// 	present[i] = false;
		// }
		vector<bool> present;
		ulint count = 0, temp=0;
		
		scanf("%llu", &N);
		while(N--)
		{
			scanf("%llu", &temp);
			temp--;
			if(present[temp] == false)
			{
				present[temp] = true;
				count++;
			}
		}
		printf("%llu\n", count);	
	}

	return 0;
}
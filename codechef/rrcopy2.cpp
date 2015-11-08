#include "cstdio"
#include "algorithm"
#include "vector"

using namespace std;

int main(int argc, char const *argv[])
{
	short int testcases=0;
	scanf("%u", &testcases);
	while(testcases--)
	{
		long int N=0, count=0;
		vector<long int> present;
		scanf("%ld", &N);
		while(N--)
		{
			long int temp;
			scanf("%ld", &temp);
			if(find(present.begin(), present.end(), temp) == present.end())
			{
				count++;
				present.push_back(temp);
			}
		}
		printf("%ld\n", count);
	}
	return 0;
}
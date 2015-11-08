#include "cstdio"

using namespace std;

typedef unsigned long long int ulint;

inline void readInt(ulint & x)
{
	register ulint c = getchar_unlocked();
	x = 0;
	int neg = 0;

	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());	

	if(c == '-')
	{
		neg = 1;
	}
	
	for (; c > 47 && c < 58; c = getchar_unlocked())
	{
		x = (x<<1) + (x<<3) + c - 48;
	}

	if(neg)
	{
		x = -x;
	}
}

int main(int argc, char const *argv[])
{
	ulint N=0, K=0, t=0, count=0;
	//scanf("%llu%llu", &N, &K);
	readInt(N);
	readInt(K);

	for (ulint i = 0; i < N; ++i)
	{
		readInt(t);
		if(t%K == 0)
			++count;
	}

	printf("%llu\n", count);
	return 0;
}
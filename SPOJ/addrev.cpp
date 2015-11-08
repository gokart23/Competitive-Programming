#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

int main(int argc, char const *argv[])
{
	ulint n=0, a=0, b=0, t1=0, t2=0;
	scanf("%llu", &n);
	while(n--)
	{
		scanf("%llu%llu", &a, &b);
		t1=0;
		while(a)
		{
			t1 = (a%10) + (t1*10);
			a /= 10;
		}
		t2=0;
		while(b)
		{
			t2 = (b%10) + (t2*10);
			b /= 10;
		}
		t2 += t1;
		t1=0;
		while(t2)
		{
			t1 = (t2%10) + (t1*10);
			t2 /= 10;
		}
		printf("%llu\n", t1);
	}
	return 0;
}
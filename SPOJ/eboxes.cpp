#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

int main(int argc, char const *argv[])
{
	ulint tc=0, n=0, k=0, t=0, f=0;
	scanf("%llu", &tc);
	while(tc--)
	{
		scanf("%llu%llu%llu%llu", &n, &k, &t, &f);
		// cout<<n<<" "<<k<<" "<<t<<" "<<f<<endl;
		ulint a = k*(f-n);
		// cout<<a<<endl;
		a /= (k-1);
		// cout<<a<<endl;
		a += n;
		// cout<<a<<endl;
		printf("%llu\n", a);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
#ifdef WINDOWS
#define A cout<<"yes";
#else
#define A cout<<"no";
#endif

int main()
{
	int a, b;
	cin>>a;
	A
	cout<<"num of set bits "<<__builtin_popcount(a)<<endl;
	b = a & ~(1<<(__builtin_ctz(a)));
	if(b)
		printf("not a power of 2 0x%x\n", b);
	else
		printf("power of 2 0x%x\n", b);
	cout<<(a<<32)<<endl;

    return 0;
}
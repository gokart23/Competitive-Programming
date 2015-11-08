#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define ulint unsigned long long int
#define lint long long int
#define VI vector<int>
#define VLL vector<lint>
#define VB vector<bool>
#define VVLL vector< VLL >
#define ci(i) cin>>i
#define co(i) cout<<i<<endl
#define FOR(i,j,n) for(lint i=j;i<n;i++)
#define pb push_back
#define s(v) v.size()

long modPow(long a, long x, long p) {
   long res = 1;
   while(x > 0) {
       if( x % 2 != 0) {
           res = (res * a) % p;
       }
       a = (a * a) % p;
       x /= 2;
   }
   return res;
}

long modInverse(long a, long p) {
   return modPow(a, p-2, p);
}
long modBinomial(long n, long k, long p) {
   long numerator = 1; 
   for (int i=0; i<k; i++) {
       numerator = (numerator * (n-i) ) % p;
   }

   long denominator = 1;
   for (int i=1; i<=k; i++) {
       denominator = (denominator * i) % p;
   }

   return ( numerator* modPow(denominator,p-2,p) ) % p;
}

#define MOD 1e9+7

int main()
{	_
	ulint k=0;
	cin>>k;	

	vector<ulint> dp;
	dp.pb(1);

	FOR(i, 1, 10)
	{
		ulint temp = 0, t2=i-k;
		for(ulint j=1; t2 >= 0; j++)
		{
			temp += modBinomial(t2+j, j-1, MOD);
			t2 = i - (j+1)*k;
			temp %= MOD;
		}
		dp.pb(dp[i-1] + temp);
	}

	FOR(i, 0, s(dp))
		cout<<dp[i]<<endl;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

#define MOD (lint)(1e9+7)

int main() {
	lint t, n, k;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &n ,&k);
		vector<lint> sum(n, 1);
		for (lint i = 1 ; i < k; i++)
			sum[i] = ( (sum[i-1]%MOD) + sum[i] )%MOD;
		for (lint i = k; i <= (n-k) ; i++)
			sum[i] = ( (sum[i-k]%MOD) + (sum[i-1]%MOD) + sum[i]) % MOD;
		printf("%lld\n", (1+sum[n-k]));
	}
}

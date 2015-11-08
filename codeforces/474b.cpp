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

int main()
{	_
	lint n=0, m=0, temp=0;
	cin>>n;
	vector<lint> piles(n);
	cin>>piles[0];
	FOR(i, 1, n)
	{
		cin>>temp;
		piles[i] = piles[i-1] + temp;
	}
	
	cin>>m;
	vector<lint> juicy(m);
	FOR(i, 0, m)
		cin>>juicy[i];
	if(n == 1)
	{
		FOR(i, 0, m)
			cout<<"1"<<endl;
	}
	else
	{
		sort(juicy.begin(), juicy.end());

		lint index=0;
		FOR(i, 0, m)
		{
			while(juicy[i] > piles[index])
				index++;
			cout<<piles[index]<<endl;
		}
	}
	
	return 0;
}
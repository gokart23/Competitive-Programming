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
	lint n=0, m=0, cur=0,sum=0, temp=0;
	cin>>n>>m;
    cur = m;
	
    FOR(i, 0, n)
    {
        cin>>temp;
        
        if((cur-temp) < 0)
        {
            cur = m;            
        }
        
        if(cur == m)
            sum++;
        cur -= temp;        
    }        
 
    cout<<sum;

	return 0;
}
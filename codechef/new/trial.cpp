#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
long int n;
inline void fastread_lint(long  int  *a)
{
    char c=0; *a=0;
    while(c<33){c=getchar_unlocked();}
    while(c>33){*a=(*a<<3)+(*a<<1)+c-'0'; c=getchar_unlocked();}
}
long long int get(long int arr[],long int idx)
{
   long long int ans=0;
	while(idx>0)
	{
		ans = ans + arr[idx-1];
		idx = idx - (idx&(-idx));
	}
	return ans;
}
void update(long int arr[],long int idx)
{
	while(idx<n)
	{
		arr[idx-1]++;
		idx = idx + (idx&(-idx));
	}
}
int main(void)
{
	long int i;
    long long int ans =0;
	fastread_lint(&n);
	vector< pair<long int ,long int> > pr(n);long int arr[n];
	for(i=0;i<n;i++)
	{
		fastread_lint(&pr[i].first);
        fastread_lint(&pr[i].second);
		arr[i] = pr[i].second;
	}
	sort(pr.begin(),pr.end());
	sort(arr,arr+n);
	for(i=0;i<n;i++)
	{
		long int ind = (int)(lower_bound(arr,arr+n,pr[i].second)-arr);
		pr[i].second = ind + 1;
 	}
 	memset(arr,0,sizeof arr);
 	   
 	for(i=n-1;i>=0;i--)
 	{
 		ans = ans + get(arr,pr[i].second-1);
 		update(arr,pr[i].second);
 	}
 	printf("%lld\n",ans);
	
	
	
	
	
	
	return 0;
}
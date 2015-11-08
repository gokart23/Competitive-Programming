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
#define S(i) scanf("%d",&i)
#define SL(i) scanf("%lld",&i)
#define PL(i) printf("%lld\n",i)
#define P(i) printf("%d\n",i)
#define MOD 1000000007
#define gc getchar_unlocked

#define LIMITS 10000

typedef set<lint> LintSet;

lint amicableNums()
{
	map<lint, LintSet > hashTable;
	vector<lint> values(LIMITS+1);
	values[1] = 0;
	LintSet elements;	
	for(int i = 2; i < LIMITS; i++)
	{
		lint sum=1;
		//cout<<i<<": ";
		for(int j = 2; j < floor(sqrt(i)); j++)
			if(!(i%j))
				{ sum += (j); sum += (i/j); }//cout<<j<<" "<<i/j<<" "; }
		if(round(sqrt(i))*round(sqrt(i)) == i)
			{ sum += round(sqrt(i)); } //cout<<round(sqrt(i))<<"(square "<<i<<")"; }
		else if(! ( i % (lint)(floor(sqrt(i))) ) && ((lint)(floor(sqrt(i))) != 1) )
			{ sum += floor(sqrt(i)); sum += i/floor(sqrt(i)); }// cout<<floor(sqrt(i))<<" "<<(i/floor(sqrt(i))); }
		//cout<<" -- "<<sum<<endl;
		values[i] = sum;
		if(!hashTable.count(sum))
		{
			hashTable[sum] = LintSet();
			hashTable[sum].insert(i);
			//cout<<"\tcreated entry for "<<sum<<" added "<<i<<endl;
		}
		else
			{ hashTable[sum].insert(i); } //cout<<"\t\tadded "<<i<<" to "<<sum<<endl; }
	}
	for(int i = 1; i < LIMITS; i++)
	{
		if(hashTable.count(values[i]))
		{
			elements.insert(i);
			for(LintSet::iterator it = hashTable[values[i]].begin(); it != hashTable[values[i]].end(); it++)
				elements.insert(*it);				
		}
	}
	lint totSum=0;
	for(LintSet::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		cout<<*it<<endl;
		lint prevSum = totSum;
		totSum += *it;
		assert(prevSum < totSum);
	}
	cout<<totSum<<endl;
	// for(map<lint, LintSet>::iterator it = hashTable.begin(); it != hashTable.end(); it++)
	// {
	// 	cout<<it->first<<": ";
	// 	for(LintSet::iterator t = (it->second).begin(); t != (it->second).end(); t++)
	// 		cout<<*t<<" ";
	// 	cout<<endl;			
	// }
}

unsigned int sum_divisors(unsigned int n) {
    unsigned int s = 0, i = 1;
    while(i < n) {
        if(n % i == 0) s = s + i;
        i++;
    }
    return s;
}
 
unsigned int sum_amicable_pairs(unsigned int low, unsigned int high) {
    unsigned int a = low, b, sum = 0;
    while(a <= high) {
        b = sum_divisors(a);
        if(b > a && sum_divisors(b) == a) sum = sum + a + b;
        a++;
    }
    return sum;
}
 
int main(int argc, char **argv) {
	// amicableNums();
    unsigned int ans = sum_amicable_pairs(1,10000);
    printf("result: %d\n",ans);
    return 0;
}
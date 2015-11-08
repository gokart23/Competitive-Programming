#include "bits/stdc++.h"
#define N 10000

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int index = 0;
	vector<int> marked(N+1, 1), pNum(1200);
	map<ulint, list<int> > primes;
	for (int i = 2; i < N+1; ++i)
	{
		if(!marked[i])
			continue;
		if(i >= 1000)
		{
			pNum[index++] = i;
			// cout<<pNum.back()<<" "<<i<<endl;
			primes[i].clear();			
		}
		for (int j = (2*i); j < N+1; j += i)
			marked[j] = 0;		
	}
	
	for (int i = 0; i < index; ++i)
	{
		int digits[4], num=0;

		digits[0] = pNum[i]%10, digits[1] = (pNum[i]%100)/10, digits[2] = (pNum[i]%1000)/100, digits[3] = (pNum[i])/1000;		
		
		for (int j = 0; j < 4; ++j)
		{	
			int power = lround(pow(10, j)), base = pNum[i] - (power * digits[j]);
			for (int k = 0; k < 10; ++k)
			{
				if(j == 3 && k == 0)
					continue;
				// cout<<num<<endl;
				num = base + power*k;
				if(num != pNum[i] && primes.count(num) > 0)
				{
					primes[pNum[i]].push_back(num);					
				}
			}
		}		
	}

	ulint t=0, init=0, fin=0;

	scanf("%llu", &t);
	while(t--)
	{
		scanf("%llu%llu", &init, &fin);
		if(init == fin)
		{
			printf("0\n");
			continue;
		}
		bool flag = true;
		int level = -1;
		queue<pair<ulint, ulint> > q;
		q.push(make_pair(init, 0));
		while(!q.empty() && flag)
		{
			pair<int, int> p = q.front();
			// cout<<"Current element "<<p.first<<endl;
			q.pop();
			for(list<int>::iterator it = primes[p.first].begin(); it != primes[p.first].end();it++)
			{
				// cout<<*it<<endl;
				if(*it == fin)
				{
					level = p.second + 1;
					flag = false;
					break;
				}
				else
				{
					q.push(make_pair(*it, p.second + 1));
				}
			}
		}

		if(flag)
			printf("Impossible\n");
		else
			printf("%d\n", level);
	}

	return 0;
}
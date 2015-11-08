#include "iostream"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

int main(int argc, char const *argv[])
{
	typedef long long int ulint;

	ulint N=0, K=0, P=0, temp=0, src=0, dest=0, hops=0, dist=0, reqHops=0;
	vector<ulint> input;
	map<ulint, ulint> store;

	cin>>N>>K>>P;

	for (ulint i = 0; i < N; ++i)
		{
			cin>>temp;
			input.push_back(temp);
		}

	vector<ulint> tempV(input);
	sort(tempV.begin(), tempV.end());
	tempV.erase( unique( tempV.begin(), tempV.end() ), tempV.end() );

	for (ulint i = 0; i < N; ++i)
	{
		store.insert(std::pair<ulint, ulint>(tempV[i], i));
	}

	for(map<ulint, ulint>::iterator it = store.begin(); it != store.end(); it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}


	for (ulint i = 0; i < P; ++i)
	{
		cin>>src>>dest;
		ulint t1 = input[dest - 1], t2 = input[src - 1];
		ulint temp1 = store[t1], temp2 = store[t2];
		hops = abs(temp1 - temp2 - 1);//store[input[dest - 1]] ;//- (ulint)store[input[dest - 1]];
		dist = abs(t1 - t2);//input[dest - 1];// - input[dest - 1];
		reqHops = dist/K;
		cout<<hops<<" "<<dist<<" "<<reqHops<<" ";
		if(dist <= K)
			cout<<"Yes"<<endl;
		else
		{
			if(dist%K == 0)
				reqHops--;

			if(hops >= reqHops)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}
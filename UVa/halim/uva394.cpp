#include "bits/stdc++.h"
#define _ std::ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef unsigned long int ulint;

int main(int argc, char const *argv[])
{ _
	ulint arrayNum=0, refNum=0, t[3], m[2];
	string temp;

	cin>>arrayNum>>refNum;

	map<string, vector<ulint> > arrays;

	while(arrayNum--)
	{
		cin>>temp>>t[0]>>t[1]>>t[2];
		vector<ulint> deltas(t[2]), constants(t[2] + 1), lowers(t[2]);
		
		for (ulint i = 0; i < t[2]; ++i)
		{
			cin>>m[0]>>m[1];

			lowers[i] = m[0];
			deltas[i] = (m[1] - m[0] + 1);
			// cout<<i<<" "<<deltas[i]<<endl;
		}

		constants[t[2]] = t[1];
		// cout<<t[2]<<" "<<constants[t[2]]<<endl;
		for (int i = --t[2]; i > 0; --i)
		{
			constants[i] = constants[i+1] * deltas[i];
			// cout<<i<<" "<<constants[i]<<endl;
		}
		constants[0] = t[0];
		for (int i = 1; i < (t[2] + 2); ++i)
		{
			constants[0] -= (constants[i] * lowers[i - 1]);
		}
		// cout<<"0 "<<constants[0]<<endl;

		arrays[temp] = constants;
	}

	while(refNum--)
	{
		cin>>temp;
		if(arrays.count(temp) > 0)
		{
			vector<ulint> cn = arrays[temp];
			vector<ulint> inp(cn.size() - 1);
			// cout<<inp.size()<<endl;
			for (ulint i = 0; i < inp.size(); ++i)
			{
				cin>>m[0];
				inp[i] = m[0];
			}
			t[1]=cn[0];
			// cout<<"init "<<t[1];
			for (ulint i = 0; i < inp.size(); ++i)
			{
				t[1] += cn[i + 1] * inp[i];
			}
			cout<<temp<<"["<<inp[0];
			for (int i = 1; i < inp	.size(); ++i)
			{
				cout<<", "<<inp[i];
			}
			cout<<"] = "<<t[1]<<endl;
		}
	}

	return 0;
}
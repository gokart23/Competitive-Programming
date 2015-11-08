#include "iostream"
#include "map"
#include "vector"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

int main(int argc, char const *argv[])
{
	ulint N=0, K=0, P=0, temp=0, temp2=0;
	vector<ulint> input;
	map<ulint, bool> bins;

	cin>>N>>K>>P;
	input.reserve(N);

	for (ulint i = 0; i < N; ++i)
	{
		cin>>temp;
		input[i] = temp;
		bins[temp/(2*K)] = true;
	}

	for (ulint i = 0; i < P; ++i)
	{
		cin>>temp>>temp2;
		ulint val1 = input[--temp], val2 = input[--temp2];

		if(val1/(2*K) == val2/(2*K))
		{
			cout<<"Yes"<<endl;
			continue;
		}
		else
		{
			ulint bin1=0, bin2=0;
			if(val1 > val2)
			{
				bin1 = val2/(2*K);
				bin1 = val1/(2*K);
			}
			else
			{
				bin1 = val1/(2*K);
				bin2 = val2/(2*K);				
			}
			
			bool flag = false;
			for (int i = (++bin1); i < bin2; ++i)
				{
					if(!bins.count(i))
					{
						cout<<"No";
						flag = true;
						break;
					}
				}
			if(!flag)
				cout<<"Yes"<<endl;

		}
	}

	return 0;
}
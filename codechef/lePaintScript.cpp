#include "iostream"
#include "vector"
#include "cstdlib"

using namespace std;

int main(int argc, char const *argv[])
{
	cout<<"{\n";
	for (int i = 1; i < 101; ++i)
	{
		int nums[i][i];
		vector<int> factors;

		for (int k = 0; k < i; ++k)
		{
			for (int l = 0; l < i; ++l)
			{
				nums[k][l] = 0;					
			}		
		}
		nums[0][0] = 1;

		for (int j = i-1; j > 0; --j)
		{
			if(i%j == 0)
				factors.push_back(j);
			for (int k = 0; k < i; ++k)
			{
				nums[j][k] = 1;
			}			
		}
		sort(factors.begin(), factors.end());

		for (int j = (factors.size() - 1); j >= 0 ; --j)
		{			
			for(int k = 0; k < i; k++)
			{
				if(k%factors[j]==0)
					nums[factors[j]][k] = i/(i/factors[j]);
				else
					nums[factors[j]][k] = 0;
			}
			for (int k = 2*factors[j]; k < i; k += factors[j])
			{
				if(nums[k][0] != 1)
					continue;
				else
				{
					// cout<<factors[j]<<": "<<k<<endl;
					for (int l = 0; l < i; ++l)
					{
						if(l % factors[j] == 0)
							nums[k][l] = i/(i/factors[j]);	
						else
							nums[k][l] = 0;
					}
					
				}
			}			
		}

		cout<<"{";
		for (int j = 0; j < i; ++j)
		{	
			cout<<"{ ";
			for (int k = 0; k < i; ++k)
			{
				cout<<nums[j][k]<<", ";
			}
			cout<<"},";
		}
		cout<<"},"<<endl;

	}
	cout<<"}";
	return 0;
}
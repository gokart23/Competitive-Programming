#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<unsigned long long int> sorted, unsorted;
	unsigned long long int N=0, K=0, P=0, temp=0, temp2=0, temp3=0;
	cin>>N>>K>>P;

	for (unsigned long long int i = 0; i < N; ++i)
	{
		cin>>temp;
		sorted.push_back(temp);
		unsorted.push_back(temp);
	}

	std::sort(sorted.begin(), sorted.end());

	// for (unsigned long long int i = 0; i < N; ++i)
	// {
	// 	cout<<i<<":"<<sorted[i]<<" ";
	// }
	// cout<<endl;
	// for (unsigned long long int i = 0; i < N; ++i)
	// {
	// 	cout<<i<<":"<<unsorted[i]<<" ";
	// }
	// cout<<endl;
	// cout<<endl;


	for(unsigned long long int i = 0; i < P; i++)
	{
		cin>>temp;
		cin>>temp2;
		temp3 = --temp;
		temp = unsorted[temp3];
		temp3 = --temp2;
		temp2 = unsorted[temp3];

		if(temp > temp2)
		{
			temp3 = temp;
			temp = temp2;
			temp2 = temp3;
		}

		unsigned long long int idx = std::lower_bound(sorted.begin(), sorted.end(), temp) - sorted.begin();
		// cout<<"dest:"<<temp2<<endl;
		for(unsigned long long int j = idx; j < N; j++)
		{
			if(sorted[j] == temp2)
			{
				cout<<"Yes"<<endl;
				break;
			}
			if((sorted[j + 1] - sorted[j]) > K)
			{
				cout<<"No"<<endl;
				break;
			}
			// cout<<sorted[j]<<" ";
		}
		// cout<<endl;
	}

	return 0;
}
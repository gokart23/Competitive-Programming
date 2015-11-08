#include "iostream"
//Codechef July'14 Long Contest Challenge -> Problem 'Reach the Point'
using namespace std;

int main(int argc, char const *argv[])
{
	typedef long long int lint;
	typedef unsigned long long int ulint;

	ulint testcases=0;

	cin>>testcases;

	while(testcases--)
	{
		lint X=0, Y=0, diff=0, sum=0;
		cin>>X>>Y;
		X = X>0?X:(-X);
		Y = Y>0?Y:(-Y);

		if(X == Y)
		{
			cout<<2*X<<endl;
		}
		else
		{
			diff = X - Y;
			if(diff > 0)
			{
				((diff)&1)?sum+=1:sum;
				sum += (2*diff) + (2*Y);
				cout<<sum<<endl;
			}
			else
			{
				((diff)&1)?sum-=1:sum;
				sum += (-2*diff) + (2*X);
				cout<<sum<<endl;				
			}
		}
	}
	return 0;
}
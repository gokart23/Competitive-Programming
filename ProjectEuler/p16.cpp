#include "iostream"

#define LIMIT 999
using namespace std;

int main(int argc, char const *argv[])
{
	unsigned int * nums = new unsigned int[350];//350 digits should be fine for most powers, I guess
	unsigned int i=0, maxI=0, carry=0, iterations=LIMIT, sum=0;

	nums[0] = 2;

	for (int i = 1; i < 100; ++i)
	{
		nums[i]=0;
	}

	while(iterations--)
	{
		carry = 0;
		for(i=0; i <= maxI; i++)
		{
			nums[i] *= 2;
			nums[i] += carry;
			carry = nums[i]/10;
			nums[i] %= 10;
			if(carry != 0)
			{
				maxI = max(maxI, i+1);
			}
		}		
	}

	for(i=0; i <= maxI; i++)
		{	
			sum += nums[i];		
		}

	cout<<sum<<endl<<++maxI;	

	delete [] nums;
	return 0;
}
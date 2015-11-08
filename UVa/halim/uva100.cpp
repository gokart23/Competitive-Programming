#include "bits/stdc++.h"
#define _ std::ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(int argc, char const *argv[])
{ _
	typedef unsigned long int ulong;
	ulong i=0, j=0;
	while(cin>>i>>j)
	{
		bool flag = false;
		if(i > j)
		{
			flag = true;
			i = i + j;
			j = i - j;
			i = i - j;
		}

		ulong maxNum=0, maxChainLength=0, curNum=i, curLength=1;

		for (curNum = i; curNum <= j; ++curNum)
		{
			curLength = 0;
			ulong temp = curNum;
			while(temp != 1)
			{
				if(temp % 2 == 0)
				{
					while(temp % 2 == 0)
					{
						curLength++;
						temp /= 2;
					}

				}
				else
				{
					curLength += 2;
					temp = (3*temp + 1)/2;
				}
			}

			if(curLength > maxChainLength)
			{
				maxChainLength = curLength;
				maxNum = curNum;
			}
		}

		flag?cout<<j<<" "<<i<<" "<<maxChainLength+1<<endl:cout<<i<<" "<<j<<" "<<maxChainLength+1<<endl;
	}

	return 0;
}
#include "stdio.h"
#define LIMIT 1000000

int main(int argc, char const *argv[])
{
	typedef unsigned long int ulong;

	ulong maxNum=0, maxChainLength=0, curNum=0, curLength=0;

	for (curNum = 1; curNum < LIMIT; ++curNum)
	{
		curLength = 0;
		ulong temp = curNum;
		while(temp != 1)
		{
			if(temp % 2 == 0)
			{
				// curLength++;
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

		// if(curNum == 13)
		// {
		// 	printf("%lu\n", curLength);
		// }
		if(curLength > maxChainLength)
		{
			maxChainLength = curLength;
			maxNum = curNum;
		}
	}

	printf("%lu : %lu\n", maxNum, maxChainLength);

	return 0;
}
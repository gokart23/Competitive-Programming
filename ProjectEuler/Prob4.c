#include "stdio.h"
#include "string.h"

int isNumPalindrome(long);

int main(int argc, char const *argv[])
{
	long int i=999, j=999, num=0, max=0;
		
	while(i > 99)
	{
		while(j > 99)
		{
			num = i * j;
			if(j <= i && isNumPalindrome(num))//Checking i/j rel in order to avoid calculating the same thing twice
			{
				printf("Pal: %d = %dx%d\n", num, i, j);
				
				if(num > max)
					max = num;				
			}
			j--;
		}
		
		j = 999;
		i--;
	}

	printf("Max: %d\n", max);
	return 0;
}

int isNumPalindrome(long num)
{
	int i = 0, length = 0;
	char strNum[7];

	sprintf(strNum, "%d", num);
	length = strlen(strNum);

	for(i=0; i < (length/2); i++)
	{
		if(strNum[i] != strNum[length - i - 1])
			return 0;
	}

	return 1;
}
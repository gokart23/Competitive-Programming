#include "stdio.h"

int main(int argc, char const *argv[])
{
	int i = 0;
	unsigned long int testcases=0, length=0, ones=0;
	
	scanf("%lu", &testcases);

	while(testcases--)
	{
		ones=0;
		scanf("%lu", &length);
		char* string = (char*)malloc(length * sizeof(char));
		scanf("%s", string);

		for(i=0; i < length; i++)
		{
			if(string[i] == '1')
			{
				ones++;
			}
		}

		printf("%lu\n", ((ones+1)*ones)/2);
		free(string);
	}


	return 0;
}
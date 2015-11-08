#include "bits/stdc++.h"
//#define _ std::ios_base::sync_with_stdio(false);cin.tie(false);

int main(int argc, char const *argv[])
{
	bool flag=false;
	int c;
	c = getchar();
	while(c != EOF)
	{
		if(c ==  '"')
		{
				if(flag)
				{
					printf("''");
					flag = false;
				}
				else
				{
					printf("``");
					flag = true;
				}
		}
		else
			printf("%c", c);
		
		c = getchar();
	}		
	return 0;
}
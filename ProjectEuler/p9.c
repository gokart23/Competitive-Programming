#include "stdio.h"
//Uses Dickson's method for generating Pythagorean triplets
int main(int argc, char const *argv[])
{
	int flag = 1;
	unsigned long int r=0, s=0, t=0;

	while(flag)
	{
		r += 2;
		unsigned long int temp = (r*r)/2;
		for(s=1;s<(temp/2) && s<1000 ;s++)
		{
			if(temp % s == 0)
			{
				t = temp/s;
				//printf("%lu (%lu) : %lu , %lu [%lu, %lu, %lu]\n", temp, r, s, t, r+s, r+t, r+s+t);
				if((3*r + 2*s + 2*t) == 1000)				
				{
					flag = 0;
					printf("%lu + %lu + %lu =%lu\n", (r+s), (r+t), (r+s+t), (3*r + 2*s + 2*t));
					printf("%lu\n", ((r+s)*(r+t)*(r+s+t)));
					break;
				}
			}
		}
	}
	
	return 0;
}
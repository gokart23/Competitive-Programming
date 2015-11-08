#include "math.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
	unsigned long int U=0, W=0, v=0, V=0, w=0, u=0;
	scanf("%lu%lu%lu%lu%lu%lu", &v, &w, &u, &U, &W, &V);

	unsigned long int X=(w-U+v)*(U+v+w), x=(U-v+w)*(v-w+U), Y=(u-V+w)*(V+w+u), y=(V-w+u)*(w-u+V), Z=(v-W+u)*(W+u+v), z=(W-u+v)*(u-v+W);
	//printf("%lu %lu %lu %lu %lu %lu\n",X, x,Y, y, Z, z);
	double a=sqrt(x*Y*Z), b=sqrt(y*Z*X), c=sqrt(z*X*Y), d=sqrt(x*y*z);
	
	double volA = (b+c+d-a)*(a+c+d-b)*(a+b+d-c)*(a+b+c-d), volB = 192*u*v*w;
	double vol = sqrt(volA)/volB;

	printf("%.4f\n", vol);

	return 0;
}
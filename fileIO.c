#include <stdio.h>
#define MAX 20

int main(int argc, char const *argv[])
{
	FILE *f1=NULL;
	char filename[20];

	printf("Enter filename\n");
	scanf("%19s", filename);

	if((f1 = fopen(filename, "r")) != NULL)
	{
		while(!feof(f1))
		{
			int temp;
			fscanf(f1, "%d", &temp);
			printf("%d\n", temp);
		}

		fclose(f1);
	}
	else
	{
		printf("Error: File does not exit\n");
	}


	return 0;
}


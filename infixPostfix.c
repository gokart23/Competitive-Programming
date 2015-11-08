#include <stdio.h>
#include <string.h>
#define MAX 20

void getPostfix(char*, char*);
int popoutStack(char* output, char* stack, int index, int index2);

int main(int argc, char const *argv[])
{
	char input[MAX];
	int i = 0, num=0;

	printf("Enter input size\n");
	scanf("%d", &num);

	printf("Enter input");
	scanf("%s", input);

	char* result;
	getPostfix(input, result);

	printf("%s\n", result);

	return 0;
}

void getPostfix(char* input, char* result)
{
	char output[MAX], prev='\0', stack[MAX];
	int i = 0, index=0, index2=0;
	printf("%d", strlen(input));
	for (i = 0; i < strlen(input); ++i)
	{
		switch(input[i])
		{
			case '/':prev = '/';
					stack[index] = '/';
					index++;
			break;
			
			case '*':if(prev == '/')
				{
					index2 = popoutStack(output, stack, index, index2);
					index = 0;
					prev = '*';
					stack[index] = '*';
					index++;
				}
				else
				{
					prev = '*';
					stack[index] = '*';
					index++;
				}
			break;

			case '+':if(prev == '/' || prev == '*')
					{
						index2 = popoutStack(output, stack, index, index2);
						index = 0;
						prev = '+';
						stack[index] = '+';
						index++;
					}
					else
					{
						prev = '+';
						stack[index] = '+';
						index++;	
					}
			break;

			case '-':if(prev == '/' || prev == '*' || prev == '+')
					{
						index2 = popoutStack(output, stack, index, index2);
						index = 0;
						prev = '-';
						stack[index] = '-';
						index++;
					}
					else
					{
						prev = '-';
						stack[index] = '-';
						index++;					
					}
			break;
			
			default: output[index2] = input[i];
					index2++;
					
			break;
		}
	}
	index2 = popoutStack(output, stack, index, index2);
	output[index2] = '\0';

	result = output;
}

int popoutStack(char* output, char* stack, int index, int index2)
{
	int i = 0;
	for(i=index;i>=0;i--)
	{
		output[index2] = stack[i];
		index2++;
		stack[i] = '\0';
	}

	return index2;
}
#include <stdio.h>
#include <string.h>
#define MAX 20

int checkPalindrome(char*);

int main(int argc, char const *argv[])
{
	char string[MAX];
	
	printf("Enter string\n");
	scanf("%s", string);

	if(checkPalindrome(string))
	{
		printf("Palindrome");
	}
	else
	{
		printf("Not a palindrome\n");
	}

	return 0;
}

int checkPalindrome(char* input)
{
	char stackArray[MAX], *head=NULL;
	int i = 0;

	for(i=0;i<strlen(input)/2;i++)
	{
		stackArray[i] = input[i];
		head = &stackArray[i];
	}

	int offset = 0;
	if(strlen(input)%2 != 0)
	{
		offset = 1;
	}
	
	for(i=(strlen(input)/2 + offset);i<strlen(input);i++)
	{
		if(input[i] != *head)
		{
			return 0;
		}

		head--;
	}

	return 1;	
}
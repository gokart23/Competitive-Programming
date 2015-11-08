#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

typedef struct SquareTag
{
	struct SquareTag *next, *prev;
} Square;

int main(int argc, char const *argv[])
{
	ulint counter=0, n=0, m=0;
	char c=0;
	scanf("%llu %llu", &n, &m);
	Square *temp = NULL;
	vector<Square> squares;
	squares.reserve(m*n);

	for (ulint i = 0; i < m*n; ++i)
	{
		squares[i].next = NULL;
		squares[i].prev = NULL;
	}

	for (ulint i = 0; i < m*n; ++i)
	{
		scanf("%c", &c);
		switch(c)
		{
			case 'N':
				temp = &squares[i - m];
			break;
			case 'E':
				temp = &squares[i + 1];
			break;
			case 'W':
				temp = &squares[i - 1];
			break;
			case 'S':
				temp = &squares[i + m];
			break;
		}
		if(temp->next != NULL || temp->prev != NULL)
			counter++;
		
		squares[i].next = temp;
		temp->prev = &squares[i];
	}

	printf("%llu", counter);
	return 0;
}
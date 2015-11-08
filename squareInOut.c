#include <stdio.h>
#include <math.h>

typedef struct lineTag
{
	float m, c;
} Line;

typedef struct pointTag
{
	float x, y;
} Point;

void getLines(Line* lines, Point* square);

int main(int argc, char const *argv[])
{
	int i = 0, max=0;
	Point square[4];
	Line lines[4];

	printf("Enter square points in x,y format: \n");
	for (i = 0; i < 4; ++i)
	{
		scanf("%d,%d", &square[i].x, &square[i].y);
	}

	for (i = 1; i < 4; ++i)
	{
		if((pow(square[i].x - square[0].x, 2) + pow(square[i].y - square[0].y, 2)) > (pow(square[max].x - square[0].x, 2) + pow(square[max].y - square[0].y, 2)))
		{
			max = i;
		}
	}

	Point temp = square[i];
	square[i] = square[3];
	square[3] = temp;

	float side = sqrt((pow(square[2].x - square[0].x, 2) + pow(square[2].y - square[0].y, 2)));

	getLines(lines, square);



	return 0;
}

void getLines(Line* lines, Point* square)
{
	int i = 0, j = -1;

	for (i = 1; i <= 3; ++i)
	{
		if((square[(j==-1?0:j)].x - square[i].x) == 0)
		{
			lines[i-1].m = INFINITY;
			lines[i-1].c = -INFINITY;
		}
		else
		{
			lines[i-1].m = (square[(j==-1?0:j)].y - square[i].y)/(square[(j==-1?0:j)].x - square[i].x);
			lines[i-1].c =  square[(i)].y - ((lines[i-1].m)*square[i].x);
		}

		printf("%d %d %f %f\n", j, i, lines[i-1].m, lines[i-1].c);
		j++;
	}

	if((square[2].x - square[3].x) == 0)
	{
		lines[3].m = INFINITY;
		lines[3].c = -INFINITY;
	}
	else
	{
		lines[3].m = (square[(2)].y - square[3].y)/(square[2].x - square[3].x);
		lines[3].c =  square[(3)].y - ((lines[3].m)*square[3].x);
	}
	printf("%d %d %f %f", j, i, lines[3].m, lines[3].c);
}
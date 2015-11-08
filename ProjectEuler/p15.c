//Prob15: Uses adjacency matrix representation of a graph and applies DFS
//		  to calculate number of paths present
#include "stdio.h"

int numPaths=0;
int gridSize, vSize, vRow;
int** grid;

void traversePath(int);

int main() {		

	int i=0, j=0;	

	gridSize = 20;
	vSize = (int)((gridSize+1)*(gridSize+1));
	vRow = (gridSize + 1);

	grid = (int**)malloc(sizeof(int*) * vSize);

	for(i = 0; i < vSize; i++)
	{
		grid[i] = (int*)malloc(sizeof(int) * vSize);
	}

	for (i = 0; i < vSize; i++) 
		{
			for (j = 0; j < vSize; j++) {
				if((j == (i+1)) && (i%vRow != gridSize))
				{
					grid[i][j] = 1;
				}
				
				if((j == (i + vRow)) && (i/vRow != gridSize))
				{
					grid[i][j] = 1;
				}
			}
		}

		// for (int i = 0; i < vSize; i++) {
		// 	for (int j = 0; j < vSize; j++) {
		// 		System.out.print(grid[i][j] + "  ");
		// 	}
		// 	System.out.println();
		// }

		traversePath(0);

		printf("%d\n", numPaths);
}

void traversePath(int vNum)
{
	int i = 0;

	if(vNum == (vSize-1))
	{
		numPaths++;
		return;
	}
	else
	{
		for(i = 0; i < vSize; i++)
		{
			if(grid[vNum][i] == 1)
			{
				//System.out.println(vNum + "->" + i);
				traversePath(i);
			}
		}
	}
}

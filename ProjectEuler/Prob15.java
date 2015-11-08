//Prob15: Uses adjacency matrix representation of a graph and applies DFS
//		  to calculate number of paths present
public class Prob15 {

	static int numPaths=0;
	final static int gridSize = 20, vSize = (int)Math.pow(gridSize+1, 2), vRow = (gridSize + 1);
	static int grid[][] = new int[vSize][vSize];

	public static void main(String[] args) {		

		for (int i = 0; i < vSize; i++) 
		{
			for (int j = 0; j < vSize; j++) {
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

		System.out.println(numPaths);
	}

	public static void traversePath(int vNum)
	{
		if(vNum == (vSize-1))
		{
			numPaths++;
			return;
		}
		else
		{
			for(int i = 0; i < vSize; i++)
			{
				if(grid[vNum][i] == 1)
				{
					//System.out.println(vNum + "->" + i);
					traversePath(i);
				}
			}
		}
	}
}
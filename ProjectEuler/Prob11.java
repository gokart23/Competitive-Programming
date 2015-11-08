import java.io.*;
import java.util.*;

public class Prob11
{
	public static void main(String[] args) throws IOException, FileNotFoundException {
		
		final int SQUARE_SIDE = 20;
		final int DIGITS = 4;

		int grid[][] = new int[SQUARE_SIDE][SQUARE_SIDE];
		long horizMax=0, verMax=0, diagMax=0, diagMax2=0;
		BufferedReader reader = new BufferedReader(new FileReader("ip11.txt"));
				
		for(int i = 0;i < SQUARE_SIDE;i++)
		{
			Scanner sc = new Scanner(reader.readLine());
			sc.useDelimiter(" ");
			for(int j = 0;sc.hasNext();j++)
			{
				grid[i][j] = Integer.parseInt(sc.next());			

			}
		}

		int readingFrame[] = new int[DIGITS];

		for(int i = 0; i < SQUARE_SIDE; i++)
		{
			for(int j = 0; j < DIGITS; j++)
			{
				readingFrame[j] = grid[i][j];
			}

			for(int j = 4; j < SQUARE_SIDE; j++)
			{
				long m = multiplyArray(readingFrame);

				if(m > horizMax)
					horizMax = m;

				readingFrame[(j - DIGITS) % DIGITS] = grid[i][j];

			}

		}

		for(int i = 0; i < SQUARE_SIDE; i++)
		{
			for(int j = 0; j < DIGITS; j++)
			{
				readingFrame[j] = grid[j][i];
			}

			for(int j = 4; j < SQUARE_SIDE; j++)
			{
				long m = multiplyArray(readingFrame);

				if(m > verMax)
					verMax = m;

				readingFrame[(j - DIGITS) % DIGITS] = grid[j][i];				
			}
		}

		for(int i = 0; i <= (SQUARE_SIDE - DIGITS); i++)
		{
			for(int j = 0; j < DIGITS; j++)
			{
				readingFrame[j] = grid[i+j][j];
				//System.out.print(grid[(i+j)][(j)] + "\t");
			}
			//System.out.println();

			for(int j = 1; j <= (SQUARE_SIDE - DIGITS); j++)
			{
				long m = multiplyArray(readingFrame);

				if(m > diagMax)
					diagMax = m;

				for(int k = 0; k < DIGITS; k++)
				{
					readingFrame[k] = grid[i+k][j+k];
					//System.out.print(grid[(i+k)][(j+k)] + "\t");
				}
				//System.out.println();
				
			}
		}

		for(int i = 19; i >= 3; i--)
		{
			for(int j = 0; j < DIGITS; j++)
			{
				readingFrame[j] = grid[i - j][j];
				// System.out.print(grid[(i-j)][(j)] + "\t");
			}
			// System.out.println();

			for(int j = 1; j <= (SQUARE_SIDE - DIGITS); j++)
			{
				long m = multiplyArray(readingFrame);

				if(m > diagMax2)
					diagMax2 = m;

				for(int k = 0; k < DIGITS; k++)
				{
					readingFrame[k] = grid[i - k][j + k];
					// System.out.print(grid[(i-k)][(j+k)] + "\t");
				}
				// System.out.println();
			}
		}

		System.out.println(horizMax + " " + verMax + " " + diagMax + " " + diagMax2);
		// for (int i = 0;i < 20;i++) {
		// 	for (int j = 0;j < 20 ;j++ ) {
		// 		System.out.print(grid[i][j] + " ");
		// 	}			
		// 	System.out.println("\n");
		// }
	}

	public static long multiplyArray(int[] array)
	{
		long mul = 1;

		for (int i = 0; i < array.length; i++) {
				mul *= array[i];
		}

		return mul;
	}
}
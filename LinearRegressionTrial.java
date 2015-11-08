import java.util.Scanner;

public class LinearRegressionTrial
{
	int numData;
	Vector[] inputData;

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		System.out.println("Enter size of input data:\t");
		numData = Integer.parseInt(input.next());
		inputData = new Vector[numData];
		System.out.println("Enter data:\n");

		for (int i = 0; i < numData; i++) {
			inputData[i] = new Vector(2, Integer.parseInt(input.next()));		
		}
		
		System.out.println(input.next());
	}
}

class Vector
{
	private int dimension;
	private int key;
	private int[] data;

	public Vector(int dimension, int key)
	{
		this.dimension = dimension;
		this.key = key;

		data = new int[dimension];
	}

	public boolean setData(int[] data)
	{
		if(data.length == dimension)
		{
			for (int i = 0;i < dimension ;i++ ) {
				this.data[i] = data[i]; 
			}

			return true;
		}
		else
		{
			return false;
		}
	}
}
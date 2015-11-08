import java.io.*;

public class MatrixTest
{
	public static void main(String[] args) {
		try
		{

		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter input dimensions: ");
		Matrix matrix = new Matrix(Integer.parseInt(input.readLine()), Integer.parseInt(input.readLine()));

		}
		catch(IOException ie)
		{
			ie.printStackTrace();
		}

	} 
}

class Matrix
{
	private int m, n;

	public Matrix(int m, int n)
	{
		this.m = m;
		this.n = n;
		System.out.println(m + " " + n);
	}
}

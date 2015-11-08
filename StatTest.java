import java.io.*;
import java.util.*;

public class StatTest
{
	static int dim, num;

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);

		System.out.println("Enter vector dimension\t:");
		dim = input.nextInt();
		/*System.out.println("Enter number of vectors\t:");
		num = input.nextInt();*/
		num=2;

		Vector[] vectors = new Vector[num];

		for(int j = 0; j < num; j++)
		{
			System.out.println("Enter vector " + j +  ":\n");
			vectors[j] = new Vector(dim);
			for (int i = 0; i < dim; i++) {
				vectors[j].setData(input.nextInt(), i);
			}		
		}

		System.out.println(Vector.expectation(vectors[0]));
		System.out.println(Vector.expectation(vectors[1]));
		System.out.println(Vector.covariance(vectors[0], vectors[1]));
		System.out.println(Vector.correlation(vectors[0], vectors[1]));
	}

	public static void printVector(Vector vector)
	{
		for(int i = 0; i < dim; i++)
		{
			System.out.print(vector.getData(i) + " ");
		}
	}
}

class Vector
{
	private int dim, data[];
	public Vector(int dim)
	{
		this.dim = dim;
		data = new int[dim];
	}

	public int getDim()
	{
		return dim;
	}

	public void setData(int data, int index)
	{
		this.data[index] = data;		
	}

	public int getData(int index)
	{
		return data[index];
	}

	public static float expectation(Vector vec)
	{
		float sum = 0;
		for(int i = 0; i < vec.getDim(); i++)
		{
			sum += vec.getData(i);
		}

		sum /= vec.getDim();

		return sum;
	}

	public static float covariance(Vector vec1, Vector vec2)
	{
		float exp1 = Vector.expectation(vec1), exp2 = Vector.expectation(vec2), sum=0;

		for (int i = 0; i < vec1.getDim(); i++) {
			sum += (vec1.getData(i) - exp1)*(vec2.getData(i) - exp2);
		}

		sum /= vec1.getDim();

		return sum;
	}

	public static float variance(Vector vec)
	{
		float var = 0, exp = Vector.expectation(vec);

		for (int i = 0; i < vec.getDim(); i++) {
			var += Math.pow((vec.getData(i) - exp), 2);
		}

		var /= vec.getDim();

		return var;
	}

	public static float correlation(Vector vec1, Vector vec2)
	{
		float cov = Vector.covariance(vec1, vec2), dev1 = (float)Math.sqrt((float)Vector.variance(vec1)), dev2 = (float)Math.sqrt((float)Vector.variance(vec2));

		return (cov/(dev1 * dev2));
	}
}
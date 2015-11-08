import java.io.*;

public class Prob15Two {

	final int gridSize = 2, vRow = (gridSize + 1), vSize = Math.pow(vRow, 2);

	public static void main(String[] args) {
		for(int i=0; i < vSize;)
		{
			
		}
	}
}

class LinkedList
{
	private LinkedList nextOne=null, LinkedList nextTwo=null;
	private int verticeNum=0;

	public LinkedList(int verticeNum, LinkedList nextOne, LinkedList nextTwo)
	{
		this.verticeNum = verticeNum;
		this.nextOne = nextOne;
		this.nextTwo = nextTwo;
	}

	public int getVNum()
	{
		return verticeNum;
	}

	public LinkedList getNOne()
	{
		return nextOne;
	}

	public LinkedList getNTwo()
	{
		return nextTwo;
	}
}
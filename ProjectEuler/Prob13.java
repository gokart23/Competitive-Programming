import java.io.*;

public class Prob13{
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader("inp_p13.txt"));
		String nums[] = new String[100];
		
		String s;

		for(int i = 0;(s = reader.readLine()) != null;i++)
		{
			nums[i] = s;
			// System.out.println(nums[i]);
		}

		long carry=0, sum[], totSum=0;
		sum = new long[10];

		for (int i = 0; i < 50; i++) {
			long tempSum=0;
			
			for(int j = 0; j < 100; j++)
			{
				long k = Long.parseLong(new Character(nums[j].charAt(49 - i)).toString());		
				tempSum += k;
			}
			//System.out.print(tempSum + " " + carry + " ");
			tempSum += carry;

			if(i >= 40 && i != 49)
			{
				sum[i - 40] = (tempSum%10);
				carry = (long)(tempSum/10);
			}
			else if(i == 49)
			{
				sum[9] = (tempSum);
				carry = 0;
			}
			else
			{
				carry = (long)(tempSum/10);	
			}			
		}

		for(int i = 0; i < 10; i++)
		{
			totSum += (sum[i]) * Math.pow(10, i);
		}

		System.out.println(new Long(totSum).toString().substring(0, 10));	
	}
}
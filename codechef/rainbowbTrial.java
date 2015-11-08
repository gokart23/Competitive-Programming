import java.io.*;
import java.math.*;

public class rainbowbTrial
{
	public static void main(String[] args) {
		try
		{
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			String NUM = reader.readLine();
			BigInteger num = new BigInteger(NUM);
			
			if(num.compareTo(new BigInteger("13")) < 0)
			{
				System.out.println("0");
				return;
			}

			num = num.subtract(BigInteger.ONE);
			num = num.shiftRight(1);

			BigInteger ans = new BigInteger("120");
			BigInteger next = new BigInteger("6");
			BigInteger now = BigInteger.ONE;
			BigInteger cur = new BigInteger("120");

			while(next.compareTo(num) < 0)
			{
				// System.out.println(now + " " + next + " " + cur + " " + ans + " " + num);
				cur = cur.divide(now);
				cur = cur.multiply(next);
				now = now.add(BigInteger.ONE);
				next = next.add(BigInteger.ONE);
				ans = ans.add(cur);
			}
			ans = ans.divide(new BigInteger("120"));
			ans = ans.mod(new BigInteger("1000000007"));

			System.out.println(ans);
		}
		catch(Exception e)
		{

		}		
	}
}
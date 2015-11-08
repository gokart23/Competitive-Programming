import java.io.*;
import java.math.*;

public class Julka
{
	public static void main(String[] args) {
		try{
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			int testcases = 10;
			BigInteger TWO = new BigInteger("2");
			while(testcases-- != 0)
			{
				BigInteger apples = new BigInteger(reader.readLine());
				BigInteger more = new BigInteger(reader.readLine());

				BigInteger natalia = apples.subtract(more);
				natalia = natalia.divide(TWO);
				System.out.println(natalia.add(more));
				System.out.println(natalia);
			}			
		}
		catch (Exception e) {
			
		}
	}
}
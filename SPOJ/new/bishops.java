import java.io.*;
import java.util.*;
import java.math.*;

public class bishops {
	public static void main(String[] args) {
		try
		{
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			String input;
			while((input=reader.readLine()) != null)
			{
				BigInteger n = new BigInteger(input);
				if(n.equals(BigInteger.ONE))
					System.out.println("1");
				else
					System.out.println(n.subtract(BigInteger.ONE).shiftLeft(1));
			}
		}
		catch (Exception e) {
			
		}
	}
}
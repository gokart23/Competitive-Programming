import java.math.*;
import java.io.*;

class floor14Java {
	public static void main(String[] args) {
		BigInteger n = new BigInteger("");
		BigInteger m = new BigInteger("");
		BigInteger ans = BigInteger.ZERO;
		BigInteger i = BigInteger.ONE;
		BigInteger TWO = new BigInteger("2");

		ans = ans.add(n);
		ans = ans.multiply(n.add(BigInteger.ONE));
		ans = ans.divide(TWO);
		ans = ans.pow(2);
		ans = ans.multiply(n);
		
		for(; i.compareTo(n) <= 0; i = i.add(BigInteger.ONE))
		{
			
		}
	}
}
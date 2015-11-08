import java.math.*;
import java.io.*;

class July14Retpo {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		long testcases = Long.parseLong(reader.readLine());

		while(testcases-- != 0) 
		{
			String[] s = reader.readLine().split(" ");
			BigInteger x = new BigInteger(s[0]);
			BigInteger y = new BigInteger(s[1]);
			BigInteger dist = x.abs().add(y.abs());
			System.out.println(dist);
		}
	}
}
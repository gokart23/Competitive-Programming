import java.math.*;
import java.io.*;

class FastMultiplication {
	public static void main(String[] args) {
		try{
			BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
			int testCases = Integer.parseInt(r.readLine());
			while(testCases-- != 0)
			{
				String[] nums = r.readLine().split(" ");
				BigInteger a = new BigInteger(nums[0]);
				BigInteger b = new BigInteger(nums[1]);

				System.out.println(a.multiply(b));
			}
		}
		catch (Exception e) {
			
		}
	}
}
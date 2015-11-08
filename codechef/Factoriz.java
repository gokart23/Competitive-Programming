import java.io.*;
import java.math.*;
import java.util.*;

class Factoriz {
	public static void main(String[] args) {
		// for(int i = 0; i <= 1000; i++)
		// 	System.out.print("0");
		try
		{
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			int t=Integer.parseInt(reader.readLine());

			final int RANGE = 35000;
			ArrayList<Boolean> isPrime = new ArrayList<Boolean>(RANGE);
			for(int i = 0; i < RANGE; i++)
			{
				isPrime.add(false);			
				//System.out.println(i + " " + isPrime.get(i));
			}
			//System.out.println("------------------------");
			ArrayList<BigInteger> primes = new ArrayList<BigInteger>();
			for (int i = 2; i < RANGE; i++) {
				if(!isPrime.get(i))
				{
					primes.add(new BigInteger(new Integer(i).toString()));
					for(int j = 2*i; j < RANGE; j+=i)
						isPrime.set(j, true);
				}
			}

			while(t-- > 0)
			{
				BigInteger num = new BigInteger(reader.readLine());
				ArrayList<BigInteger> list = new ArrayList<BigInteger>();
				
				for(int i = 0; i < primes.size(); i++)
				{
					if(num.mod(primes.get(i)).compareTo(BigInteger.ZERO) == 0)
					{
						while(num.mod(primes.get(i)).compareTo(BigInteger.ZERO) == 0)
						{
							list.add(primes.get(i));
							num = num.divide(primes.get(i));
						}
					}
				}

				if(num.compareTo(BigInteger.ONE) != 0)
					list.add(num);

				System.out.println(list.size());
				for(int i =0; i < list.size(); i++)
					System.out.println(list.get(i));
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
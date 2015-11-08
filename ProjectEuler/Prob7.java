import java.util.*;
import java.io.*;
//Basically, a modified form of sieve of Erastosthenes
public class Prob7
{
	public static void main(String[] args) throws IOException{
		BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
		
		long num = (long)Math.pow(2, 18);//Randomly choosing a range large enough to contain 10001th prime but small enough not to slow down the sieve

		ArrayList<Long> numbers = new ArrayList<Long>();
		ArrayList<Long> primes = new ArrayList<Long>();

		for(long i = 2; i < num; i++)
		{
			numbers.add(i);
		}

		while(primes.size() != 10001 && !numbers.isEmpty())
		{
			long i = numbers.get(0);
			numbers.remove(new Long(i));
			primes.add(new Long(i));
			for(long j = 2*i; j < num; j += i)
			{
				numbers.remove(new Long(j));
			}
		}

		System.out.println(primes.get(10000));
	}
}
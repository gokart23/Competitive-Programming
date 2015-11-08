import java.util.*;
import java.io.*;

public class Prob10
{
	public static void main(String[] args) throws IOException{
		
		final int LIMIT = 1000000;

		ArrayList<Long> numbers = new ArrayList<Long>();
		ArrayList<Long> primes = new ArrayList<Long>();

		for(long i = 3; i < LIMIT; i+=2)
		{
			numbers.add(i);
		}

		primes.add((long)2);

		while(!numbers.isEmpty())
		{
			long i = numbers.get(0);
			numbers.remove((long)i);
			primes.add((long)i);
			System.out.println(i);
			for(long j = 2*i; j < LIMIT; j += i)
			{
				numbers.remove((long)j);
				//System.out.println(i + ": " +j);
			}
		}

		long sum = 0;

		for(long i : primes)
		{
			sum += i;
		}

		System.out.println(sum);
	}
}
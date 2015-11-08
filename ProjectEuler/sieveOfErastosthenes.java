import java.util.*;
import java.io.*;

class sieveOfErastosthenes
{
	public static void main(String[] args) throws IOException{
		BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(rd.readLine());

		while(testcases-- != 0)
		{
			String[] nums = rd.readLine().split(" ");
			long start = Long.parseLong(nums[0]);
			long end = Long.parseLong(nums[1]);

			ArrayList<Long> numbers = new ArrayList<Long>();
			ArrayList<Long> primes = new ArrayList<Long>();

			for(long i = 2; i <= end; i++)
			{
				numbers.add(i);
			}

			while(!numbers.isEmpty())
			{
				long i = numbers.get(0);
				numbers.remove((long)i);
				primes.add((long)i);
				for(long j = 2*i; j <= end; j += i)
				{
					numbers.remove((long)j);
				}
			}

			for(long i = 0; i < primes.size(); i++)
			{
				if(primes.get((int)i) >= start && primes.get((int)i) <= end)
				{
					System.out.println(primes.get((int)i));
				}
			}
			System.out.println();
			
		}
		
	}
}
import java.io.*;

public class Prob3
{
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

		long num = Long.parseLong(r.readLine());
		long sqrtNum = (long)Math.ceil(Math.sqrt(num));

		for(int i = 2; num%i == 0;)
		{
			num /= 2;
		}

		if(num == 1)
		{
			System.out.println("2");
			return;
		}
		long i = 3; 
		while(i != num)
		{
			if(num % i == 0)
			{
				num /= i;
			}
			else
			{
				i += 2;
			}
		}

		System.out.println(i);
	}
}
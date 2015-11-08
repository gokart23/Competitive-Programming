import java.io.*;

class GardenGameJava {
	public static void main(String[] args) throws IOException {
		long testcases=0, N=0;

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testcases = Long.parseLong(reader.readLine());

		while(testcases-- != 0)
		{
			N = Long.parseLong(reader.readLine());
			long[] input = new long[(int)N];
			long lcm=1;

			String[] str = reader.readLine().split(" ");

			for (long i = 0; i < N; i++) {
				input[(int)i] = Long.parseLong(str[(int)i]) - 1;	
			}

			for (long i = 0; i < N; i++) {
				long pos=(input[(int)i]), j=1, temp2 = lcm, temp3 = 0, temp=0;

				while(pos != (i))
				{
					++j;
					pos = input[(int)pos];
				}
				temp = j;

				if(j < temp2)
				{
					temp3 = temp2;
					temp2 = j;
					j = temp3;
				}

				while(temp2 != 0)
				{
					temp3 = j;
					j = temp2;
					temp2 = temp3 % j;
				}
				lcm = temp * lcm / j;
			}

			System.out.println(lcm%1000000007);
		}
	}
}
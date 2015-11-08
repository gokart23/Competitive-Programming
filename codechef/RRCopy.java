import java.io.*;

class Main
{
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int testcases= Integer.parseInt(reader.readLine());

		while(testcases-- != 0)
		{
			long N = Long.parseLong(reader.readLine());
			long count = 0;
			boolean present[] = new boolean[100000];
			String[] s = reader.readLine().split(" ");
			for(long i = 0; N-- != 0; i++)
			{
				long temp = Long.parseLong(s[(int)i]);
				if(!present[(int)temp])
				{
					present[(int)temp] = true;
					count++;
				}
			}
			System.out.println(count);
		}

	}
}
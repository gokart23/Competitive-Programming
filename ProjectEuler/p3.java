import java.util.*;
import java.io.*;

public class ProbThree
{
	public static void main(String[] args) throws IOException{
		long a;

		a = Long.parseLong(new BufferedReader(new InputStreamReader(System.in)).readLine());

		System.out.println(StrictMath.sqrt(a));
	}
}
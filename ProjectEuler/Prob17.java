public class Prob17 {
	public static void main(String[] args) {
		final int maxNum = 1000;
		long numLetters=0;
		
		for(int i = 1; i <= maxNum; i++)
		{
			StringBuffer curNum = new StringBuffer();
			switch (getDigits(i)) {
				case 1: curNum.append(getDigitName(i, 1));
				break;
				case 2: int tens = i/10, units = i%10;
					if(tens == 1)
					{
						switch(i)
						{
							case 10: curNum.append("ten");
							break;
							case 11:curNum.append("eleven");
							break;
							case 12:curNum.append("twelve");
							break;
							case 13:curNum.append("thirteen");
							break;
							case 14:curNum.append("fourteen");
							break;
							case 15:curNum.append("fifteen");
							break;
							case 16:curNum.append("sixteen");
							break;
							case 17:curNum.append("seventeen");
							break;
							case 18:curNum.append("eighteen");
							break;
							case 19:curNum.append("nineteen");
							break;							
						}
					}
					else
					{
						curNum.append(getDigitName(tens, 2));
						if(units != 0)
						{
							curNum.append(getDigitName(units, 1));
						}
					}
				break;
				case 3: int hundreds = i/100, ten=((i/10) - (10 * hundreds)), ones = i%10;
						curNum.append(getDigitName(hundreds, 1));
						if(ten==0 && ones==0 )
						{
							curNum.append("hundred");
						}
						else
						{
							curNum.append("hundredand");
							if(ten == 1)
							{
								switch(i%100)
								{
									case 10: curNum.append("ten");
									break;
									case 11:curNum.append("eleven");
									break;
									case 12:curNum.append("twelve");
									break;
									case 13:curNum.append("thirteen");
									break;
									case 14:curNum.append("fourteen");
									break;
									case 15:curNum.append("fifteen");
									break;
									case 16:curNum.append("sixteen");
									break;
									case 17:curNum.append("seventeen");
									break;
									case 18:curNum.append("eighteen");
									break;
									case 19:curNum.append("nineteen");
									break;							
								}
							}
							else
							{
								curNum.append(getDigitName(ten, 2));
								if(ones != 0)
								{
									curNum.append(getDigitName(ones, 1));
								}
							}		
						}
				break;
				case 4: curNum.append("onethousand");
				break;
			}
			numLetters += curNum.toString().length();
			System.out.println(i + " " + curNum.toString() + " " + curNum.toString().length());			
		}
		System.out.println(numLetters);

	}

	public static String getDigitName(int digit, int code)
	{
		switch(code)
		{
			case 1: switch(digit)
			{
				case 1: return "one";
				
				case 2: return "two";
				
				case 3: return "three";
				
				case 4: return "four";
				
				case 5: return "five";
				
				case 6: return "six";
				
				case 7: return "seven";
				
				case 8: return "eight";
				
				case 9: return "nine";
				
			}
			break;
			case 2: switch(digit)
			{
				case 1: return "ten";
				case 2: return "twenty";
				case 3: return "thirty";
				case 4: return "forty";
				case 5: return "fifty";
				case 6: return "sixty";
				case 7: return "seventy";
				case 8: return "eighty";
				case 9: return "ninety";
			}
			break;
		}

		return "";
	}

	public static int getDigits(int num)
	{
		int digits=0;

		while(num!=0)
		{
			digits++;
			num /= 10;
		}

		return digits;
	}
}
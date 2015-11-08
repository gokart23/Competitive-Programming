#include "iostream"
#include "string"

using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0;
	unsigned long long int testcases=0, length=0, ones=0;
	string str;

	cin>>testcases;

	while(testcases--)
	{
		ones=0;
		cin>>length;
		cin>>str;		

		for(i=0; i < length; i++)
		{
			if(str[i] == '1')
			{
				ones++;
			}
		}

		cout<<((ones+1)*ones)/2<<endl;		
	}

	return 0;
}
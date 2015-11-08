#include "iostream"
#include "string"
#include "vector"
#include "sstream"
//INCOMPLETE
using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

int main(int argc, char const *argv[])
{
	ulint testcases=0, N=0, temp=0;
	string input, strtemp, org;
	stringstream ss;
	vector<ulint> posn;

	cin>>testcases;

	while(testcases--)
	{
		cin>>N;
		posn.reserve(N);

		for (ulint i = 0; i < N; ++i)
		{
			cin>>temp;
			posn[i] = --temp;
			ss<<temp;
		}

		input = ss.str();
		org = input;
		ss.str(string());

		do
		{
			strtemp = input;
			for (ulint i = 0; i < N; ++i)
			{
				input[posn[i]] = temp[i];
			}
			cout<<input<<endl;
		}while(org != input);

		input.clear();
		posn.clear();
	}
	return 0;
}
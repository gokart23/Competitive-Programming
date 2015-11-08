#include "iostream"
#include "vector"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

typedef struct {
	ulint cycle=0;
	ulint next=0;
} Unit;

int main(int argc, char const *argv[])
{
	ulint testcases=0, N=0, temp=0;

	cin>>testcases;
	while(testcases--)
	{
		ulint lcm=1;
		cin>>N;
		vector<Unit> units;
		units.reserve(N);	
		
		for (ulint i = 0; i < N; ++i)
		{
			cin>>temp;
			units[i].next = --temp;
			units[i].cycle = 1;
			for (ulint j = 0; j < i; ++j)
			{
				if(units[j].next == i)
				{
					units[j].cycle++;
					if(j == temp)
					{
						units[j].next = -1;	
						cout<<j<<": "<<units[j].cycle<<endl;
					}
					else
						units[j].next = temp;
				}
			}
		}

		for (ulint i = 0; i < N; ++i)
		{
			ulint t1 = lcm>units[i].cycle?lcm:units[i].cycle, t2 = units[i].cycle + lcm - t1, t3=0;

			while(t2)
			{
				t3 = t1;
				t1 = t2;
				t2 = t3 % t2;
			}

			lcm = (lcm * units[i].cycle) / t1;
		}
		cout<<lcm<<endl;

	}
	return 0;
}
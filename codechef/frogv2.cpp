#include "iostream"
#include "cstdlib"
#include "vector"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

typedef struct {
	ulint dist;
	ulint idNum;
} Frog;

int cmp(const void *a, const void *b)
{
	Frog *t1 = (Frog*)a;
	Frog *t2 = (Frog*)b;
	//cout<<a.dist<<" "<<b.dist;
	if(t1->dist > t2->dist)
		return 1;
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	ulint N=0, K=0, P=0, temp=0, temp2=0;
	vector<Frog> input;
	vector<ulint> sequences;

	cin>>N>>K>>P;
	input.reserve(N);
	sequences.reserve(N);

	for (ulint i = 0; i < N; ++i)
	{
		cin>>temp;
		input[i].idNum = (i);
		input[i].dist = temp;
	}

	std::qsort(&input[0], N, sizeof(Frog), *cmp);

	// for (ulint i = 0; i < N; ++i)
	// {
	// 	cout<<i<<": "<<input[i].dist<<"("<<input[i].idNum<<")"<<endl;
	// }
	ulint seq = 0;
	
	sequences[0] = 0;
	for (ulint i = 1; i < N; ++i)
	{
		if((input[i].dist - input[i-1].dist) <= K)
		{
			sequences[input[i].idNum] = seq;
		}
		else
		{
			sequences[input[i].idNum] = ++seq;
		}
	}

	// for (int i = 0; i < N; ++i)
	// {
	// 	cout<<i<<": "<<sequences[i]<<endl;
	// }

	for (ulint i = 0; i < P; ++i)
	{
		cin>>temp>>temp2;
		if(sequences[--temp] == sequences[--temp2])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
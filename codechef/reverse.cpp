#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;

// Fast Input for int
inline int fast_scan() {
    int n=0;
    int ch=getchar_unlocked();
    while( ch <48 ) {
        ch=getchar_unlocked();
    }
    while( ch >47 ) {
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    }
    return n;
}
//Fast output for int
inline void fast_print(int n) {
    char ch[15];
    int ind=0;
    if(n<0) {
        putchar_unlocked('-');
        n *= -1;
    }
    if(n == 0) {
        putchar_unlocked('0');
    }
    while(n > 0) {
        ch[ind] = n%10 + '0';
        n /= 10;
        ind++;
    }
    while(ind--) putchar_unlocked(ch[ind]);
    putchar_unlocked('\n');
}

//Fast input for long long int
inline long long Scan_f()
{
    int c;
    do
        c = fgetc(stdin);
    while ( (c < '0' || c > '9') && c != EOF );

    long long a = 0;
    while ( c >= '0' && c <= '9' )
    {
        a = a*10 + (c - '0');
        c = fgetc(stdin);
    }
    return a;
}

//Fast output for long long int
inline void Print_f (long long n)
{
    char buffer[sizeof(n) * 8 * 3 / 10 + 3];  // 3 digits per 10 bits + two extra and space for terminating zero.
    int index = sizeof(buffer)-1;
    int end = index;
    buffer[index--] = 0;
    do {
       buffer[index--] = (n % 10) + '0';
       n /= 10;
    } while(n);
    puts(&buffer[index+1]);
}

vector<ulint> minD;

typedef struct EdgeTag
{
	ulint dest, cost;
} Edge;

bool compare(ulint v1, ulint v2)
{
	return minD[v1] > minD[v2];
}

int main()
{
	ulint n=0, m=0, t1=0, t2=0, t3=-1;
	//n = Scan_f(), m= Scan_f();
	scanf("%llu%llu", &n, &m);
	vector<list<Edge> > graph;
	map<ulint, bool> seen;
	graph.resize(n);
	minD.resize(n, -1);
	Edge t;
	minD[0] = 0;
	while(m--)
	{
		t1 = Scan_f() - 1, t2 = Scan_f() - 1;
		// scanf("%llu%llu", &t1, &t2);
		t1--; t2--;

		if(t1 == t2)
			continue;
		t.dest = t2;
		t.cost = 0;
		graph[t1].push_back(t);
		t.dest = t1;
		t.cost = 1;
		graph[t2].push_back(t);
	}

	vector<ulint> heap;

	heap.push_back(0);

	while(heap.size())
	{
		ulint a = heap.front();
		seen[a] = true;
		// cout<<"Top: "<<a<<endl;
		if(a == (n-1))
			break;
		
		pop_heap(heap.begin(), heap.end());
		heap.pop_back();

		while(!graph[a].empty())
		{
			Edge b = graph[a].front();
			if(seen.count(b.dest) > 0)
			{
				graph[a].pop_front();
				continue;
			}
			if(minD[b.dest] > (minD[a] + b.cost))
				minD[b.dest] = minD[a] + b.cost;
			// cout<<"\t"<<b.dest<<" : Cost "<<b.cost<<endl;
			graph[a].pop_front();
			heap.push_back(b.dest);
		}
		make_heap(heap.begin(), heap.end(), compare);
	}

	if(minD[n-1] == t3)
		printf("%d", -1);
	else
		Print_f(minD[n-1]);// printf("%llu", minD[n-1]);//Print_f(minD[n-1]);

	return 0;
}
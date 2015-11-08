#include "bits/stdc++.h"
#define FOR(i, j, k) for(register ulint i =j ; i < k; i++)
using namespace std;

typedef unsigned long long int ulint;
typedef long long int lint;
// // Fast Input for int
// inline int fast_scan() {
//     int n=0;
//     int ch=getchar_unlocked();
//     while( ch <48 ) {
//         ch=getchar_unlocked();
//     }
//     while( ch >47 ) {
//         n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//     }
//     return n;
// }
// //Fast output for int
// inline void fast_print(int n) {
//     char ch[15];
//     int ind=0;
//     if(n<0) {
//         putchar_unlocked('-');
//         n *= -1;
//     }
//     if(n == 0) {
//         putchar_unlocked('0');
//     }
//     while(n > 0) {
//         ch[ind] = n%10 + '0';
//         n /= 10;
//         ind++;
//     }
//     while(ind--) putchar_unlocked(ch[ind]);
//     putchar_unlocked('\n');
// }

// //Fast input for long long int
// inline long long Scan_f()
// {
//     int c;
//     do
//         c = fgetc(stdin);
//     while ( (c < '0' || c > '9') && c != EOF );

//     long long a = 0;
//     while ( c >= '0' && c <= '9' )
//     {
//         a = a*10 + (c - '0');
//         c = fgetc(stdin);
//     }
//     return a;
// }

// //Fast output for long long int
// inline void Print_f (long long n)
// {
//     char buffer[sizeof(n) * 8 * 3 / 10 + 3];  // 3 digits per 10 bits + two extra and space for terminating zero.
//     int index = sizeof(buffer)-1;
//     int end = index;
//     buffer[index--] = 0;
//     do {
//        buffer[index--] = (n % 10) + '0';
//        n /= 10;
//     } while(n);
//     puts(&buffer[index+1]);
// }
vector<vector<ulint> > heights;
vector<ulint> indices;
vector<ulint> segTree;

void buildSegTree(ulint node, ulint lowB, ulint uppB)
{
	// cout<<"Node: "<<node<<" lowB: "<<lowB<<" uppB: "<<uppB<<endl;
	if(lowB == uppB)
	{
		segTree[node] = heights[lowB][0];
		// cout<<lowB<<" "<<uppB<<" val : "<<segTree[node]<<endl;
	}
	else
	{
		buildSegTree(2*node + 1, lowB, (lowB + uppB)/2);
		buildSegTree(2*node + 2, (lowB+uppB)/2 + 1, uppB);
		segTree[node] = max(segTree[2*node + 1], segTree[2*node + 2]);
	}
}

void updateSegTree(ulint node, ulint lowB, ulint uppB, ulint updateNode, ulint newVal)
{
	// cout<<"Node: "<<node<<" lowB: "<<lowB<<" uppB: "<<uppB<<" updateNode: "<<updateNode<<" newVal : "<<newVal<<endl;

	if(updateNode < lowB || updateNode > uppB)
		return;

	if(lowB == uppB)
	{
		segTree[node] = newVal;
		return;
	}

	updateSegTree(2*node + 1, lowB, (lowB + uppB)/2, updateNode, newVal);
	updateSegTree(2*node + 2, (lowB + uppB)/2 + 1, uppB, updateNode, newVal);

	segTree[node] = max(segTree[2*node + 1], segTree[2*node + 2]);	
}

lint queryTree(ulint node, ulint lowB, ulint uppB, ulint lowRange, ulint uppRange)
{
	// cout<<"Node: "<<node<<" lowB: "<<lowB<<" uppB: "<<uppB<<" lowRange: "<<lowRange<<" uppRange : "<<uppRange<<endl;

	if(lowB > uppB || lowB > uppRange || uppB < lowRange)
		return -1;

	if(lowRange <= lowB && uppRange >= uppB)
		return segTree[node];

	lint leftChild = queryTree(2*node + 1, lowB, (lowB + uppB)/2, lowRange, uppRange);
	lint rightChild = queryTree(2*node + 2, (lowB + uppB)/2 + 1, uppB, lowRange, uppRange);

	return max(leftChild, rightChild);
}

int main()
{
	ulint n=0, m=0, t=0, t2 = 0, t3 = 0, f=0;
	
	scanf("%llu", &n);//n = Scan_f();
	heights.resize(n);
	indices.resize(n, 0);
	segTree.resize((ulint)(pow(2, floor(log2(n)) + 2)) - 1, 0);	

	FOR(i, 0, n)
	{
		scanf("%llu", &t);//t = Scan_f();
		
		if(t == 0)
		{
			heights[i].push_back(0);
			continue;
		}

		ulint d = ceil(log10(t)), e=0;
		if(fabs(log10(t) - (float)d) < 0.001)
			d++;
		ulint base=lround(pow(10, d-1));
		bool nexZ=false;
		
		heights[i].push_back(t);
		// cout<<"Digits: "<<d<<" - "<<base<<" \t";
		FOR(j, 1, d)
		{
			if(nexZ)
			{
				nexZ = false;
				t *= 10;
			}
			else
			{
				e = t/base;
				// cout<<"e: "<<e;
				t %= base;
				// cout<<"  int t "<<t;
				t = (t*10) + e;
				// cout<<" fin t "<<t<<endl;
			}
			if(t/base == 0)
			{
				nexZ = true;
			}
			heights[i].push_back(t);
			// cout<<t<<"\t";
		}
		// cout<<endl;
	}

	buildSegTree(0, 0, n-1);

	// FOR(i, 0, segTree.size())
	// 	cout<<i<<" : "<<segTree[i]<<endl;
	scanf("%llu", &m);//m = Scan_f();
	
	while(m--)
	{
		scanf("%llu", &t);
		if(t)
		{
			scanf("%llu%llu", &t2, &t3);
			lint temp = queryTree(0, 0, n-1, t2, t3);
			printf("%lld\n", temp);
		}
		else
		{
			scanf("%llu%llu%llu", &t2, &t3, &f);
			if(f == 0)
				continue;
			FOR(i, t2, t3 + 1)
			{
				// cout<<"before : index of "<<i<<" is "<<indices[i]<<" at height "<<heights[i][indices[i]];

				indices[i] = (indices[i] + f) % (heights[i].size());
				// cout<<"after : index of "<<i<<" is "<<indices[i]<<" at height "<<heights[i][indices[i]];
				updateSegTree(0, 0, n-1, i, heights[i][indices[i]]);
				// FOR(j, 0, segTree.size())
				// {
				// 	cout<<"Node "<<j<<" : "<<segTree[j]<<endl;
				// }
				// cout<<"----------"<<endl;
			}
		}
	}

	return 0;
}
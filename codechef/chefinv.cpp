#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define ulint unsigned long long int
#define lint long long int
#define VI vector<int>
#define VLL vector<ulint>
#define VB vector<bool>
#define VVLL vector< VLL >
#define ci(i) cin>>i
#define co(i) cout<<i<<endl
#define FOR(i,j,n) for(lint i=j;i<n;i++)
#define pb push_back
#define s(v) v.size()
#define S(i) scanf("%d",&i)
#define SL(i) scanf("%lld",&i)
#define PL(i) printf("%lld\n",i)
#define P(i) printf("%d\n",i)
#define MOD 1000000007
#define gc getchar_unlocked

void scanint(ulint &x)
{
    register ulint c = gc();
    x = 0;
    ulint neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

//Fast Input for int
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

ulint mergeAndCount(VLL & input)
{
	if(s(input)==1)
		return 0;

	VLL left(s(input)/2), right(s(input)/2 + 1);
	copy(input.begin(), input.begin() + s(input)/2, left.begin());
	copy(input.begin() + s(input)/2, input.end(), right.begin());
	
	ulint lInv = mergeAndCount(left);
	ulint rInv = mergeAndCount(right);
	ulint lIndex=0, rIndex=0, invCount=0, curIndex=0;

	FOR(i, 0, s(input))
	{
		if(lIndex >= s(left))
		{
			input[curIndex++] = right[rIndex++];
		}
		else if(rIndex >= s(right))
		{
			input[curIndex++] = left[lIndex++];
		}
		else
		{
			input[curIndex++] = min(left[lIndex], right[rIndex]);

			if(input[curIndex] == right[rIndex])
			{
				rIndex++;
				invCount = s(left) - lIndex;
			}
			else
				lIndex++;
		}
	}

	return lInv+rInv+invCount;
}

int main()
{	
	ulint n=0, m=0;
	scanint(n), scanint(m);
	VLL input(n);
	
	FOR(i, 0, n)
		scanint(input[i]);

	FOR(k, 0, m)
	{
		ulint i, j;
		scanint(i), scanint(j);
		i--, j--;
		VLL temp(input);
		swap(temp[i], temp[j]);

		Print_f(mergeAndCount(temp));
	}
	
	return 0;
}
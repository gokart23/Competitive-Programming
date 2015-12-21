#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define ulint unsigned long long int
#define lint long long int
#define VI vector<int>
#define VLL vector<lint>
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
#define gc getchar
#define pc putchar
#define MAX 185

void scanint(lint &x)
{
    register lint c = gc();
    x = 0;
    lint neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
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

int main()
{
	lint t=0, n=0, m=0, b_ctr=0, cur_dist=0, cur_size=0;
	vector< vector<bool> > matrix(MAX);
	vector< vector<lint> > dist(MAX);
	queue< pair<int, int> > queue;
	pair<int, int> p;
	FOR(i, 0, MAX) FOR(j, 0, MAX) { matrix[i].pb(false); dist[i].pb(0); }
	scanint(t);
	while(t--)
	{
		assert(queue.empty());
		scanint(n), scanint(m);
		char tmp[m];		
		FOR(i, 0, n)
		{
			gets(tmp);
			FOR(j, 0, m)		
			{
			  if(tmp[j] == '0') matrix[i][j] = true; else matrix[i][j] = false;
			  if(matrix[i][j]) b_ctr++; else { queue.push(make_pair(i, j)); }
			}
		}
		while(b_ctr)
		{
			assert(!queue.empty());
			cur_size = s(queue);
			for(int i=0; i < cur_size; i++)
			{
				p = queue.front(); queue.pop();
				// cout<<"Currently on "<<p.first<<" "<<p.second<<" b_ctr "<<b_ctr<<endl;
				dist[p.first][p.second] = cur_dist;
				
				if(cur_dist)
					b_ctr--;
				if(p.first+1 < n && matrix[p.first+1][p.second])
					{ queue.push(make_pair(p.first+1, p.second)); matrix[p.first+1][p.second] = false; }
				if(p.second-1 >= 0 && matrix[p.first][p.second-1])
					{ queue.push(make_pair(p.first, p.second-1)); matrix[p.first][p.second-1] = false; }
				if(p.first-1 >= 0 && matrix[p.first-1][p.second])
					{ queue.push(make_pair(p.first-1, p.second)); matrix[p.first-1][p.second] = false; }
				if( p.second+1 < m && matrix[p.first][p.second+1])
					{ queue.push(make_pair(p.first, p.second+1)); matrix[p.first][p.second+1] = false; }
			}
			cur_dist++;
		}
		FOR(i, 0, n) {
			FOR(j, 0, m)
				printf("%lld ", dist[i][j]);
			pc('\n');
		}
		// for(;!queue.empty();queue.pop())
		// 	cout<<queue.front().first<<" "<<queue.front().second<<endl;
	}
	return 0;
}
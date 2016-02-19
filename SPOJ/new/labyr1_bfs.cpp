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
#define FORR(i,j,n) for(lint i=j;i>=n;i--)
#define pb push_back
#define s(v) v.size()
#define S(i) scanf("%d",&i)
#define SL(i) scanf("%lld",&i)
#define PL(i) printf("%lld\n",i)
#define P(i) printf("%d\n",i)
#define MAX 1005
#define DIR 4
#define gc getchar

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

inline bool is_valid(int x, int y, int r, int c)
{
	if(x >= 0 && x < r && y >= 0 && y < r)
		return true;
	return false;
}

int main()
{
	char ch;	
	lint t=0, res=0, r=0, c=0, tmp_x=0, tmp_y=0, tmp_l=0;
	const int x_dir[] = {-1, 1, 0, 0}, y_dir[] = {0, 0, -1, 1};
	char graph[MAX][MAX];
	queue<lint> bfs;
	scanint(t);
	while(t--)
	{
		tmp_x=0, res=0, tmp_y=0, tmp_l=0;
		scanint(c), scanint(r);
		FOR(i, 0, r) { FOR(j, 0, c) { graph[i][j]=gc(); if(graph[i][j] == '.') tmp_x=i, tmp_y=j;} gc(); }
		if(graph[tmp_x][tmp_y] == '.')
		{
			while(true)
			{
				bfs.push(c*tmp_x+tmp_y), bfs.push(0);
				while(!bfs.empty())
				{
					tmp_x = bfs.front()/c, tmp_y = bfs.front()%c; bfs.pop(); 
					tmp_l = bfs.front(); bfs.pop();
					graph[tmp_x][tmp_y] = 'x';
					FOR(k, 0, DIR)
						if(is_valid(tmp_x+x_dir[k], tmp_y+y_dir[k], r, c) && graph[tmp_x+x_dir[k]][tmp_y+y_dir[k]] == '.')
							bfs.push(c*(tmp_x+x_dir[k])+tmp_y+y_dir[k]), bfs.push(tmp_l+1);
				}
				bfs.push(c*tmp_x+tmp_y), bfs.push(0);
				while(!bfs.empty())
				{
					tmp_x = bfs.front()/c, tmp_y = bfs.front()%c; bfs.pop(); 
					tmp_l = bfs.front(); bfs.pop();
					graph[tmp_x][tmp_y] = '.';
					FOR(k, 0, DIR)
						if(is_valid(tmp_x+x_dir[k], tmp_y+y_dir[k], r, c) && graph[tmp_x+x_dir[k]][tmp_y+y_dir[k]] == 'x')
							bfs.push(c*(tmp_x+x_dir[k])+tmp_y+y_dir[k]), bfs.push(tmp_l+1);	
				}
				if(res <= tmp_l) break;
				else res = tmp_l;
			}
			// cout<<tmp_l<<" "<<tmp_x<<" "<<tmp_y<<endl;			
			// cout<<tmp_l<<" "<<tmp_x<<" "<<tmp_y<<endl;				
		}
		printf("Maximum rope length is %lld.\n", tmp_l);			

		//Augmented DFS -> missing corner cases :p

		// FOR(i, 0, r) { FOR(j, 0, c) { ch=gc(); if(ch == '.') graph[i][j] = -4; else graph[i][j] = -5; } gc(); }
		// stack<lint> dfs, len;
		// FOR(i, 0, r && !flag) FOR(j, 0, c && !flag)
		// {
		// 	// printf("Checking %lld %lld %lld\n", i, j, graph[i][j]);
		// 	if(graph[i][j] == -4)
		// 	{
		// 		flag = true;				
		// 		dfs.push(c*i+j), len.push(0);
		// 		while(!dfs.empty())
		// 		{
					// tmp_x = dfs.top()/c, tmp_y = dfs.top()%c, tmp_l = len.top();
		// 			// printf("Current is %lld %lld %lld %lld %lld %lld\n", dfs.top(), r, c, tmp_x, tmp_y, graph[tmp_x][tmp_y]);
		// 			dfs.pop(), len.pop();
		// 			if(graph[tmp_x][tmp_y] == -4)
		// 			{
		// 				graph[tmp_x][tmp_y] = -6;
		// 				dfs.push(c*tmp_x+tmp_y), len.push(-1);
		// 				FOR(k, 0, DIR)
		// 					if(is_valid(tmp_x+x_dir[k], tmp_y+y_dir[k], r, c) && graph[tmp_x+x_dir[k]][tmp_y+y_dir[k]] == -4)
		// 						dfs.push(c*(tmp_x+x_dir[k])+tmp_y+y_dir[k]), len.push(tmp_l+1);
		// 			}
		// 			else if(graph[tmp_x][tmp_y] == -6)
		// 			{
		// 				graph[tmp_x][tmp_y] = 1;
		// 				FOR(k, 0, DIR)
		// 				{	
		// 					if(is_valid(tmp_x+x_dir[k], tmp_y+y_dir[k], r, c) && graph[tmp_x+x_dir[k]][tmp_y+y_dir[k]] >= 0)
		// 					{
		// 						graph[tmp_x][tmp_y] = max(graph[tmp_x][tmp_y], graph[tmp_x+x_dir[k]][tmp_y+y_dir[k]]+1);
		// 						vec[k] = graph[tmp_x+x_dir[k]][tmp_y+y_dir[k]];
		// 					}
		// 					else vec[k] = 0;
		// 				}
		// 				sort(vec, vec+4);
		// 				// cout<<"vec: "<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<" "<<vec[3]<<endl;
		// 				res = max(res, vec[3] + vec[2]);
		// 				// printf("Res:%lld Setting %lld %lld to %lld\n", res, tmp_x, tmp_y, graph[tmp_x][tmp_y]);					
		// 			}
		// 			else assert(false);
		// 		}				
		// 	}
		// }
		// printf("Maximum rope length is %lld.\n", res);
	}

	return 0;
}
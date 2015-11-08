#include <bits/stdc++.h>

#define LEVELS 100

using namespace std;

const int NODES = (LEVELS * (LEVELS+1))>>1;

long long int dfs(vector< vector<int> >& graph, vector<int>& values)
{
	long long int max=0;
	vector<long long int> marked(NODES, 0);
	stack< pair<int, long long int> > dfs;
	dfs.push(make_pair(0,values[0]));
	while(!dfs.empty())
	{
		pair<int, long long int> top = dfs.top(); dfs.pop();
		cout<<"top is "<<top.first<<","<<top.second<<" max "<<max<<endl;
		if(max < top.second)
			{ max = top.second; } //cout<<"max going from "<<max<<" to "<<top.second<<endl;
		for(int i = 0; i < graph[top.first].size(); i++)
		{
			if(!marked[graph[top.first][i]] < (top.second + values[graph[top.first][i]]) )
			{
				marked[graph[top.first][i]] = top.second + values[graph[top.first][i]];
				dfs.push(make_pair(graph[top.first][i], top.second + values[graph[top.first][i]]));
			}
		}
	}
	return max;
}
double percent=0;
long long int rec(int n, vector<int>& values, vector< vector<int> >& graph)
{
	static vector<long long int> mark(NODES, -1);
	if(!graph[n].size())
		return values[n];
	long long int maxN = 0;
	for(int i = 0; i < graph[n].size(); i++)
	{
		if(mark[graph[n][i]] == -1)
		{
			percent++; 
			mark[graph[n][i]] = rec(graph[n][i], values, graph); 
			//cout<<graph[n][i]<<" done "<<mark[graph[n][i]]<<" "<<(percent/NODES)*100<<endl; 
		}
		maxN = max(maxN, mark[graph[n][i]]+values[n]);
	}
	return maxN;
}


int main(int argc, char const *argv[])
{
	int ctr=0;
	vector< vector<int> > graph(NODES);
	vector<int> values(NODES);

	queue<int> parent,child;
	for(int i = 0; i < LEVELS; i++)
	{
		int final = i + ctr;
		for(; ctr <= final; ctr++)
			{ cin>>values[ctr]; child.push(ctr); }
		if(!ctr)
			{ parent.push(0); child.pop(); }
		else
		{
			assert(parent.size()+1 == child.size());
			int parent_count = parent.size();
			for(int k = 0; k < parent_count; k++)
			{
				int top = parent.front(); parent.pop();
				graph[top].push_back(child.front());
				parent.push(child.front());	child.pop();
				graph[top].push_back(child.front());
			}
			parent.push(child.front()); child.pop();
			assert(!child.size());
		}		
	}
	//cout<<dfs(graph, values)<<endl;
	cout<<rec(0, values, graph)<<endl;
	// for(int i = 0; i < NODES; i++)
	// {
	// 	cout<<i<<": ";
	// 	for(int j = 0; j < graph[i].size(); j++)
	// 		cout<<graph[i][j]<<" ";
	// 	cout<<endl;
	// }
	return 0;
}
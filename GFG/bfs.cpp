#include <bits/stdc++.h>

using namespace std;

bool bfs(vector< vector<int> >& graph ,int s, int t)
{
	if(!graph.size())
		return false;
	bool visited[graph.size()];
	memset(visited, 0, sizeof(visited));
	queue<int> bfsQueue;	
	bfsQueue.push(s); visited[s] = true;
	while(!bfsQueue.empty())
	{
		int top=bfsQueue.front(); bfsQueue.pop();
		for(int i = 0; i < graph[top].size(); i++)
		{	
			if(graph[top][i] == t)
				return true;
			if(!visited[graph[top][i]])
			{ 
				bfsQueue.push(graph[top][i]);
				visited[graph[top][i]]=true; 
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	vector< vector<int> > graph(4);
	// for(int i = 0; i < 4; i++)
	// {	
	// 	vector<int> *a = new vector<int>;
	// 	graph.push_back(*a);
	// }
	graph[0].push_back(1); graph[0].push_back(2);
	graph[1].push_back(2);
	graph[2].push_back(0); graph[2].push_back(3);
	graph[3].push_back(3);	
	int s=0, t=3;
	cout<<bfs(graph, s, t)<<endl;	
	return 0;
}
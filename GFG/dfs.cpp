#include <bits/stdc++.h>

using namespace std;

void dfs(vector< vector<int> >& graph, int s, int t)
{
	if(!graph.size())
		return;
	vector<bool> marked(graph.size(), false);
	stack<int> stack;
	stack.push(s);
	while(!stack.empty())
	{
		int top=stack.top(), i=0; stack.pop();
		for(; i < graph[top].size(); i++)
		{
			if(!marked[graph[top][i]])
			{
				if((graph[top][i] == t))
					break;
				stack.push(graph[top][i]);
				marked[graph[top][i]] = true;
			}		
		}	
		if(i != graph[top].size())
		{
			cout<<"connected"<<endl;
			return;
		}
	}
	cout<<"not connected"<<endl;	
}

int main(int argc, char const *argv[])
{
	vector< vector<int> > graph(5);
	graph[0].push_back(1); graph[0].push_back(2);
	graph[1].push_back(3);
	graph[2].push_back(3);	
	dfs(graph, 0, 4);
	return 0;
}
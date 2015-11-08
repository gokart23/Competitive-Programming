#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

void topoSort(vector< vector<int> >& graph, stack<int>& sortStack, vector<bool>& visited, int idx)
{
	if(!graph.size() || idx >= graph.size())
		return;
	for(int i = 0; i < graph[idx].size(); i++)
		if(!visited[graph[idx][i]])
		{
			visited[graph[idx][i]] = true;
			topoSort(graph, sortStack, graph[idx][i]);
		}
	sortStack.push(idx);	
}

int main()
{	
	//Parse input
	stack<int> sortStack;
	vector<bool> visited(graph.size(), false);
	topoSort(graph, sortStack, visited, 0);
	while(!sortStack.empty)
	{
		cout<<sortStack.top()<<" ";
		sortStack.pop();		
	}
	cout<<endl;

	return 0;
}
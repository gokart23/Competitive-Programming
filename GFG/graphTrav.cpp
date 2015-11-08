#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool BFS(vector< vector<int> >& graph, int sourceIdx, int destIdx)
{
	if(!graph.size())
		return false;
	if(sourceIdx == destIdx)
		return true;
	queue<int> bfsQueue;
	vector<bool> visited(graph.size(), false);
	bfsQueue.push(sourceIdx);

	while(!bfsQueue.empty())
	{
		int top = bfsQueue.top();
		bfsQueue.pop();
		if(top == destIdx)
			return true;
		visited[top] = true;
		for(int i = 0; i < graph[top].size(); i++)
			if(!visited[graph[top][i]])
				bfsQueue.push(graph[top][i]);
	}

	return false;
}

void DFS(vector< vector<int> >& graph)
{
	if(!graph.size())
		return;
	vector<bool> visited(graph.size(), false);
	stack<int> dfsStack;

	for(int i = 0; i < graph.size(); i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			for(int j = 0; j < graph[i].size(); j++)
				if(!visited[graph[i][j]])
					dfsStack.push(graph[i][j]);
		}
	}
}

void topologicalSort(vector< vector<int> >& graph)
{
	if(!graph.size())
		return;
	stack<int> topoSort;
	vector<bool> visited(graph.size(), false);

	for(int i = 0; i < graph.size(); i++)
		if(!visited[i])
			performTopoSort(graph, visited, topoSort, i);
}

void performTopoSort(vector< vector<int> >& graph, vector<bool>& visited, stack<int>& topoSort, int nodeIdx)
{
	if(nodeIdx >= graph.size() || !graph.size())
		return;
	visited[nodeIdx] = true;
	for(int i = 0; i < graph[nodeIdx].size(); i++)
		if(!visited[graph[nodeIdx][i]])
			performTopoSort(graph, visited, topoSort, graph[nodeIdx][i]);
	topoSort.push(nodeIdx);
}

int main()
{
	//Parse graph
	//Call relevant functions

	return 0;
}
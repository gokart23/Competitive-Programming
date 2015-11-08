#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *left, *right;
	int val;
};

int numNodes(Node *root)
{
	if(!root)
		return 0;
	else
		return 1 + numNodes(root->left) + numNodes(root->right);
}

void distanceK(Node *root, int k)
{
	if(!root || !k)
		return;
	stack<Node*> dfsStack;
	deque<Node*> pathStack;	
	dfsStack.push(root);

	while(!dfsStack.empty())
	{
		cout<<"current path is ";
		for(int i = 0; i < pathStack.size(); i++)
			cout<<pathStack[i]->val<<" ";
		cout<<endl;

		Node *top = dfsStack.top(); dfsStack.pop();
		if(!top)
			continue;
		if(top->val < 0)
			{cout<<"\tremoving "<<pathStack.back()->val<<endl; pathStack.pop_back();}
		else
		{
			if(!top->left && !top->right)
			{
				if(pathStack.size() >= k)
					cout<<"\t\tprinting this one "<<pathStack[pathStack.size() - k]->val<<endl;
			}
			else
			{
				Node *n = new Node(); n->val = -1*top->val; n->left=NULL; n->right=NULL;
				dfsStack.push(n); pathStack.push_back(top);
				dfsStack.push(top->right); dfsStack.push(top->left);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Node p1, p2, p3, p4, p5, p6, p7, p8;
	p1.val = 1; p1.left = &p2; p1.right = &p3;
	p2.val = 2; p2.left = &p4; p2.right = &p5;
	p4.val = 4; p4.left = NULL; p4.right = NULL;
	p5.val = 5; p5.left = NULL; p5.right = NULL;
	p3.val = 3; p3.left = &p6; p3.right = &p7;
	p6.val = 6; p6.left = NULL; p6.right = &p8;
	p8.val = 8; p8.left = NULL; p8.right = NULL;
	p7.val = 7; p7.left = NULL; p7.right = NULL;
	distanceK(&p1, 1);
	return 0;
}
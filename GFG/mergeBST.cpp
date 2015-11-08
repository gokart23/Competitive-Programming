#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *left, *right;
	int val;
};

void inorder(Node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void mergeBST(Node *root1, Node *root2)
{
	if(!root1)
		inorder(root2);
	if(!root2)
		inorder(root1);

	stack<Node*> pathOne, pathTwo;
	Node *curOne = root1, *curTwo = root2;
	for(; curOne; pathOne.push(curOne), curOne=curOne->left);// cout<<curOne->val<<"p ";
	for(; curTwo; pathTwo.push(curTwo), curTwo=curTwo->left);// cout<<curTwo->val<<"q ";
	cout<<endl;
	Node *top;
	
	while(!pathOne.empty() && !pathTwo.empty())		
	{
		if(pathOne.top()->val < pathTwo.top()->val)
		{
			top = pathOne.top(); pathOne.pop();
			for(Node *t = top->right; t; pathOne.push(t), t=t->left);
		}
		else
		{
			top = pathTwo.top(); pathTwo.pop();
			for(Node *t = top->right; t; pathTwo.push(t), t=t->left);
		}
		cout<<top->val<<" ";
	}

	while(!pathOne.empty())
	{
		top = pathOne.top(); pathOne.pop();
		for(Node *t = top->right; t; pathOne.push(t), t=t->left);		
		cout<<top->val<<" ";
	}

	while(!pathTwo.empty())
	{
		top = pathTwo.top(); pathTwo.pop();
		for(Node *t = top->right; t; pathTwo.push(t), t=t->left);
		cout<<top->val<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node p1,p2,p3,p4,q1,q2,q3;
	p1.val = 8; p1.left=&p2; p1.right=&p3;
	p2.val = 2; p2.left=&p4;p2.right=NULL;	
	p3.val = 10; p3.left=NULL;p3.right=NULL;	
	p4.val = 1; p4.left=NULL;p4.right=NULL;	
	q1.val = 5; q1.left=&q2; q1.right=NULL;
	q2.val = 3; q2.left=&q3;q2.right=NULL;	
	q3.val = 0; q3.left=NULL;q3.right=NULL;	
	mergeBST(&p1, &q1);
	return 0;
}
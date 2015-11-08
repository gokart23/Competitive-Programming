#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int val;
	Node *left, *right;
};

int printKElem(Node *root, int k)
{
	if(!root)
		return -1;

	stack<Node*> inorderStack; int popped = 0;
	Node *current = root;
	for(;current; current = current->left)
		inorderStack.push(current);
	while(!inorderStack.empty())
	{
		current = inorderStack.top(); inorderStack.pop(); popped++;
		cout<<"current top "<<current->val<<" popped "<<popped<<endl;
		if(popped == k)
			return current->val;		
		
		current = current->right;
		for(;current; current = current->left)
			inorderStack.push(current);
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	Node p1, p2, p3, p4, p5;
	p1.val = 20; p1.left = &p2; p1.right = &p3;
	p2.val = 8; p2.left = &p4; p2.right = &p5;
	p3.val = 22; p3.left = NULL; p3.right = NULL;
	p4.val = 4; p4.left = NULL; p4.right = NULL;
	p5.val = 12; p5.left = NULL; p5.right = NULL;
	cout<<printKElem(&p1, 3);
	return 0;
}
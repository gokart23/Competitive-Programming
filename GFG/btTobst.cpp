#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int val;
	Node *left, *right;
};

void inorderTraversal(Node *root, vector<int>& array)
{
	if(!root)
		return;
	inorderTraversal(root->left, array);
	array.push_back(root->val);
	inorderTraversal(root->right, array);
}

void makeBST(Node *root)
{
	if(!root)
		return;
	vector<int> array;
	inorderTraversal(root, array);
	sort(array.begin(), array.end());

	stack<Node*> tree; int idx=0;
	for(Node *temp = root;temp;temp=temp->left)
		tree.push(temp);
	while(!tree.empty())
	{
		Node *top = tree.top(); tree.pop();
		top->val = array[idx++];
		for(top=top->right;top;top=top->right)
			tree.push(top);
	}	
}

int main(int argc, char const *argv[])
{
	Node p1, p2, p3, p4, p5;
	p1.val = 10; p1.left = &p2; p1.right = &p3;
	p2.val = 2; p2.left = &p4; p2.right = &p5 ;
	p3.val = 7; p3.left = NULL; p3.right = NULL;
	p4.val = 8; p4.left = NULL; p4.right = NULL;
	p5.val = 4; p5.left = NULL; p5.right = NULL;
	vector<int> array;
	makeBST(&p1);
	inorderTraversal(&p1, array);
	for(int i = 0; i < array.size(); i++)
		cout<<array[i]<<" ";
}
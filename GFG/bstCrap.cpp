#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node
{
	int val;
	Node *left, *right;
};

Node* search(Node *root, int key, Node **parent)
{
	if(!root)
		return NULL;
	if(root->val == key)
		return root;
	if(parent)
		*parent = root;
	if(root->val < key)
	{
		if(!root->right)	
			return root;
		else
			search(root->right, key, parent);
	}
	else
	{
		if(!root->left)
			return root;
		else
			search(root->left, key, parent);
	}
}

Node* insert(Node* root, int val)
{
	Node *n = new Node;
	n->val = val;
	n->left = NULL; n->right = NULL;
	Node *v = search(root, val, NULL);
	if(!v)
		return n;
	else if(v->val < val)
		v->right = n;
	else
		v->left = n;
	return root;
}

Node* successor(Node *root, int key)
{
	Node *parent, *val = search(root, key, &parent);
	if(!val)
		return NULL;	
	if(val->right)
	{
		Node *temp;
		for(temp = val->right; temp->left; temp = temp->left);
		return temp;
	}
	else
	{
		parent = NULL, val = root;
		while(val && val->val != key)
		{
			if(val->val < key)
				val = val->right;
			else
			{
				parent = val;
				val = val->left;
			}
		}
		return parent;
	}
}

Node* deleteNode(Node *root, int key)
{
	Node *parent, *val = search(root, key, &parent), *next=NULL;
	if(!val)
		return root;
	if(!val->left || !val->right)
		next = val->left ? val->left : val->right;	
	else if(val->left && val->right)
	{
		Node *succ, *succParent;
		for(succ=val->right, succParent=val; succ->left; succParent = succ, succ = succ->left);
		succParent->left = NULL;
		succ->left = val->left, succ->right = val->right;
		next = succ;			
	}
	if(val == root)
		return next;
	if(parent->val < key)
		parent->right = next;		
	else
		parent->left = next;		
	free(val);
	return root;
}

void inorder(Node *root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main()
{
	Node *h = insert(NULL, 10);
	insert(h, 20);
	insert(h, 5);
	insert(h, 15);
	insert(h, 35);
	insert(h, 40);
	insert(h, 17);
	inorder(h); cout<<endl;
	cout<<successor(h, 10)->val<<" ";
	cout<<successor(h, 5)->val<<endl;
	h = deleteNode(h, 17);	
	inorder(h); cout<<endl;
	h = deleteNode(h, 35);
	inorder(h); cout<<endl;
	h = deleteNode(h, 10);
	inorder(h); cout<<endl;
	return 0;
}
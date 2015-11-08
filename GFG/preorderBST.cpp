#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int val;
	Node *left, *right;
};

void inorder(Node *root)
{
	if(!root)
		return;
	inorder(root->left); cout<<root->val<<" "; inorder(root->right);
}

Node* preorderBST(int *preorder, int size, int* pIdx, int max, int min)
{
	if(!preorder || *pIdx >= size)
		return NULL;
	if(preorder[*pIdx] < max && preorder[*pIdx] > min)
	{
		Node *n = new Node; n->val = preorder[*pIdx]; (*pIdx)=*pIdx+1;
		Node *left = preorderBST(preorder, size, pIdx, n->val, min);
		Node *right = preorderBST(preorder, size, pIdx, max, n->val); 
		n->left = left; n->right = right;
		return n;
	}
	else
		return NULL;
}

Node* preorderBSTTwo(int *preorder, int size, int pMax, int pMin)
{
	if(pMin >= size || (pMin>=pMax))
		return NULL;
	Node *n = new Node; n->val = preorder[pMin]; 
	int i = 0;
	for(i = pMin; i < size && preorder[i]<=n->val; i++);
	Node *left = preorderBSTTwo(preorder, size, i, pMin+1);
	Node *right = preorderBSTTwo(preorder, size, pMax, i);
	n->left = left; n->right = right;
	return n;
}

Node* preorderBSTThree(int *preorder, int size)
{
	stack<Node*> treePath; int pIdx = 0;
	Node *root = new Node; root->val = preorder[pIdx++]; root->left = NULL; root->right = NULL;
	treePath.push(root);
	for(;pIdx<size;pIdx++)
	{
		cout<<"currently on "<<preorder[pIdx]<<endl;
		Node *n = new Node; n->val = preorder[pIdx];
		n->left = NULL; n->right = NULL;		
		if(treePath.top()->val > preorder[pIdx])
			treePath.top()->left = n;
		else
		{
			Node *t=treePath.top(), *tprev=NULL;
			for(;t && t->val<preorder[pIdx];tprev=t,treePath.pop(), t=treePath.top()) cout<<"\t\tremoving "<<treePath.top()->val<<endl;
			tprev->right = n;
			cout<<"\tadding to the right of "<<tprev->val<<endl;
		}
		treePath.push(n);		
	}
	// Node *t=root;
	// for(; t; t=t->right);
	// t->right = treePath.top();
	return root;
}

int main(int argc, char const *argv[])
{
	int array[] = {10,5,1,7,40,50}; int size=0;	
	// inorder(preorderBST(array, 6, &size, INT_MAX, INT_MIN));
	// inorder(preorderBSTTwo(array, 6, 6, 0));
	inorder(preorderBSTThree(array, 6));
	cout<<endl;
	return 0;
}
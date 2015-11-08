#include <bits/stdc++.h>
//In- and pre- order traversals of a tree are provided
using namespace std;

struct Node
{
	Node *left, *right;
	int val;
};

void printLevelOrder(Node *root)
{
	Node dhakkan; dhakkan.val = -1; dhakkan.left = NULL; dhakkan.right = NULL;
	queue<Node*> queue;
	queue.push(root);
	queue.push(&dhakkan);
	while(!queue.empty())
	{
		Node* top = queue.front(); queue.pop();
		// cout<<"!!"<<top<<" ";
		if(!top) { continue; }
		if(top->val == -1 ) { cout<<endl; if(!queue.empty()) queue.push(&dhakkan); continue; }
		cout<<top->val<<" ";
		queue.push(top->left), queue.push(top->right);
	}
}

int elSearch(int *array, int element, int aStart, int aEnd)
{
	for(int i = 0; i < (aEnd-aStart); i++)
		if(array[i+aStart] == element)
			return (i+aStart);
	return -1;
}

Node* createTree(int size, int *preorder, int *inorder, int pIndex, int iStart, int iEnd)
{
	if(!preorder || !inorder)
		return NULL;
	if(iStart >= iEnd)
		return NULL;
	cout<<"currently at "<<pIndex<<" with iStart/iEnd "<<iStart<<"/"<<iEnd<<endl;
	if(iEnd - iStart == 1)
	{
		cout<<"creating leaf node "<<inorder[iStart]<<endl;
		Node *n = new Node();
		n->val = inorder[iStart];
		n->left = NULL; n->right = NULL;
		return n;
	}

	int inPos = elSearch(inorder, preorder[pIndex], iStart, iEnd);
	if(inPos == -1)
		return NULL;
	cout<<"creating node "<<preorder[pIndex]<<endl;
	Node* m = new Node();
	m->val = preorder[pIndex];
	m->left = createTree(size, preorder, inorder, pIndex+1, iStart, inPos);
	if(inPos != iEnd-1)
	{
		int rPos = elSearch(preorder, inorder[inPos+1], 0, size);
		m->right = createTree(size, preorder, inorder, rPos, inPos+1, iEnd);
	}
	else
		m->right = NULL;
	return m;
}
int inorder[] = {4, 2, 5, 1, 3};
int preorder[] = {1, 2, 4, 5, 3};

int main(int argc, char const *argv[])
{
	Node r, p1, p2, p3, p4, p5;
	r.val = 1; p1.val = 2; p2.val = 3; p3.val = 4; p4.val = 5; p5.val = 6;
	r.left = &p1; r.right = &p2;
	p1.left = &p3; p1.right = NULL;
	p2.left = NULL; p2.right = &p4;
	p3.left = &p5; p3.right = NULL;
	p4.left = NULL; p4.right = NULL; p5.left = NULL; p5.right = NULL;	
	printLevelOrder(createTree(5, preorder, inorder, 0, 0, 5));
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct NodeLL
{
	int val;
	NodeLL *prev, *next;
};

struct NodeT
{
	int val;
	NodeT *left, *right;
};

void printDLL(NodeLL *head)
{
	if(!head)
		return;
	cout<<head->val<<"--";
	printDLL(head->next);
}

void bstToDll(NodeT* root, NodeLL** head, NodeLL** tail)
{
	if(!root)
		return;
	NodeLL *n = new NodeLL; n->val = root->val;
	n->prev = NULL; n->next = NULL;
	cout<<"currently on value "<<&n<<endl;
	if(root->left)
	{
		NodeLL **h, **t;
		bstToDll(root->left, h, t);
		cout<<"\tprev value is "<<(*h)<<endl;
		assert(root->val!=2);
		(*t)->next = n; n->prev = *t; head = h;
	}
	else
		head = &n;
	if(root->right)
	{
		NodeLL **h, **t;
		bstToDll(root->right, h, t);
		(*h)->prev = n; n->next = *h; tail = t;
		cout<<"\tnext value is "<<n->next->val<<endl;
	}
	else
		tail = &n;		
}

int main(int argc, char const *argv[])
{
	NodeT p1, p2, p3, p4, p5, p6;
	p1.val=11;p1.left=&p2;p1.right=&p3;
	p2.val=2;p2.left=&p4;p2.right=&p5;
	p3.val=29;p3.left=&p6;p3.right=NULL;
	p4.val=1;p4.left=NULL;p4.right=NULL;
	p5.val=7;p5.left=NULL;p5.right=NULL;
	p6.val=15;p6.left=NULL;p6.right=NULL;
	NodeLL **h, **t;
	bstToDll(&p1, h, t);	
	printDLL(*h);
	return 0;
}
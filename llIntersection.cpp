#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *next;
	int val;
};

int lengthOfList(Node *head)
{
	if(!head)
		return 0;	
	return 1 + lengthOfList(head->next);
}

Node* intersectionPt(Node *head1, Node *head2)
{
	if(!head1 || !head2)
		return NULL;
	int l1 = lengthOfList(head1), l2 = lengthOfList(head2), diff = abs(l1-l2);
	cout<<l1<<" "<<l2<<" "<<diff<<endl;
	Node *maxList = l1>l2?head1:head2, *minList = l1>l2?head2:head1;	
	if(diff)
		while(diff--)
			maxList = maxList->next;	
	for(;maxList && minList && maxList->val != minList->val;maxList=maxList->next, minList=minList->next);
	if(!head1 || !head2)
		return NULL;
	return maxList;
}

int main(int argc, char const *argv[])
{
	Node n1, n2, n3, m1, m2, m3;
	n1.val = 10; n1.next = &n2;
	n2.val = 20; n2.next = &n3;
	n3.val = 30; n3.next = NULL;
	m1.val = 40; m1.next = &m2;
	m2.val = 50; m2.next = &m3;
	m3.val = 60; m3.next = &n2;

	cout<<intersectionPt(&n1, &m1)->val<<endl;

	return 0;
}
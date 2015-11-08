#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int val;
	Node *next;
};

void printLL(Node *head)
{
	if(!head)
		return;
	cout<<head->val<<" ";
	printLL(head->next);
}

Node* combine(Node *headOne, Node *headTwo)
{
	Node *curOne=headOne, *curTwo=headTwo, *prev=NULL, *head=NULL;
	if(!headOne)
		return headTwo;
	if(!headTwo)
		return headOne;
	if(headOne->val < headTwo->val)
	{
		head = headOne; headOne = headOne->next;
	}
	else
	{
		head = headTwo; headTwo = headTwo->next;
		head->next = headOne;
	}
	prev = head; cout<<"head is "<<head->val<<endl;
	while(headTwo && headOne)
	{
		cout<<"headOne is "<<headOne->val<<" headTwo is "<<headTwo->val<<" prev is "<<prev->val<<endl;
		if(headOne->val < headTwo->val)
		{
			prev = headOne; headOne = headOne->next;
		}
		else
		{
			prev->next = headTwo; headTwo = headTwo->next;
			prev = prev->next;	prev->next = headOne;			
		}
	}	
	if(headTwo)
		prev->next = headTwo;
	return head;
}

Node* mergesortLL(Node *head)
{
	Node *slow=head, *fast=head;
	while(fast)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast)
			fast = fast->next;
	}
}

int main(int argc, char const *argv[])
{
	Node p1,p2,p3,p4;
	Node q1,q2,q3;
	p1.val=2; p1.next=&p2;
	p2.val=5; p2.next=&p3;
	p3.val=11; p3.next=&p4;
	p4.val=23; p4.next=NULL;
	q1.val=3; q1.next=&q2;
	q2.val=4; q2.next=&q3;	
	q3.val=19; q3.next=NULL;

	printLL(combine(&p1, &q1));
	cout<<endl;

	return 0;
}
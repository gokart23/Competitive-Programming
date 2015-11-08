#include <bits/stdc++.h>

using namespace std;

struct NodeLL
{
	int val;
	NodeLL *next;
};

NodeLL* split(NodeLL *head)
{
	NodeLL *slow=head, *fast=head->next;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;		
	}
	NodeLL *temp = slow->next;
	slow->next = NULL;
	return temp;
}

NodeLL* combine(NodeLL *headOne, NodeLL *headTwo)
{
	if(!headOne)
		return headTwo;
	if(!headTwo)
		return headOne;
	if(headOne->val < headTwo->val)
		{ headOne->next = combine(headOne->next, headTwo); return headOne; }
	else
		{ headTwo->next = combine(headOne, headTwo->next); return headTwo; }
}

NodeLL* mergeSort(NodeLL *head)
{
	if(!head || !(head->next))
		return head;
	NodeLL *second = split(head);
	NodeLL *head1=mergeSort(head);
	NodeLL *head2=mergeSort(second);
	return combine(head1, head2);
} 

void printList(NodeLL *head)
{
	NodeLL *temp = head;
	for(; temp; temp = temp->next)
		cout<<temp->val<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	NodeLL p1, p2, p3;
	NodeLL q1, q2, q3;
	p1.val = 5; p1.next = &p2;
	p2.val = 10; p2.next = &p3;
	p3.val = 15; p3.next = &q1;
	q1.val = 1; q1.next = &q2;
	q2.val = 7; q2.next = &q3;
	q3.val = 20; q3.next = NULL;

	printList(&p1);
	printList(mergeSort(&p1));

	return 0;
}
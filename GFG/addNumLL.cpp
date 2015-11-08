#include <bits/stdc++.h>

using namespace std;

struct NodeLL
{
	int val;
	NodeLL *next;
};

void printList(NodeLL *head)
{
	NodeLL *temp = head;
	for(; temp; temp = temp->next)
		cout<<temp->val<<" ";
	cout<<endl;
}

NodeLL* reverse(NodeLL *head)
{
	if(!head)
		return NULL;
	NodeLL *prev = NULL, *cur = head, *next = head->next;
	while(cur)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if(next)
			next = next->next;
	}
	return prev;
}

NodeLL* addNums(NodeLL *numOne, NodeLL *numTwo)
{
	if(!numOne)
		return numTwo;
	if(!numTwo)
		return numOne;
	NodeLL *curOne = reverse(numOne), *curTwo = reverse(numTwo);
	// printList(curOne); printList(curTwo);
	NodeLL *head = new NodeLL; head->val = 0; head->next = NULL;
	NodeLL *tail = head;
	int carry = 0;

	while(curOne && curTwo)
	{
		// cout<<curOne->val<<" "<<curTwo->val<<endl;
		int sum = carry + curOne->val + curTwo->val;
		carry = sum/10;
		sum %= 10;
		tail->next = new NodeLL;
		tail->next->val = sum;
		tail->next->next = NULL;
		tail = tail->next;
		curOne=curOne->next;
		curTwo=curTwo->next;
	}
	if(!curOne && !curTwo && carry)
	{
		tail->next = new NodeLL;
		tail->next->val = carry;
		tail->next->next = NULL;
		tail = tail->next;
	}
	else
	{
		int orgCarry=carry;
		while(curOne)
		{
			int sum = carry + curOne->val;
			carry = sum/10;
			sum %= 10;
			tail->next = new NodeLL;
			tail->next->val = sum;
			tail->next->next = NULL;
			tail = tail->next;
			curOne=curOne->next;
		}
		carry = orgCarry;
		while(curTwo)
		{
			int sum = carry + curTwo->val;
			carry = sum/10;
			sum %= 10;
			tail->next = new NodeLL;
			tail->next->val = sum;
			tail->next->next = NULL;
			tail = tail->next;
			curTwo=curTwo->next;	
		}
	}
	// printList(head);
	NodeLL *temp = head;
	head = head->next; temp->next = NULL;
	free(temp);
	return reverse(head);
}

int main(int argc, char const *argv[])
{
	NodeLL a1; NodeLL a2; NodeLL a3; NodeLL a4;
	NodeLL b1; NodeLL b2; NodeLL b3;
	a1.val=9;a2.val=9;a3.val=3;a4.val=9;
	b1.val=1;b2.val=2;b3.val=3;
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = NULL;
	b1.next = &b2; b2.next = &b3; b3.next = NULL;
	printList(addNums(&a1, &b1));
	return 0;
}
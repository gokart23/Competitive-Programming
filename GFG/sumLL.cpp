#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *next;
	int val;
};

int findLength(Node *head)
{
	Node *temp = head; int counter = 0;
	for(counter=0; temp != NULL; temp = temp->next, counter++);
	return counter;		
}

void printNumber(Node *head)
{
	Node *temp = head;
	for(;temp != NULL; temp = temp->next)
		cout<<temp->val<<" ";
	cout<<endl;
}

Node* reverseLL(Node *head)
{
	if(!head)
		return head;
	Node *current=head, *previous=NULL, *next=(head->next);
	while(current != NULL)
	{
		//cout<<"previous "<<previous<<" current "<<current->val<<" next "<<next<<endl;
		current->next = previous;
		previous = current;
		current = next;
		if(next)
			next = current->next;
	}
	return previous;
}

Node* findSum(Node *num1, Node *num2)
{
	if(num1 == NULL || num2 ==  NULL)
		return NULL;
	int lengthOne = findLength(num1), lengthTwo = findLength(num2), carry=0, tempSum=0;
	num1 = reverseLL(num1); num2 = reverseLL(num2);
	Node *adder = (lengthOne > lengthTwo ? num1 : num2), *adderPrev = NULL;
	Node *addend = (lengthOne > lengthTwo ? num2 : num1);
	Node *addendTail=addend, *adderTail = adder;
	while(addendTail)
	{
		tempSum = carry + (addendTail->val + adderTail->val); carry = tempSum/10; 
		cout<<adderTail->val<<" "<<addendTail->val<<" carry "<<carry<<" sum "<<tempSum<<endl;
		adderTail->val = tempSum%10;
		addendTail = addendTail->next; 
		adderPrev = adderTail; adderTail = adderTail->next;
	}	
	if(carry && adderTail)
	{
		if(adderTail->val != 9)
			adderTail->val += carry;
		else
		{
			adderPrev = adderPrev->next;
			Node *n = new Node();
			n->val = 1; n->next = NULL;
			adderPrev->val = 0;	adderPrev->next = n;			
		}
	}
	else if(carry && !adderTail)
	{
		Node *n = new Node();
		n->val = carry; n->next = NULL;
		adderPrev->next = n;
	}
	return reverseLL(adder);
}

int main(int argc, char const *argv[])
{
	Node a1; Node a2; Node a3;
	Node b1; Node b2; Node b3;
	a1.val=9;a2.val=9;a3.val=9;
	b1.val=9;b2.val=9;b3.val=9;
	a1.next = &a2; a2.next = &a3; a3.next = NULL;
	b1.next = &b2; b2.next = &b3; b3.next = NULL;
 	printNumber(findSum(&b1, &a1));
	return 0;
}
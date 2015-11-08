#include <bits/stdc++.h>

using namespace std;

class StackArray
{
private:
	int *array;
	int top, size;
public:
	StackArray(int size)
	{
		array = new int[size];
		for(int i = 0; i < size; i++)
			array[i] = 0;
		this->size = size;
		top = 0;
	}
	bool push(int item);
	bool pop();
	int peek(); 
};

bool StackArray::push(int item)
{
	if(top < size && top >= 0)
		array[top++] = item;
	else
		return false;
	// cout<<" top: "<<top<<" ";
	return true;
}

bool StackArray::pop()
{
	if(top > 0 && top <= size)
		top--;
	else
		return false;
	return true;
}

int StackArray::peek()
{
	// cout<<"peek top: "<<top<<" ";
	if(top > 0 && top <= size)
		return array[top-1];
	else
		return -1;
}

struct NodeLL
{
	int val;
	NodeLL *next;
};

class SingleLL
{
private:
	NodeLL *head=NULL;
public:
	void printLL();
	void printHead();
	void reverse();
	bool insert(int val);
	bool insertByPos(int pos, int val);
	bool deleteByPos(int pos);
	NodeLL* searchByPos(int pos);	
};

void SingleLL::printHead()
{
	if(head)
		cout<<"head: "<<head->val<<endl;
	else
		cout<<"head: NULL"<<endl;
}

void SingleLL::printLL()
{
	for(NodeLL *temp = head; temp; temp = temp->next)
		cout<<temp->val<<" ";
	cout<<endl;
}

void SingleLL::reverse()
{
	if(!head)
		return;
	NodeLL *prev = NULL, *cur = head, *next = head->next;
	while(cur)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if(next)
			next = next->next;
	}
	head = prev;	
}

bool SingleLL::insert(int val)
{
	if(!head)
		{ head = new NodeLL; head->val = val; head->next = NULL; return true; }
	NodeLL *temp = head;
	for(; temp->next; temp = temp->next);
	temp->next = new NodeLL;
	temp->next->val = val; temp->next->next = NULL;
	return true;
}

NodeLL* SingleLL::searchByPos(int pos)
{
	int ctr = 0;
	NodeLL *temp = head;
	for(; ctr < pos && temp; ctr++)
		temp = temp -> next;
	if(ctr != (pos))
		return NULL;
	return temp;
}

bool SingleLL::insertByPos(int pos, int val)
{
	NodeLL *temp = new NodeLL;
	temp->val = val; temp->next = NULL;
	if(pos == 1)
	{
		if(!head)
			head = temp;
		else
			{ temp->next = head; head = temp; }
	}
	else
	{
		NodeLL *prev = searchByPos(pos-1);		
		if(!prev)
			{ free(temp); return false; }
		temp->next = prev->next; prev->next = temp;
	}
	return true;
}

bool SingleLL::deleteByPos(int pos)
{
	if(pos == 1)
	{
		if(!head)
			return false;
		else
			{ NodeLL *temp = head; head = head->next; free(temp); }
	}
	else
	{
		NodeLL *prev = searchByPos(pos-1);
		if(!prev)
			return false;
		else
		{
			NodeLL *temp = prev->next;
			prev->next = temp->next;
			free(temp);
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	// StackArray stack(3);
	// cout<<stack.push(1)<<endl<<stack.push(2)<<endl<<stack.push(3)<<endl;
	// cout<<stack.push(4)<<endl;
	// cout<<stack.peek()<<endl; stack.pop();
	// cout<<stack.peek()<<endl; stack.pop();
	// cout<<stack.peek()<<endl; stack.pop();
	// cout<<stack.peek()<<" "<<stack.pop()<<endl;

	SingleLL ll;
	ll.printLL();
	ll.insertByPos(1, 1); ll.insertByPos(1, 2); ll.insertByPos(1, 3);
	ll.printLL();
	ll.deleteByPos(1); ll.deleteByPos(1);
	ll.printLL();
	ll.insert(2); ll.insert(3); ll.insertByPos(2, 4);
	ll.printLL();
	ll.insert(4); ll.deleteByPos(1); ll.deleteByPos(2); ll.deleteByPos(2); ll.insert(5); ll.insert(6);
	ll.printLL();
	ll.reverse();
	ll.printLL();

	return 0;
}
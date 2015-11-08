#include "iostream"

using namespace std;

class AdjListNode
{

private:
	int vNum=0;
	AdjListNode* next=NULL;

public:
	AdjListNode(int, AdjListNode*);
	int getVNum();
	void setNext(AdjListNode*);
	AdjListNode* getNext();
};

class AdjList
{

private:
	AdjListNode* head=NULL;
	int length=0;

public:
	AdjList(AdjListNode*);
	int getLength();
	AdjListNode* getHead();
	void addNode(AdjListNode*);
};

class Graph
{

private:
	int vertices=0;
	AdjList* adjList=NULL;

public:
	Graph(int vertices);
	~Graph();
	int getNumV();
	void addEdge(int src, int dest);
	void printGraph();
};

AdjListNode::AdjListNode(int vNum, AdjListNode* next)
{
	this->vNum = vNum;
	this->next = next;
}

int AdjListNode::getVNum()
{
	return this->vNum;
}

void AdjListNode::setNext(AdjListNode* next)
{
	this->next = next;
}

AdjListNode* AdjListNode::getNext()
{
	return this->next;
}

AdjList::AdjList(AdjListNode* head)
{
	this->head = head;
	this->length++;
}

int AdjList::getLength()
{
	return length;
}

AdjListNode* AdjList::getHead()
{
	return this->head;
}

void AdjList::addNode(AdjListNode* node)
{
	AdjListNode* temp=this->head;
	for (int i = 0; i < this->length; ++i)
	{
		temp = temp->getNext();
	}

	temp->setNext(node);
	this->length++;
}

Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adjList = new AdjList[vertices];

	for (int i = 0; i < vertices; ++i)
	{
		adjList[i] = new AdjList(new AdjListNode(i, NULL));
	}
}

Graph::~Graph()
{
	for (int i = 0; i < this->vertices; ++i)
		{
			delete adjList[i];
		}	
	delete [] adjList;
}

int Graph::getNumV()
{
	return this->vertices;
}

void Graph::addEdge(int src, int dest)
{
	AdjListNode* srcHead = this->adjList[src]->getHead();
	AdjListNode* destination = new AdjListNode(dest, srcHead->getNext());
	srcHead->setNext(destination);
}

void Graph::printGraph()
{
	for (int i = 0; i < this->vertices; ++i)
		{
			AdjListNode* head = this->adjList[i]->getHead();
			while(head->getNext() != NULL)
			{
				cout<<head->getVNum()<<" -> ";
			}
			cout<<endl;
		}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
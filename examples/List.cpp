#include "List.h"
using namespace std;

List::~List()
{
	Node* currNode = head, *nextNode = NULL;

	while (currNode != NULL)
	{
		nextNode = currNode->next;
		// destroy the current node
		delete currNode;	
		currNode = nextNode;
	}
}

Node* List::InsertNode(int index, double x)
{
	if (index < 0) return NULL;	
	
	int currIndex =	1;
	Node* currNode = head;

	while (currNode && index > currIndex)
	{
		currNode = currNode->next;
		currIndex++;
	}

	if (index > 0 && currNode == NULL) return NULL;
	
	Node* newNode =	new Node;
	newNode->data = x;	
	if (index == 0)
	{
		newNode->next =	head;
		head = newNode;
	}
	else
	{
		newNode->next =	currNode->next;
		currNode->next = newNode;
	}

	return newNode;
}

int List::FindNode(double x)
{
	Node* currNode = head;
	int currIndex = 1;

	while (currNode && currNode->data != x)
	{
		currNode = currNode->next;
		currIndex++;
	}

	if (currNode) return currIndex;

	return 0;
}

Node* List::ReturnNode(double x)
{
	Node* currNode = head;

	while (currNode && currNode->data != x)
	{
		currNode = currNode->next;
	}

	if (currNode) return currNode;

	return NULL;
}

int List::DeleteNode(double x)
{
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex =	1;

	while (currNode && currNode->data != x)
	{
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}

	if (currNode)
	{
		if (prevNode)
		{
			prevNode->next = currNode->next;
			delete currNode;
		}
		else
		{
			head = currNode->next;
			delete currNode;
		}

		return currIndex;
	}

	return 0;
}

void List::DisplayList()
{
	int num	= 0;
  	Node* currNode = head;
  	while (currNode != NULL)
	{
		cout << currNode->data << endl;
		currNode = currNode->next;
		num++;
	}

	cout << "Number of nodes in the list: " << num << endl;
}

void List::DisplayList(Node* item)
{
	int num	= 0;
  	Node* currNode = item;
  	while (currNode != NULL)
	{
		cout << currNode->data << endl;
		currNode = currNode->next;
		num++;
	}

	cout << "Number of nodes in the list: " << num << endl;
}

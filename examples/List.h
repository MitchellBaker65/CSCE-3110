#include "Node.h"
#include <iostream>

class List
{
	public:
		List() { head = NULL; }	// constructor
		~List();		// destructor

		bool IsEmpty() { return head == NULL; }
		Node* InsertNode(int index, double x);
		int FindNode(double x);
		Node* ReturnNode(double x);
		int DeleteNode(double x);
		void DisplayList();
		void DisplayList(Node* item); // new method
	private:
		Node* head;
};

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List list;

	list.InsertNode(0, 7.0);	// successful
	list.InsertNode(1, 5.0);	// successful
	list.InsertNode(1, 4.5);	// successful
	list.InsertNode(0, 6.0);	// successful
	list.InsertNode(2, 9.1);	// successful
	list.InsertNode(0, 2.9);	// successful
	list.InsertNode(1, 8.4);	// successful
	list.InsertNode(3, 7.1);	// successful
	list.InsertNode(4, 3.2);	// successful
	list.InsertNode(8, 4.0);	// successful

	// print all the elements
	list.DisplayList();

	cout << endl;

	Node* retNode = list.ReturnNode(3.2);
	list.DisplayList(retNode);

	return 0;
}

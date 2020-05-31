#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List list;

	list.InsertNode(0, 7.0);	// successful
	list.InsertNode(1, 5.0);	// successful
	list.InsertNode(-1, 5.0);	// unsuccessful
	list.InsertNode(0, 6.0);	// successful
	list.InsertNode(8, 4.0);	// unsuccessful

	// print all the elements
	list.DisplayList();

	if (list.FindNode(5.0) > 0)
		cout << "5.0 found" << endl;	
	else
		cout << "5.0 not found" << endl;

	if (list.FindNode(4.5) > 0)
		cout << "4.5 found" << endl;
	else
		cout << "4.5 not found" << endl;

	list.DeleteNode(7.0);
	list.DisplayList();

	return 0;
}

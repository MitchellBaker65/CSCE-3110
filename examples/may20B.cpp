#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers = {1,2,3,4,5};

	cout << "for loop:" << endl;
	for (vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); ++itr)
	{
		cout << *itr << endl;
	}

	cout << "while loop:" << endl;
	vector<int>::iterator itr = numbers.begin();

	itr++;
	itr++;
	numbers.insert(itr, 22);

	itr = numbers.end();
	--itr;
	--itr;
	numbers.erase(itr);

	itr = numbers.begin();
	while (itr != numbers.end())
	{
		cout << *itr << endl;
		itr++;
	}
	
}

#include <iostream>
using namespace std;

class IntCell
{
	public:
		explicit IntCell(int initialValue = 0)
		{
			storedValue = new int(initialValue);
			//cout << "storedValue=" << storedValue << endl;
		}

		~IntCell()
		{
			delete storedValue;
		}

		int read() const
		{
			return *storedValue;
		}

		void write(int x)
		{
			*storedValue = x;
		}

	private:
		int *storedValue;
};

int f()
{
/*	IntCell obj;
	obj = 37;

	cout << "obj=" << obj.read() << endl; */

	IntCell a(2);
	IntCell b = a;
	IntCell c;

	c = b;
	a.write(4);
	cout << a.read() << endl << b.read() << endl << c.read() << endl;

	return 0;
}

int main()
{
	f();

	return 0;
}

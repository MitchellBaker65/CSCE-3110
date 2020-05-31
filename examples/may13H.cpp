#include <iostream>
using namespace std;

class IntCell
{
	public:
		explicit IntCell(int initialValue = 0)
		{
			storedValue = new int(initialValue);
		}

		~IntCell()
		{
			delete storedValue;
		}

		IntCell(const IntCell & rhs) // copy constructor
		{
			storedValue = new int(*rhs.storedValue);
		}

		IntCell(IntCell && rhs) : storedValue(rhs.storedValue) // move constructor
		{
			rhs.storedValue = nullptr;
		}

		IntCell & operator= (const IntCell & rhs) // copy assignment
		{
			if (this != &rhs)
			{
				*storedValue = *rhs.storedValue;
			}

			return *this;
		}

		IntCell & operator= (IntCell && rhs) // move assignment
		{
			std::swap(storedValue, rhs.storedValue);
			return *this;
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
	obj = 37; */

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

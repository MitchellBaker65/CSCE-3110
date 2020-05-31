#include <iostream>
using namespace std;

long int f(long int x);

int main()
{
	long int x;

	cout << "Enter an integer: ";
	cin  >> x;

        cout << f(x) << endl;

        return 0;
}

long int f(long int x)
{
        if (x == 0)
        {
                return 0;
        }
	else if (x < 0)
	{
		cout << "Error: integer should be positive (" << x << ")" << endl;
		return x;
	}
        else
        {
                return 2 * f( x - 1) + x * x;
        }
}

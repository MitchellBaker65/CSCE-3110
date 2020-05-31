#include <iostream>
using namespace std;

int bad(int n);

int main()
{
	int n;

	cout << "Enter an integer: ";
	cin  >> n;

        cout << bad(n) << endl;

        return 0;
}

int bad(int n)
{
        if (n == 0)
        {
                return 0;
        }
        else
        {
                return bad(n/3 + 1) + n - 1;
        }
}

#include <iostream>
using namespace std;

long gcd(long m, long n);

int main()
{
	long m, n;

	cout << "Enter value for m: ";
	cin  >> m;

	cout << "Enter value for n: ";
	cin  >> n;

	long result = gcd(m, n);

	cout << "gcd of " << m << " and " << n << " is " << result << endl;

	return 0;
}

long gcd(long m, long n)
{
	cout << "gcd: ";

	while (n != 0)
	{
		long rem = m % n;
		m = n;
		n = rem;
		cout << n << " ";
	}

	cout << endl;

	return m;
}

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

timespec diff(timespec start, timespec end);

int main()
{
	const int SIZE = 100000;
	int X[SIZE], A[SIZE];
	timespec tS, tE, tC;	// start, end, calculated times

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		X[i] = rand() % 100;
		A[i] = 0;
	}

/*	for (int i = 0; i < SIZE; i++)
	{
		cout << X[i] << " ";
	}

	cout << endl; */

	// Solution 1
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tS);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			A[i] += X[j];
		}

		A[i] /= (i+1);
	}

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tE);

	tC = diff(tS, tE);

/*	for (int i = 0; i < SIZE; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl; */

	cout << "Solution 1 Running Time: " << tC.tv_sec << " seconds " << tC.tv_nsec << " nanoseconds" << endl;

	// Solution 2
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tS);

	for (int i = 0; i < SIZE; i++)
	{
		if (i == 0)
                {
                        A[i] = X[i];
                }
                else
                {
                        A[i] = X[i] + A[i-1];
                }

		A[i] /= (i+1);
	}

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tE);

	tC = diff(tS, tE);

	cout << "Solution 2 Running Time: " << tC.tv_sec << " seconds " << tC.tv_nsec << " nanoseconds" << endl;

	return 0;
}

timespec diff(timespec start, timespec end)
{
        timespec temp;

        if ((end.tv_nsec-start.tv_nsec) < 0)
        {
            temp.tv_sec = end.tv_sec-start.tv_sec-1;
            temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
        }
        else
        {
            temp.tv_sec = end.tv_sec-start.tv_sec;
            temp.tv_nsec = end.tv_nsec-start.tv_nsec;
        }

        return temp;
}

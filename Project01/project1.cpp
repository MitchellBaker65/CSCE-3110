/*
Name: Mitchell Baker
Date: 05/20/2020
Course: CSCE 3110.021
Description:

*/

#include <iostream>
#include <ctime>
#include <cstdlib>

// function provided by Dr.Thompson for calculating the time a 
// section of code takes to run
timespec diff(timespec start, timespec end)
{
    timespec temp;	// holds the temporary values for calculating the time

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

// takes two integers and multiplies them via addition, returns the product
int multiply(int operand1, int operand2) {
    
    int multiplier = (operand1 < operand2) ? operand1 : operand2;	// assigns the operand with the smaller value to the multiplier
    int multiplicand = (operand1 > operand2) ? operand1 : operand2;	// assigns the operand with the larger value to the multiplicand

    int product = 0;	// intilizing the product (sum)

	// iterates for size of the multiplier and sums the multiplicand
    for(int i = 0; i <multiplier; i++) {
    	product += multiplicand;
    }

    return product;
}

// takes two integers and multiplies them via addition and bit shift, returns the product
int bitMultiply(int operand1, int operand2) {

    int multiplier = (operand1 < operand2) ? operand1 : operand2;	// assigns the operand with the smaller value to the multiplier
    int multiplicand = (operand1 > operand2) ? operand1 : operand2;	// assigns the operand with the larger value to the multiplicand

    int product = 0;	// intilizing the product (sum)

	// for every bit in the multiplicand, checks if the LSB is 1 or 0
	// if 1, adds the multiplier to the product.
	// for each iteration, it is LHS the multiplicand until it runs out of bits
	// and it is RHS the multiplier each iteration
	for(int iteration = multiplier; iteration > 0; iteration = iteration>>1) {
		if(iteration & 1) product += multiplicand;
		multiplicand = multiplicand << 1;
	}

	return product;
}

int main(int argc, char **argv){

    const int SIZE = 10;    // times calculations will loop
	timespec tS, tE, tC;	// start, end, calculated times
    int operand1,operand2;	// values given by the user
	int product;			// integer to hold the return of multiply() and bitMultiply()
	double averageSeconds = 0;				// holds average seconds for the solution
	double averageNanoseconds = 0;			// holds average nanoseconds for the solution
	int sumSeconds = 0;						// holds the sum of seconds for all passes
	long sumNanoseconds = 0;				// holds the sum of nanoseconds for all passes
    long long int testProduct;				// integer to check if product leads to integer overflow 

	// asks user for operand1 and operand2, keeps prompting if either is a non-positive integer
    do{
       	std::cout << "Enter first positive integer: ";
        std::cin >> operand1;
    }while(operand1 <= 0);
    
    do{
        std::cout << "Enter second positive integer: ";
        std::cin >> operand2;
    }while(operand2 <= 0);

	// checks for integer overflow, if so, exits the program
    if( static_cast<long long int>(operand1) != static_cast<long long int>((testProduct = operand1 * operand2) / operand2) ) {
        std::cout << "Error: Product results in integer overflow." << std::endl;
        exit(0);
	}

	// solution using only addition
	
    std::cout << "Multiplication using only ADDITION:" << std::endl;
	
	// runs for the const int SIZE, calculates the product, time required to calculate the product
	// then outputs to the user
	// also records a sum of the time took for each iteration then outputs the average time to the user
    for(int i = 1; i <= SIZE; i++) {
		
		// accesses the cpu clock and stores it in tS then after the function is called
		// accesses the cpu clock and stores it in tE, then the difference of the times
		// is stored in tC. This gives us the total time it took for the function to run.
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tS);
		product = multiply(operand1, operand2);	
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tE);
		tC = diff(tS, tE);

		// sums up the seconds and nanoseconds for each run
		sumSeconds += tC.tv_sec;
		sumNanoseconds +=tC.tv_nsec;

		// outputs to the user the data for each pass
    	std::cout << "Product: " << product << std::endl;
    	std::cout << "Pass " << i << ": "<< tC.tv_sec << " seconds " << tC.tv_nsec << " nanoseconds" << std::endl;
    }

	
	averageSeconds = sumSeconds/SIZE;
	
	// static cast sumNanoseconds to have a float type stored in averageNanoseconds
	averageNanoseconds = static_cast<float>(sumNanoseconds)/SIZE;

	std::cout << "Average: "<< averageSeconds << " seconds " << averageNanoseconds << " nanoseconds" << std::endl;
	
	// solution using addition and bit shifts
	
    std::cout << "Multiplication using only ADDITION and bit SHIFTS:" << std::endl;
	
	averageSeconds = 0;
	averageNanoseconds = 0;
	sumSeconds = 0;
	sumNanoseconds = 0;

	// runs for the const int SIZE, calculates the product, time required to calculate the product
	// then outputs to the user
	// also records a sum of the time took for each iteration then outputs the average time to the user
    for(int i = 1; i <= SIZE; i++) {
		
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tS);
		product = bitMultiply(operand1, operand2);	
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tE);
		tC = diff(tS, tE);

		sumSeconds += tC.tv_sec;
		sumNanoseconds += +tC.tv_nsec;

    	std::cout << "Product: " << product << std::endl;
    	std::cout << "Pass " << i << ": "<< tC.tv_sec << " seconds " << tC.tv_nsec << " nanoseconds" << std::endl;
    }

	averageSeconds = sumSeconds/SIZE;
	
	averageNanoseconds = static_cast<float>(sumNanoseconds)/SIZE;
	
	std::cout << "Average: "<< averageSeconds << " seconds " << averageNanoseconds << " nanoseconds" << std::endl;
	
	
    return 0;
}








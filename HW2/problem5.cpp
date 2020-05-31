// Name: Mitchell Baker

#include <iostream>

int main(){

    int N;  // variable to hold the size N
    
    int sumOfArray = 0; // holds sum of array A
    int sumOfN = 0;     // holds the sum of numbers 1 through N
    
    std::cout << "Enter size of N: ";
    std::cin >> N;

    int array[N-1];

    std::cout << "Enter the numbers: ";
  
    // asks user for number and then adds it to the sum
    for(int i = 0; i < N-1; i++) {
        std::cin >> array[i];
        sumOfArray += array[i];
    }

    // sums the numbers 1 through N
    for(int i = 1; i <= N; i++){
        sumOfN +=i;
    }

    // calculates the difference of sum of N and the sum of the array which will
    // be the missing number
    int differenceOfArrayAndN = sumOfN - sumOfArray;

    std::cout << "The missing number is " << differenceOfArrayAndN << "." << std::endl;

    return 0;
}
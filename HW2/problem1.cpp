// Name: Mitchell Baker

#include <iostream>
#include <string.h>

int main(){

    // creates a string for the user to input
    std::string stringToCheck;

    // prompts user for input string
    std::cout << "Enter a string: ";
    std::cin >> stringToCheck;

    // store the length of the user given string to be used
    // in the check for 'Y' and to assign the value of N
    int stringToCheckLength = stringToCheck.length();

    // checks that 'Y' is in the middle of the string
    if(stringToCheck.at(stringToCheckLength/2) != 'Y') exit(0);

    // assigns the size of the string to N and subracts one
    // to give the index of the last char in the string
    int N = stringToCheckLength - 1;

    // iterates through the first and last half of the string at the same time
    // and compares eached mirriored index to see if they are not the same.
    // If they are not the same, prints that it is not a correct string and exits. 
    for(int i = 0; i < N-1; i++, N--){
        if(stringToCheck.at(N) != stringToCheck.at(i)) {
            std::cout <<"String is not if the form xYz." << std::endl;
            exit(0);
        }
    }

    // getting here means that the string was a palidrone and prints that the string
    // is in the correct form.
    std::cout << "String is in form xYz." << std::endl;

    return 0;
}
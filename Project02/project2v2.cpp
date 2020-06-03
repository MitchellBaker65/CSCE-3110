/*
Name: Mitchell Baker
Date: 05/31/2020
Course: CSCE 3110.021
Description: A program that converts an expression from infix to postfix then evaluates the expression.
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <stdlib.h>

int main(int argc, char **argv){

    std::string userInputString;                    // holds the infix expression give by the user 
    char* userInputPointer;                         // pointer to hold the user input for breaking the string up
    std::vector<std::string> userInputVectorOfCharacters;  // holds the user input broken up into characters
    std::stack<std::string> stackOfOperators;              // stack to hold the operators during transfer 
                                                    // from infix to posfix and to evaluate the expression
    std::queue<std::string> queueOfOperandsAndOperators;   // queue to hold the posfix equivalent expression
    std::queue<std::string> queueOfOperandsAndOperatorsForCalculation; // holds the copy of the postfix so an evaluation can be calculated.
    std::stack<float> stackOfPostfixEvaluation;     // stack to evaluate the generated postfix expression 
    int userInputStringLength;                      // holds the length of the string of the user input
    float tempPostfixNumber;                        // holds the value of the convertion from char to float
    float firstNumber;                              // holds the value of the second number popped off the stack
    float secondNumber;                             // holds the value of the first number popped off the stack
    int numOfParenthesizes = 0;
    

    // asks and stores user input
    std::cout << "Enter a valid infix expression: ";
    std::getline(std::cin, userInputString);

    // creates a cstring with size of the user input + 1 so to have a NULL terminated character array
    userInputStringLength = userInputString.length();
    char userInputCharArray[userInputStringLength+1];

    // stores the user string into the c string
    strcpy(userInputCharArray, userInputString.c_str()); 

    // initializes the pointer with the first token
    userInputPointer = strtok(userInputCharArray," ");

    // iterates through the c string, breaking up each piece seperated by a " " and
    // stores it in the character vector
    while(userInputPointer != NULL){
        std::string temp(userInputPointer);
        userInputVectorOfCharacters.push_back(temp);
        if(*userInputPointer == '(' || *userInputPointer == ')') numOfParenthesizes++;
        userInputPointer = strtok(NULL, " ");
    }

    // if the number of parentheses are odd, outputs that the parentheses are mismatched then terminates
    if(numOfParenthesizes%2 != 0) {
        std::cout << "Error: Mismatched Parentheses! Program Terminated." << std::endl;
        exit(1);
    }

    // iterates throught the vector containing the tokens
    // while the token has yet to be pushed to the queue, checks if:
    /* 1. it is an operator, then:
            a. if it is an exponent
                push the operand onto the stack
            b. if it is a multiplicative followed by an additive
                push the operand onto the stack
            c. if it is an open parenthesis
                push the operand onto the stack
            d. if it is a closed parenthesis:
                i. pop all operators off the stack and onto the queue until reaching the open parenthesis
        2. it is an operand, then:
            push the operand onto the queue
    */
    for(std::string c: userInputVectorOfCharacters){
        bool operatorNotPushed = true;
        do {
            if(c.length() == 1 && (c == "+" || c == "-" || c == "/" || c == "*" || c == "(" || c == ")"|| c == "%"|| c == "^")) {
                if(stackOfOperators.empty()) {
                    stackOfOperators.push(c);
                    operatorNotPushed = false;
                }
                else if(c == "^"){
                    stackOfOperators.push(c);
                    operatorNotPushed = false;
                }
                else if((c == "/" || c == "*" || c == "%")  && (stackOfOperators.top() == "-" || stackOfOperators.top() == "+")) {
                    stackOfOperators.push(c);
                    operatorNotPushed = false;
                }
                else if (stackOfOperators.top() == "(" || c == "(" ){
                    stackOfOperators.push(c);
                    operatorNotPushed = false;
                }
                else if(c == ")"){  
                    while(stackOfOperators.top() != "("){
                        std::string temp = stackOfOperators.top();
                        stackOfOperators.pop();
                        queueOfOperandsAndOperators.push(temp);
                    }
                    stackOfOperators.pop();
                    operatorNotPushed = false;
                }
                else {
                    std::string temp = stackOfOperators.top();
                    stackOfOperators.pop();
                    queueOfOperandsAndOperators.push(temp);
                    operatorNotPushed = true;
                }
            }
            else {
                queueOfOperandsAndOperators.push(c);
                operatorNotPushed = false;
            }
        }while(operatorNotPushed);
    }

    // removes the last operand that is leftover on the stack 
    while(!stackOfOperators.empty()){
        std::string temp = stackOfOperators.top();
        queueOfOperandsAndOperators.push(temp);
        stackOfOperators.pop();
    }

    // prints out the queue containing the the postfix expression and copies the queue
    // so the expression can be evaluated 
    std::cout << "The resulting postfix expression: ";
    while(!queueOfOperandsAndOperators.empty()) {
        std::string temp = queueOfOperandsAndOperators.front();
        std::cout << queueOfOperandsAndOperators.front();
        queueOfOperandsAndOperatorsForCalculation.push(temp);
        queueOfOperandsAndOperators.pop();
    }
    std::cout << std::endl;

    // steps throught the queue and if:
    /*  1. if it isn't an operand, push onto the queue
        2. if it is an operand, takes the top two numbers
            from the stack and then does the aproperate 
            calculation based on what operand in the queue it
            is at. 
    */
    while(!queueOfOperandsAndOperatorsForCalculation.empty()) {
        std::string temp = queueOfOperandsAndOperatorsForCalculation.front();
        queueOfOperandsAndOperatorsForCalculation.pop();
        
        tempPostfixNumber = std::atof(temp.c_str());

        if(temp != "^" && temp != "%" && temp != "/" && temp != "*" && temp != "-" && temp != "+"){
            stackOfPostfixEvaluation.push(tempPostfixNumber);
        }
        else{
                secondNumber = stackOfPostfixEvaluation.top();
                stackOfPostfixEvaluation.pop();
                firstNumber = stackOfPostfixEvaluation.top();
                stackOfPostfixEvaluation.pop();
                if(temp == "^") {
                    stackOfPostfixEvaluation.push(pow(firstNumber, secondNumber));
                }
                if(temp == "%") {
                    stackOfPostfixEvaluation.push(int(firstNumber) % int(secondNumber));
                }
                if(temp == "/") {
                    stackOfPostfixEvaluation.push(firstNumber / secondNumber);
                }
                if(temp == "*") {
                    stackOfPostfixEvaluation.push(firstNumber * secondNumber);
                }
                if(temp == "-") {
                    stackOfPostfixEvaluation.push(firstNumber - secondNumber);
                }
                if(temp == "+") {
                    stackOfPostfixEvaluation.push(firstNumber + secondNumber);
                }
        }
    }

    std::cout << "The result is: "<< stackOfPostfixEvaluation.top() << std::endl;

    return 0;
}
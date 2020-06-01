#include <iostream>
#include <sstream>
#include <cmath>

int main(){

    std::stringstream ss;

    char a = '2';
    char c = '6';
    float d = 2;
    float b = 6;

    ss << a;
    ss >> b;
    ss.clear();
    
    ss << c;
    ss >> d;

    float that = d / b;

    std::cout << that << std::endl;

    return 0;
}
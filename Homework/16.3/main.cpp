#include "Functions.h"
#include "JacobCommon.h"
#include <iostream>

const int numOne = 5;
const int numTwo = 15;
const double bigNumOne = 10.00;
const double bigNumTwo = 15.00;
const size_t unsignedNumOne = 1;
const size_t unsignedNumTwo = 2;

int main()
{

    std::cout << maximun(numOne, numTwo) << " is the bigger of " << numOne << " and " << numTwo << "\n";
    std::cout << maximun(bigNumOne, bigNumTwo) << " is the bigger of " << bigNumOne << " and " << bigNumTwo << "\n";
    std::cout << maximun(unsignedNumOne, unsignedNumTwo) << " is the bigger of " << unsignedNumOne << " and " << unsignedNumTwo << "\n";

    std::cout << minimum(numOne, numTwo) << " is the smaller between " << numOne << " and " << numTwo << "\n";
    std::cout << minimum(bigNumOne, bigNumTwo) << " is the smalelr between " << bigNumOne << " and " << bigNumTwo << "\n";
    std::cout << minimum(unsignedNumOne, unsignedNumTwo) << " is the smaller between " << unsignedNumOne << " and " << unsignedNumTwo << "\n";

    double userInput = getValidUserInput(userInput, "Hello", "Enter a number: ", 0, 1);

    std::cout << userInput;

    return 0;
}
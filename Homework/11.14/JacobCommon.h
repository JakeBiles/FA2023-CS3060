#pragma once
#include <string>

/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T>
void getUserInput(T* userSelection, const std::string queryLine) {

	std::cout << std::endl;
	std::cout << queryLine;
	std::cin >> *userSelection;
	system("cls");
	std::cin.ignore();

}

/* Get User Input
* Handles a generic input and ensures its within a valid region
* == INPUTS ==
* Type T (generic) userInput -- variable taking input
* const T inclusiveMax -- The max range of the input
* const T inclusiveMin -- The min range of the input
* cont string header -- The prompt being asked
* const string query -- The line - entry
* const string error -- The error if invalid input
*/
template <typename T>
void ensureValidInput(T* userInput, const T inclusiveMax, const T inclusiveMin, const std::string header, const std::string query, const std::string error) {

	bool isValid = false;

	do {

		std::cout << header;
		getUserInput(userInput, query);

		if (*userInput > inclusiveMax || *userInput < inclusiveMin) { std::cout << *userInput << error << std::endl; }
		else {

			isValid = true;

		}

	} while (!isValid);

}



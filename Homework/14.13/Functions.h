#pragma once
#include <iostream>
#include <string>

/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T> T getUserInput(T& userEntry, const std::string queryLine) {

	bool isValid = false;

	do {

		std::cout << queryLine;

		if (!(std::cin >> userEntry)) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			std::cout << "Error with entry!" << std::endl;
		}

		else {
			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			isValid = true;
		}

	} while (!isValid);

	return userEntry;

}
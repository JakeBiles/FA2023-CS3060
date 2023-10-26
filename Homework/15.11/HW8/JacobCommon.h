#pragma once
#include <iostream>
#include <limits>

/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T> T getUserInput(T& userEntry, const char* queryLine) {

	do {

		std::cout << std::endl << queryLine;

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
			return userEntry;
		}

	} while (true);

}

/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T> T getValidUserInput(T& userEntry, const char* header, const char* queryLine, T iMax, T iMin) {

	bool isValid = false;

	do {

		std::cout << header << "\n";

		do {

			std::cout << "\n" << queryLine;

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

		isValid = false;

		if (userEntry > iMax || userEntry < iMin) std::cout << "Out of range [" << iMax << "-" << iMin << "]\n";
		else return userEntry;

	} while (true);


}


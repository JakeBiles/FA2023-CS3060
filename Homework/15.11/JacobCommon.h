#pragma once
#include <iostream>
#include <limits>

/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T> T getUserInput(T& userEntry, const char* header, const char* queryLine) {

	do {

		std::cout << header << "\n";
		std::cout << "\n" << queryLine;

		if (!(std::cin >> userEntry)) {

			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			std::cout << "Error with previous entry\n";

		}

		else {

			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			return userEntry;

		}

	} while (true);

}

/* Get Valid User Input
* Uses the Get Uers Input Method to get a requested input within a range
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
* const char* header -- The header portion of the prompt (Above Input Line)
* const char* queryLine -- The question being asked (on input line)
* T iMax -- The inclusive max range
* T iMin -- The inclusive min range
* == OUTPUTS ==
* T -- The userEntry varaible
*/
template <typename T> T getValidUserInput(T& userEntry, const char* header, const char* queryLine, T iMax, T iMin) {

	do {

		getUserInput(userEntry, header, queryLine);
		if (userEntry > iMax || userEntry < iMin) std::cout << "Out of range [" << iMax << "-" << iMin << "]\n";
		else return userEntry;

	} while (true);


}


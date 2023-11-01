#pragma once
#include <iostream>
#include <limits>

/* Get User Input
 * Gets a user Input, ensures fits the input type -- cleans buffer -- Repeats untill valid type
 * == INPUTS ==
 * Type T (generic) userSelection -- variable taking input
 * const char* header -- The header portion of the prompt (Above Input Line)
 * const char* queryLine -- The question being asked (on input line)
 */
template <typename T>
T getUserInput(T &userEntry, const char *header, const char *queryLine)
{

	do
	{

		std::cout << header << "\n";
		std::cout << "\n"
				  << queryLine;

		if (!(std::cin >> userEntry))
		{

			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			std::cout << "Error with previous entry\n";
		}

		else
		{

			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			return userEntry;
		}

	} while (true);
}

/* Get Valid User Input
 * Uses the Get Uers Input Method to get a requested input within a range -- repeats untill valid
 * == INPUTS ==
 * Type T (generic) userSelection -- variable taking input
 * const char* header -- The header portion of the prompt (Above Input Line)
 * const char* queryLine -- The question being asked (on input line)
 * T iMax -- The inclusive max range
 * T iMin -- The inclusive min range
 * == OUTPUTS ==
 * T -- The userEntry varaible
 */
template <typename T, typename D>
T getValidUserInput(T &userEntry, const char *header, const char *queryLine, D iMin, D iMax)
{

	do
	{

		getUserInput(userEntry, header, queryLine);

		if (userEntry <= iMax && userEntry >= iMin)
			return userEntry;

		std::cout << "Out of range [" << iMin << "-" << iMax << "]\n";

	} while (true);
}

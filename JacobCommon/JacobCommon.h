#ifndef JCommon
#define JCommon

template <typename T>
size_t findArraySize(T* someArray) {

	return (sizeof(*someArray) / sizeof(*someArray[0]));

}

#endif // !JCommon

#ifndef JCInput
#define JCINPUT
#include <iostream>
#include <iomanip>
#include <string>

/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T> void getUserInput(T* userEntry, const std::string queryLine, const size_t valueLimiter) {

	bool isValid = false;

	do {

		std::cout << std::endl << queryLine;

		if (!(std::cin >> *userEntry)) {
			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			std::cout << "Error with entry!" << std::endl;
		}

		else {
			T temp = *userEntry;
			system("cls");
			std::cin.clear();
			std::cin.ignore(BUFSIZ, '\n');
			isValid = true;
		}

	} while (!isValid);

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
template <typename T> void ensureValidInput(T* userInput, const T inclusiveMax, const T inclusiveMin, const std::string header, const std::string query, const std::string error) {

	bool isValid = false;

	do {

		std::cout << header;
		getUserInput(userInput, query);

		if (*userInput > inclusiveMax || *userInput < inclusiveMin)  std::cout << *userInput << error << std::endl;
		else isValid = true;

	} while (!isValid);

}

#endif // JCInput

#ifndef JCOutput
#define JCOutput
#include <iostream>

template <typename T>
void printArray(T* someArray) {

	size_t arraySize = findArraySize(someArray);
	for (size_t i = 0; i < arraySize; i++) { std::cout << *(*someArray + i) << std::endl; }

}

#endif // JCOutput

#ifndef JCSorting
#define JCSorting

template <typename T>
void linearSort(T* someArray) {

	size_t arraySize = findArraySize(someArray);

	for (size_t i = 0; i < arraySize; i++) {

		for (size_t j = i + 1; j < arraySize; j++) {

			double temp = (double)(*(*someArray + i)); // Start: Ex [1],2,3 
			double right = (double)(*(*someArray + j)); // Right (start + 1) Ex 1,[2],3 

			if (temp < right) { // if [1] < [2]

				*(*someArray + j) = temp; // right (start+1) = [1]
				*(*someArray + i) = right; // left (start) = [2]

			}

		}

	}

}

#endif // JCSorting

#ifndef JCSearching
#define JCSearching

template <typename T>
long int linearSearch(const T* someArray, double target) {

	size_t arraySize = findArraySize(someArray);
	size_t element = 0;
	size_t comparrisons = 0;

	for (size_t i = 0; i < arraySize; i++) {

		int temp = *(*someArray + i);
		comparrisons++;
		if (target == *(*someArray + i)) {

			std::cout
				<< "Target: " << target << " found at element: " << i << std::endl
				<< "Comparrisons: " << comparrisons << std::endl;

			return i;

		}

	}

	std::cout
		<< "Target: " << target << " was unable to be found." << std::endl
		<< "Comparrisons: " << comparrisons << std::endl;

	return -1;

}

template <typename T>
long int binarySearch(const T* someArray, size_t arraySize, size_t middle, size_t comparrisons, double target) {


	if (middle >= arraySize || middle == -1) {

		std::cout
			<< "Target: " << target << " was unable to be found." << std::endl
			<< "Comparrisons: " << comparrisons << std::endl;

		return -1;

	}

	else if (target > *(*someArray + middle)) {

		comparrisons++;
		middle = middle - floor((middle) / (2 * comparrisons));
		return binarySearch(someArray, arraySize, middle, comparrisons, target);

	}

	else if (target < *(*someArray + middle)) {

		comparrisons++;
		middle = middle + floor((middle) / (2 * comparrisons));
		return binarySearch(someArray, arraySize, middle, comparrisons, target);

	}

	else {

		std::cout
			<< "Target: " << target << " found at element: " << middle << std::endl
			<< "Comparrisons: " << comparrisons << std::endl;

		return target;

	}

}

#endif // JCSearching
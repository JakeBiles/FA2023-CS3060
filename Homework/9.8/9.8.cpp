// Author : Jacob Biles
// Class : CS 3060 001
// Date : 9/8/23

#include <iostream>;
using namespace std;

// Constants //
const int NUMBERS[9] = { 2,2,3,4,5,6,7,8,9 };

// Prototypes //
size_t findUniqueNumbers(const int[], size_t, size_t);
int findCount(const int[], size_t, size_t);
int findMode(const int[], size_t);
void program();

// Main //
int main() {

	program();

	return 0;

}

// Implementation //
/* Find Unique Numbers
*  Finds the number of unique numbers within a given array, does so recursively
*  INPUTS : an array of ints, the size of the given array, the element in which the search stars
*  OUTPUTS : The number of unique numbers within the list
*/
size_t findUniqueNumbers(const int arrayNumbers[], size_t arraySize, size_t firstElement) {

	size_t uniqueNumCount = 1;

	if (firstElement == (arraySize - 1)) { return uniqueNumCount; }

	else if (*(arrayNumbers + firstElement) == *(arrayNumbers + (firstElement + 1))) {

		firstElement++;
		return findUniqueNumbers(arrayNumbers, arraySize, firstElement);

	}

	else {

		firstElement++;
		return findUniqueNumbers(arrayNumbers, arraySize, firstElement) + 1;

	}

}

/* Find count
*  Finds the count of a given number in a row recersively
*  INPUTS : an array of ints, the size of the given array, the element in which the search stars
*  OUTPUTS : The number of consecetive numbers
*/
int findCount(const int arrayNumbers[], size_t arraySize, size_t firstElement) {

	int count = 0;

	if (firstElement == (arraySize - 1)) { return count + 1; }

	else if (*(arrayNumbers + firstElement) == *(arrayNumbers + (firstElement + 1))) {

		firstElement++;
		return findCount(arrayNumbers, arraySize, firstElement) + 1;

	}

	else { return count + 1; }

}

/* Find Mode
*  Finds the mode of a given array
*  INPUTS : an array of ints, the size of the given array
*  OUTPUTS : The mode of the array
*/
int findMode(const int arrayNumbers[], size_t arraySize) {

	int currentCount = 0;
	int highestCount = 0;
	size_t highestElement = 0;
	size_t highestUniqueElement = 0;
	size_t uniqueElement = 0;
	size_t uniqueNumbers = findUniqueNumbers(arrayNumbers, arraySize, 0);
	size_t* uniqueArrayPTR = new size_t[uniqueNumbers];

	// Finding Highest Value
	for (size_t i = 0; i < arraySize; i) {

		currentCount = findCount(arrayNumbers, arraySize, i);

		// Checking for highest count
		if (currentCount == 1 && highestCount == 0) { highestCount = -1; }
		else if (currentCount > highestCount) {

			highestElement = i;
			highestUniqueElement = uniqueElement;
			highestCount = currentCount;

		}

		// Reccording each number's consecitivity
		if (uniqueElement < uniqueNumbers) {

			*(uniqueArrayPTR + uniqueElement) = currentCount;
			uniqueElement++;

		}

		// Incrementing i
		i = i + (size_t)currentCount;

	}

	// Ensuring uniqueness of consecitivity.
	for (size_t i = 0; i < uniqueNumbers; i++) {

		if (highestUniqueElement == i);
		else if (highestCount == *(uniqueArrayPTR + i)) { highestCount = -1; }

	}

	// Reuturning Values
	if (highestCount != -1) { return *(arrayNumbers + highestElement); }
	else { return -1; }

	// Removing Array 
	delete[] uniqueArrayPTR;

}

/* Program
*  Combines all elements of Program to calculate the mode of a given array
*/
void program() {

	size_t arraySize = sizeof(NUMBERS) / sizeof(NUMBERS[0]);
	int mode = findMode(NUMBERS, arraySize);

	if (mode == -1) { cout << "There was no mode." << endl; }
	else { cout << "The mode is: " << mode << endl; }

}
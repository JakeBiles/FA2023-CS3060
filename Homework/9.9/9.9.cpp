// Author : Jacob Biles
// Class : CS 3060 001
// Date : 9/8/23

#include <iostream>;
using namespace std;

// Constants 
const int NUMBERS[10] = { 1,2,3,4,5,6,7,8,9,10 };

// Prototypes
double findMedian(const int[], size_t);

// Main
int main() {

	size_t arraySize = (sizeof(NUMBERS) / sizeof(NUMBERS[0]));
	double median = findMedian(NUMBERS, arraySize);
	cout << median;

	return 0;

}

// Functions
/* Find Median
*  Finds the Median of a given array
*  INPUTS : an array of ints, the size of the given array
*  OUTPUTS : The Median or Median-average of an array
*/
double findMedian(const int arrayNumbers[], size_t arraySize) {

	if (arraySize % 2 == 0) {

		size_t evenElement = ((arraySize / 2) - 1);
		size_t oddElement = ((arraySize / 2));

		return (((double)*(NUMBERS + oddElement) + (double)*(NUMBERS + evenElement)) / 2);

	}
	else { return NUMBERS[((arraySize - 1) / 2)]; }

}
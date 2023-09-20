// Author : Jacob Biles
// Class : CS 3060 001
// Date : 8/29/23

#include <iostream>


// CONSTANTS //
const size_t NUM_FLAVORS = 5;

const char* FLAVOR_NAMES[NUM_FLAVORS] = {
	"Mild",
	"Medium",
	"Sweet",
	"Hot",
	"Zesty"
};


// PROTOTYPES //
void initilizeArray(std::string[], int[]);

void getUserInput(std::string[], int[]);

void findCeiling(size_t*, int[]);

void findFloor(size_t*, int[]);

void findTotal(int*, int[]);

void displayInfo(std::string[], int[]);

void salsaSalesCalculator();


// MAIN //
int main() {

	salsaSalesCalculator();
	return 0;

}


// FUNCTIONS //
/* Initilize Array
*  Initilizes two parrel arrays to represent the name of the product alongside the number of each sold
*  INPUTS : String Array (names of the flavors), Int Array (amount of each sold)
*/
void initilizeArray(std::string flavorNameArray[], int saleTotalArray[]) {

	//int sales[NUM_FLAVORS];
	//std::string flavors[NUM_FLAVORS];

	for (int i = 0; i < (int)NUM_FLAVORS; i++) {
		flavorNameArray[i] = FLAVOR_NAMES[i];
		saleTotalArray[i] = -1;
	}

}

/* Get User Input
*  Asks the use for amount sold of each type of product, disallows less than 0 entries
*  INPUTS : String Array (names of the flavors), Int Array (amount of each sold)
*/
void getUserInput(std::string flavorNameArray[], int saleTotalArray[]) {

	for (int i = 0; i < (int)NUM_FLAVORS; i++) {

		std::cout << "How many of the " << flavorNameArray[i] << " flavor did you sell today?" << std::endl;

		while (saleTotalArray[i] < 0) {

			std::cout << "Amount sold: ";
			std::cin >> saleTotalArray[i];
			std::cout << std::endl;

			if (saleTotalArray[i] < 0 && (std::cout << "You cant sell less than 0!" << std::endl));

		}

	}
}

/* Find Ceiling
*  Find the highest valued sale
*  INPUTS : Size_t min pointer - inputed value adress to be changed to adress of highest value, Int Array (amount of each sold)
*/
void findCeiling(size_t* max, int saleTotalArray[]) {

	for (size_t i = 0; i < NUM_FLAVORS; i++) {

		if (saleTotalArray[i] > saleTotalArray[*max] && (*max = i));


	}

}

/* Find Floor
*  Find the lowest valued sale
*  INPUTS : Size_t min pointer - inputed value adress to be changed to adress of lowest value, Int Array (amount of each sold)
*/
void findFloor(size_t* min, int saleTotalArray[]) {
	for (size_t i = 0; i < NUM_FLAVORS; i++) {

		if (saleTotalArray[i] < saleTotalArray[*min] && (*min = i));

	}
}

/* Find Total
*  Find the total of all sales
*  INPUTS : Inr pointer - inputed value adress to be changed to accumulated value of all elements of int array, Int Array (amount of each sold)
*/
void findTotal(int* totalSalesAccumulater, int saleTotalArray[]) {

	for (size_t i = 0; i < NUM_FLAVORS; i++) {

		*totalSalesAccumulater += saleTotalArray[i];

	}
}

/* Get User Input
*  Asks the use for amount sold of each type of product, disallows less than 0 entries
*  INPUTS : String Array (names of the flavors), Int Array (amount of each sold)
*/
void displayInfo(std::string flavorNameArray[], int saleTotalArray[]) {
	size_t lowest = 0, highest = 0;
	int totalSales = 0;

	findFloor(&lowest, saleTotalArray);
	findCeiling(&highest, saleTotalArray);
	findTotal(&totalSales, saleTotalArray);


	std::cout
		<< "There was a total of " << totalSales << " jars of salsa sold today." << std::endl
		<< "The highest sold being the " << flavorNameArray[highest] << " flavor " << "at " << saleTotalArray[highest] << std::endl
		<< "The lowest sold today being the " << flavorNameArray[lowest] << " flavor " << "at " << saleTotalArray[lowest] << std::endl
		<< std::endl;

	std::cout << "======================== Total Breakdown ========================" << std::endl;
	for (int i = 0; i < (int)NUM_FLAVORS; i++)
	{
		std::cout << flavorNameArray[i] << ": " << saleTotalArray[i] << std::endl;
	}
}

/* Salsa Sales Calculater
* Program that creates two parrel arrays, initilizes them and assigns name from an initilizer list (constant), gets the user to input sales and finally outputs all realavent information
*/
void salsaSalesCalculator() {

	std::string flavors[NUM_FLAVORS];
	int sales[NUM_FLAVORS];

	initilizeArray(flavors, sales);
	getUserInput(flavors, sales);
	displayInfo(flavors, sales);

}
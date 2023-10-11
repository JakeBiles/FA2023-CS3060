// Author : Jacob Biles
// Class : CS 3060 001
// Date : 8/29/23

#include <iostream>

// Constants //
const size_t NUM_WEEKDAYS = 5;
const size_t NUM_MONKEYS = 3;

const char* DAYS_OF_THE_WEEK[NUM_WEEKDAYS] = {
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday"
};

const char* MONKEY_NAMES[NUM_MONKEYS] = {
	"Banana Joe",
	"Talie Man",
	"Splitter"
};


// PROTOTYPES //
void getUserInput(float[NUM_MONKEYS][NUM_WEEKDAYS]);
void calculateDailyAverage(float[NUM_MONKEYS][NUM_WEEKDAYS], float[]);
void findSmallestEater(float[NUM_MONKEYS][NUM_WEEKDAYS], size_t*);
void findHighestEater(float[NUM_MONKEYS][NUM_WEEKDAYS], size_t*);
void displayTable(float[NUM_MONKEYS][NUM_WEEKDAYS], float[], size_t*, size_t*);
void monkeyFeedTable();

// Main //	
int main() {

	monkeyFeedTable();
	return 0;

}


// Function Implementation //
/* Get User Input
*  Gets the amount of food eaten by a monkey day by day, doesnt allow for negative values
*  INPUTS : Flot [][] - The table 2d array which holds the amount of food eaten by each monkey per day
*/
void getUserInput(float monkeyFeedTableArray[NUM_MONKEYS][NUM_WEEKDAYS]) {

	for (int i = 0; i < (int)NUM_MONKEYS; i++) {

		std::cout << "Please enter the amount of pounds " << MONKEY_NAMES[i] << " ate on:" << std::endl;

		for (int j = 0; j < (int)NUM_WEEKDAYS; j++) {

			do {

				std::cout << DAYS_OF_THE_WEEK[j] << ": ";
				std::cin >> monkeyFeedTableArray[i][j];
				std::cin.clear();

			} while (monkeyFeedTableArray[i][j] < 0 && (std::cout << "The amount eaten must be at least 0 pounds please re-enter " << MONKEY_NAMES[i] << " for" << std::endl));

		}

		std::cout << std::endl;

	}

}

/* Calculate Daily Average
*  Calculates the average of each day of food eaten per monkey
*  INPUTS : Flot [][] - The table 2d array which holds the amount of food eaten by each monkey per day, float [] - Array containing each average based on day
*/
void calculateDailyAverage(float monkeyFeedTableArray[NUM_MONKEYS][NUM_WEEKDAYS], float dailyAverageArray[]) {

	float total;
	size_t count = 0;

	for (int i = 0; i < (int)NUM_WEEKDAYS; i++) {

		total = 0;

		for (int j = 0; j < (int)NUM_MONKEYS; j++) {

			total += monkeyFeedTableArray[j][i];

		}

		dailyAverageArray[count] = (total / NUM_MONKEYS);
		count++;

	}


}

/* Find Smallest Eater
*  Compares all monkeys food eaten by the week and finds the monkey which ate the least
*  INPUTS : Flot [][] - The table 2d array which holds the amount of food eaten by each monkey per day, size_t pointer - pointer to the element which is the smallest eater
*/
void findSmallestEater(float monkeyFeedTableArray[NUM_MONKEYS][NUM_WEEKDAYS], size_t* smallestEaterElement) {

	float total;
	float smallestValue = NULL;

	for (size_t i = 0; i < NUM_MONKEYS; i++) {

		total = 0;

		for (size_t j = 0; j < NUM_WEEKDAYS; j++) {

			total += monkeyFeedTableArray[i][j];

		}

		if (total < smallestValue || smallestValue == NULL) {

			smallestValue = total;
			*smallestEaterElement = i;

		}

	}

}

/* Find Highest Eater
*  Compares all monkeys food eaten by the week and finds the monkey which ate the most
*  INPUTS : Flot [][] - The table 2d array which holds the amount of food eaten by each monkey per day, size_t pointer - pointer to the element which is the highest eater
*/
void findHighestEater(float monkeyFeedTableArray[NUM_MONKEYS][NUM_WEEKDAYS], size_t* highestEaterElement) {

	float total;
	float largestValue = 0;

	for (size_t i = 0; i < NUM_MONKEYS; i++) {

		total = 0;

		for (size_t j = 0; j < NUM_WEEKDAYS; j++) {

			total += monkeyFeedTableArray[i][j];

		}

		if (total > largestValue) {

			largestValue = total;
			*highestEaterElement = i;

		}

	}

}

/* Display Table
*  Displays the Monkey, how much they ate each day, and the average for the day. Alongside, the largest and smallest eater
*  INPUTS :
*  Flot [][] - The table 2d array which holds the amount of food eaten by each monkey per day
*  float [] - The daily average array
*  size_t pointer - pointer to the element which is the smallest eater
*  size_t pointer - pointer to the element which is the largest eater
*/
void displayTable(float monkeyFeedTableArray[NUM_MONKEYS][NUM_WEEKDAYS], float dailyAverageArray[], size_t* lowestEaterElement, size_t* highestEaterElement) {

	// Header
	std::cout << "Monkey name";
	for (size_t i = 0; i < NUM_WEEKDAYS; i++) { std::cout << "    " << DAYS_OF_THE_WEEK[i]; }
	std::cout << std::endl;

	// Data
	for (size_t i = 0; i < NUM_MONKEYS; i++) {

		std::cout << MONKEY_NAMES[i];
		for (size_t j = 0; j < NUM_WEEKDAYS; j++) { std::cout << "          " << monkeyFeedTableArray[i][j]; }
		std::cout << std::endl;

	}

	// Average
	std::cout << "Average";
	for (size_t i = 0; i < NUM_WEEKDAYS; i++) { std::cout << "          " << dailyAverageArray[i]; }
	std::cout << std::endl;

	std::cout << std::endl;

	// Highest / Smallest Eater
	std::cout << "The smallest eater is: " << MONKEY_NAMES[*lowestEaterElement] << std::endl;
	std::cout << "The highest eater is: " << MONKEY_NAMES[*highestEaterElement];

}

/* Monkey Feed table
*  Combines all elements, gets the user to input the amount of food each monkey ate each day. Then calculates the average per day based on each monkey, finds the smallest and largest eater in between all the monkies
*  and finally displays all of this information
*/
void monkeyFeedTable() {

	float monkeyFeedTable[NUM_MONKEYS][NUM_WEEKDAYS];
	float dailyAverage[NUM_WEEKDAYS];
	size_t lowestEaterElement = 0;
	size_t highestEaterElement = 0;

	getUserInput(monkeyFeedTable);
	calculateDailyAverage(monkeyFeedTable, dailyAverage);
	findSmallestEater(monkeyFeedTable, &lowestEaterElement);
	findHighestEater(monkeyFeedTable, &highestEaterElement);

	displayTable(monkeyFeedTable, dailyAverage, &lowestEaterElement, &highestEaterElement);

}
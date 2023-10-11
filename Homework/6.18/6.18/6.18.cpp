// Author : Jacob Biles
// Class : CS 3060 001
// Date : 8/21/23

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

using namespace std;

// Constants //

const float PRICE_PER_HOUR_WORKED = 25.00;

const float SQUARE_FEET_ESTIMATE = 110;

const float GALLON_ESTIAMTE = 1;

const float HOURS_ESTIMATE = 8;

const float GALLON_PER_FT = (GALLON_ESTIAMTE / SQUARE_FEET_ESTIMATE);

const float HOURS_PER_FT = (HOURS_ESTIMATE / SQUARE_FEET_ESTIMATE);

const size_t NUMBER_OF_USER_INPUTS = 3;

const char* PROMPTS[NUMBER_OF_USER_INPUTS] =
{
	"rooms",
	"square feet",
	"gallons"
};


// Classes // 

class InputHashTable {

private:
	string userPrompts[NUMBER_OF_USER_INPUTS];
	float values[NUMBER_OF_USER_INPUTS];

public:

	void addElement(string type) {

		int i = -1;

		do {

			i++;

			if (userPrompts[i].empty() && userPrompts[i] != type) {

				userPrompts[i] = type;
				values[i] = 0;

			}

		} while (userPrompts[i] != type && i < NUMBER_OF_USER_INPUTS);

	}


public:

	float* getValue(string prompt) {

		float* output = NULL;

		for (int i = 0; i < (int)NUMBER_OF_USER_INPUTS; i++) {

			if (prompt == userPrompts[i]) { output = &values[i]; }

		}

		return output;

	}

};


// FUNCTIONS //

// Validate User Input
// Ensures the user's input is above zero for entries
// INPUTS :: Pointer to float variable, Prompt string - > passed
// SPECIAL CASE :: If the prompt is gallon, then the input must be 10
void validatedUserInput(float* variable, string prompt) {

	if (prompt != "gallons") {

		while (*variable <= 0 && (cout << "Please enter the number of " << prompt << ": " && cin >> *variable)) {

			if (*variable <= 0 && cout << "The value of the previous question must be greater than 0!" << endl << endl);

		}

	} // Not gallon price

	else {

		while (*variable < 10 && (cout << "Please enter the price of " << prompt << ": " && cin >> *variable)) {

			if (*variable < 10 && cout << "The value of the previous question must be greater than or equal to 10!" << endl << endl);

		}

	} // Gallon price

	cout << endl;

} // End Validate User Input 

// Calculate Gallons
// Calculates the total number of gallons to be used
// INPUTS :: Value representing square feet in given home
// OUTPUTS :: Estimated number of gallons needed
float calculateGallons(float squareFeet) {

	return squareFeet * GALLON_PER_FT;

}

// Calculate Hours
// Calculates the total number of hours 
// INPUTS :: Value representing square feet in given home
// OUTPUTS :: Estiamtes the number of hours needed for the job
float calculateHours(float squareFeet) {

	return squareFeet * HOURS_PER_FT;

}

// Calculate Gallon Price
// Calculates the price from the number of gallons needed
// INPUTS :: Gallons needed for job, The price of gallons
// OUTPUTS :: The price based on A*B
float calculateGallonPrice(float gallonsNeeded, float gallonPrice) {

	return gallonsNeeded * gallonPrice;

}

// Calculate Labor Price
// Calculates the price from the number of hours
// INPUTS :: Hours needed to complete the job
// OUTPUTS :: The price based on A*B (CONSTANT)
float calculateLabourPrice(float hoursNeeded) {

	return hoursNeeded * PRICE_PER_HOUR_WORKED;

}

// Initilize Table
// Creates Hash Table based on constant information
InputHashTable initilizeTable() {

	InputHashTable userInputsTable;

	for (int i = 0; i < (int)NUMBER_OF_USER_INPUTS; i++) {

		userInputsTable.addElement(PROMPTS[i]);
		validatedUserInput(userInputsTable.getValue(PROMPTS[i]), PROMPTS[i]);

	}
	return userInputsTable;

}

// Quote Calculator
// Calculates the quote and displays information to user
// INPUT :: Hash table of user's inputs
void quoteCalculator(InputHashTable userInputs) {

	float totalGallons, totalHours, priceHours, priceGallons;

	totalGallons = calculateGallons(*userInputs.getValue("square feet"));
	totalHours = calculateHours(*userInputs.getValue("square feet"));
	priceGallons = calculateGallonPrice(ceil(totalGallons), *userInputs.getValue("gallons"));
	priceHours = calculateLabourPrice(calculateHours(*userInputs.getValue("square feet")));


	cout << "Number of gallons needed: " << std::setprecision(2) << totalGallons << std::fixed << endl <<
		std::setprecision(0) << "Rounded up to: " << ceil(totalGallons) << std::fixed << endl << endl;

	cout << "Number of hours of work needed: " << std::setprecision(2) << totalHours << std::fixed << endl;

	cout << "Price of gallons: $" << std::setprecision(2) << priceGallons << std::fixed << endl;

	cout << "Price of Labour: $" << std::setprecision(2) << priceHours << std::fixed << endl;

	cout << "Total price of job: $" << priceGallons + priceHours << endl;

}

// Paint quote Program
// Creates Hash table and calculates quote based on user input
void paintQuoteProgram() {

	InputHashTable userInputs = initilizeTable();
	quoteCalculator(userInputs);

}


// Main // 

int main() {

	paintQuoteProgram();

} // End main // 


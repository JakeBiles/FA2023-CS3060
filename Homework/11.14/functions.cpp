#include "functions.h"

#include <iostream>
#include <string>
#include "JacobCommon.h"
#include "Bin.h"
#include "constants.h"

/* Initialize Bins
* Initializes the bins from given constants
* == INPUTS ==
* Bin* currentBinPTR -- Current bin element being looked at
* size_t count -- the current count
*/
void initializeBins(Bin* currentBinPTR, size_t count) {

	if (count != NUM_OF_BINS) {
		(currentBinPTR + count)->itemDesc = *(BIN_NAMES + count);
		(currentBinPTR + count)->numberOfItem = *(BIN_INITIL_VALS + count);
		count++;
		initializeBins(currentBinPTR, count);
	}

}

/* Build Empty
* If there were any bins that were empty prints these
* == INPUTS ==
* const Bin* currentBinPTR -- Current bin element being looked at
* size_t count -- the current count
*/
void buildEmpty(const Bin* currentBinPTR, size_t count) {

	if (count == NUM_OF_BINS) { std::cout << QUIT_OPTION << ". QUIT" << std::endl; }

	else {

		count++;
		std::cout
			<< "Bin: #" << count << std::endl
			<< "Desc: " << currentBinPTR->itemDesc << std::endl
			<< std::endl;

		return buildEmpty((currentBinPTR + 1), count);

	}

}

/* Build Used
* Builds the menu with all the bins names / inventory
* == INPUTS ==
* const Bin* currentBinPTR -- Current bin element being looked at
* size_t count -- the current count
*/
void buildUsed(const Bin* currentBinPTR, size_t count) {

	if (currentBinPTR->numberOfItem == -1 || count == NUM_OF_BINS) { return buildEmpty(currentBinPTR, count); }

	else {

		count++;

		std::cout
			<< "Bin: #" << count << std::endl
			<< "Desc: " << currentBinPTR->itemDesc << std::endl
			<< "Count: " << currentBinPTR->numberOfItem << std::endl
			<< std::endl;

		return buildUsed((currentBinPTR + 1), count);

	}

}

/* Build Options
* Builds the options portion of string
* == INPUTS ==
* size_t count -- the current count
*/
void buildOptions(size_t count) {

	if (count == NUM_OF_EDIT_OPTIONS) { std::cout << std::endl << BACK_OPTION << ". " << "BACK" << std::endl; }

	else {

		std::cout << count + 1 << ". " << *(EDIT_OPTIONS + count) << std::endl;
		count++;

		return buildOptions(count);

	}

}

/* Initialize Program
* calls all initilailzing functions
* == INPUTS ==
* Bin* currentBinPTR -- Current bin element being looked at
* size_t count -- the current count
*/
void initilizeProgram(Bin* currentBinPTR) {

	initializeBins(currentBinPTR, 0);
	buildUsed(currentBinPTR, 0);

}

/* Modify Value
* modifies the count value by given count
* == INPUTS ==
* Bin* currentBinPTR -- Current bin element being looked at
* const int value -- the value to modify by
*/
void modifyValue(Bin* currentBinPTR, const int value) {

	currentBinPTR->numberOfItem += value;

}

/* Build Header
* Builds a header portion of an outpuit
* == INPUTS ==
* const Bin* currentBinPTR -- Current bin element being looked at
* const string option -- optional text to add to printoff
*/
void buildHeader(const Bin* currentBinPTR, const std::string option) {

	std::cout
		<< "Current amount of " << currentBinPTR->itemDesc << ": " << currentBinPTR->numberOfItem << std::endl
		<< option << ": " << MAX_BIN_ITEMS << std::endl
		<< std::endl
		<< "Enter 0 to go back" << std::endl;

}

/* Build Error
* Builds a error portion of the print
* == INPUTS ==
* const int max -- the Highest range that can be entered
* const int min -- the lowest value that can be entered
*/
void buildError(const int max, const int min) {

	std::cout << " is invalid! Range: (" << max << "-" << min << ")";

}

/* Perform Operand
* Lets user select which operand to complete and does so
* == INPUTS ==
* Bin* currentBinPTR -- The current bin being looked at
*/
void performOperand(Bin* currentBinPTR) {
	size_t userInput = 0;
	Bin* temp = (currentBinPTR - 1);
	int valueInput = 0;
	bool isValid = false;

	do {
		
		buildOptions(0);
		ensureValidInput(&userInput, (size_t)(NUM_OF_EDIT_OPTIONS + 1), (size_t)(1), "", "Please make a selection: ", " is an invalid selection!");

		switch (userInput)
		{

		case 1:

			buildHeader(temp, "Maximum ");

			ensureValidInput(&valueInput, (MAX_BIN_ITEMS - temp->numberOfItem), 0, "", "Please Select a value to add: ", " is out of range! The bin cant be over 30! Enter 0 to go back or a new value to add!");
			modifyValue(temp, valueInput);

			break;
		case 2:

			buildHeader(temp, "Minimum ");

			ensureValidInput(&valueInput, temp->numberOfItem, MIN_BIN_ITEMS, "", "Please enter a value to subtract: ", " is out of range! The bin cant be negative! Enter 0 to go back or a new value to substract!");
			modifyValue(temp, -valueInput);


			break;
		case 3:

			isValid = true;

			break;
		default:

			std::cout
				<< "Error 1 " << std::endl
				<< "How did we get here?" << std::endl
				<< "Current value: " << userInput << std::endl;

			break;

		}

	} while (!isValid);

}

void binInventoryTracker() {

	bool isValid = false;
	size_t userInput = 0;
	Bin binInventroy[NUM_OF_BINS];
	initilizeProgram(binInventroy);

	do {

		ensureValidInput(&userInput, (size_t)(NUM_OF_BINS + 1), (size_t)(1), "", "Enter a bin to edit: ", " is an invalid input! (1-10) or 11 to quit!");

		if (userInput <= 10) {
			performOperand(binInventroy + userInput);
			buildUsed(binInventroy, 0);
		}

		else {
			isValid = true;
		}

	} while (!isValid);
}
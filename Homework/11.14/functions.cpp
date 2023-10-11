#include "functions.h"

#include <iostream>
#include <sstream>
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
* stringstream& menuString -- The string being written to
* size_t count -- the current count
*/
void buildEmpty(const Bin* currentBinPTR, std::stringstream& menuString, size_t count) {

	if (count == NUM_OF_BINS) { menuString << QUIT_OPTION << ". QUIT" << std::endl; }

	else {

		count++;
		menuString
			<< "Bin: #" << count << std::endl
			<< "Desc: " << currentBinPTR->itemDesc << std::endl
			<< std::endl;

		return buildEmpty((currentBinPTR + 1), menuString, count);

	}

}

/* Build Used
* Builds the menu with all the bins names / inventory
* == INPUTS ==
* const Bin* currentBinPTR -- Current bin element being looked at
* stringstream& menuString -- The string being written to
* size_t count -- the current count
*/
void buildUsed(const Bin* currentBinPTR, std::stringstream& menuString, size_t count) {

	if (currentBinPTR->numberOfItem == -1 || count == NUM_OF_BINS) { return buildEmpty(currentBinPTR, menuString, count); }

	else {

		count++;

		menuString
			<< "Bin: #" << count << std::endl
			<< "Desc: " << currentBinPTR->itemDesc << std::endl
			<< "Count: " << currentBinPTR->numberOfItem << std::endl
			<< std::endl;

		return buildUsed((currentBinPTR + 1), menuString, count);

	}

}

/* Build Options
* Builds the options portion of string
* == INPUTS ==
* stringstream& optionString -- The string being written to
* size_t count -- the current count
*/
void buildOptions(std::stringstream& optionString, size_t count) {

	if (count == NUM_OF_EDIT_OPTIONS) { optionString << std::endl << BACK_OPTION << ". " << "BACK" << std::endl; }

	else {

		optionString << count + 1 << ". " << *(EDIT_OPTIONS + count) << std::endl;
		count++;

		return buildOptions(optionString, count);

	}

}

/* Initialize Program
* calls all initilailzing functions
* == INPUTS ==
* Bin* currentBinPTR -- Current bin element being looked at
* stringstream& menuString -- The main menu string poriton being written to
* stringstream& optionString -- The option string portion being written to
* size_t count -- the current count
*/
void initilizeProgram(Bin* currentBinPTR, std::stringstream& menuString, std::stringstream& optionString) {

	initializeBins(currentBinPTR, 0);
	buildUsed(currentBinPTR, menuString, 0);
	buildOptions(optionString, 0);

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
* stringstream& header -- The header to be written to
*/
void buildHeader(const Bin* currentBinPTR, const std::string option, std::stringstream& header) {

	header
		<< "Current amount of " << currentBinPTR->itemDesc << ": " << currentBinPTR->numberOfItem << std::endl
		<< option << ": " << MAX_BIN_ITEMS << std::endl
		<< std::endl
		<< "Enter 0 to go back" << std::endl;

}

/* Build Query
* Builds a header portion of an outpuit
* == INPUTS ==
* const string stringA-C -- Optional First portio of line query
* stringstream& query -- The query to be written to
*/
void buildQuery(const std::string stringA, const std::string stringB, const std::string stringC, std::stringstream& query) {

	query << stringA << stringB << stringC;

}

/* Build Error
* Builds a error portion of the print
* == INPUTS ==
* const int max -- the Highest range that can be entered
* const int min -- the lowest value that can be entered
* stringstream& error -- The error portion of the print being written to
*/
void buildError(const int max, const int min, std::stringstream& error) {

	error << " is invalid! Range: (" << max << "-" << min << ")";

}

/* Clear Operands Temps
* Clears all built string streams and resets them to empty
* == INPUTS ==
* stringstream& header -- The header to be written to
* stringstream& query -- The query to be written to
* stringstream& error -- The error portion of the print being written to
*/
void clearOperandsTemps(std::stringstream& header, std::stringstream& query, std::stringstream& error) {

	header.str("");
	query.str("");
	error.str("");

}

/* Perform Operand
* Lets user select which operand to complete and does so
* == INPUTS ==
* Bin* currentBinPTR -- The current bin being looked at
* const stringstream& optionString -- The options printed off
* stringstream& menuString -- The menu meant to be re-written to
*/
void performOperand(Bin* currentBinPTR, const std::stringstream& optionString, std::stringstream& menuString) {

	std::stringstream tempQuery;
	std::stringstream tempHeader;
	std::stringstream tempError;
	size_t userInput = 0;
	Bin* temp = (currentBinPTR - 1);
	int valueInput = 0;
	bool isValid = false;

	do {

		ensureValidInput(&userInput, (size_t)(NUM_OF_EDIT_OPTIONS + 1), (size_t)(1), optionString.str(), "Please make a selection: ", " is an invalid selection!");

		switch (userInput)
		{

		case 1:

			buildHeader(temp, "Maximum ", tempHeader);
			buildQuery("Please select a value to ", EDIT_OPTIONS[userInput - 1], ": ", tempQuery);
			buildError((MAX_BIN_ITEMS - temp->numberOfItem), MIN_BIN_ITEMS, tempError);

			ensureValidInput(&valueInput, (MAX_BIN_ITEMS - temp->numberOfItem), 0, tempHeader.str(), tempQuery.str(), tempError.str());
			modifyValue(temp, valueInput);

			clearOperandsTemps(tempHeader, tempQuery, tempError);

			break;
		case 2:

			buildHeader(temp, "Minimum ", tempHeader);
			buildQuery("Please enter a value to ", EDIT_OPTIONS[userInput - 1], ": ", tempQuery);
			buildError(temp->numberOfItem, MIN_BIN_ITEMS, tempError);

			ensureValidInput(&valueInput, temp->numberOfItem, MIN_BIN_ITEMS, tempHeader.str(), tempQuery.str(), tempError.str());
			modifyValue(temp, -valueInput);

			clearOperandsTemps(tempHeader, tempQuery, tempError);

			break;
		case 3:

			isValid = true;

			clearOperandsTemps(tempHeader, tempQuery, tempError);

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
	std::stringstream binString;
	std::stringstream optionString;
	initilizeProgram(binInventroy, binString, optionString);

	do {

		ensureValidInput(&userInput, (size_t)(NUM_OF_BINS + 1), (size_t)(1), binString.str(), "Enter a bin to edit: ", " is an invalid input!");

		if (userInput <= 10) {
			performOperand(binInventroy + userInput, optionString, binString);
			binString.str("");
			buildUsed(binInventroy, binString, 0);
		}

		else {
			isValid = true;
		}

	} while (!isValid);
}
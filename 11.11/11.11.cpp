// Author : Jacob Biles
// Class : CS 3060 001
// Date : 9/17/23


#include <iostream>
#include <sstream>
#include <iomanip> 
using namespace std;


// Structures //
struct MonthlyBudget
{

	double housing = 0,
		utilities = 0,
		household = 0,
		transportation = 0,
		food = 0,
		medical = 0,
		insurance = 0,
		entertainment = 0,
		clothing = 0,
		misc = 0;

};


// Constants //
const MonthlyBudget BUDGET_GOAL = { 500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00 };
const size_t NUMBER_OF_CATEGORIES = 10;
const char* CATEGORY_OPTIONS[NUMBER_OF_CATEGORIES] = {

	"housing",
	"utilities",
	"household",
	"transportation",
	"food",
	"medical",
	"insurance",
	"entertainment",
	"clothing",
	"misc",

};


// TEMPLATE FUNCTIONS //
/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T>
void getUserInput(T* userSelection) {

	cout << endl;
	cout << "Entry: ";
	cin >> *userSelection;
	system("cls");
	cin.ignore();

}


// Prototypes // 
void ensureValidEntry(double*, size_t);
void setSpending(MonthlyBudget*);
void setMonthlySpending(MonthlyBudget*);
double determineDifference(double, double);
void buildHeader(stringstream&);
void buildGoal(stringstream&);
void buildActual(MonthlyBudget*, stringstream&);
void buildDifference(MonthlyBudget*, stringstream&);
void displayDifference(MonthlyBudget);
void expensesCalculator();


// Main //
int main() {

	expensesCalculator();
	return 0;

}


// Implementation //
/* Ensure Valid Entry
* == DESC ==
* Ensures v
* == INPUTS ==
* double* monthlyBudgetPTRCategory -- The budget category to edit
* size_t category -- The element of CATEGORY_OPTIONS array to print
*/
void ensureValidEntry(double* monthlyBudgetPTRCategory, size_t category) {

	bool validInput = false;
	double userInput = -1;

	do {

		cout << "Please enter " << CATEGORY_OPTIONS[category] << " expenses";
		getUserInput(&userInput);
		if (userInput < 0) { cout << "The entry must be at least 0" << endl; }
		else { *monthlyBudgetPTRCategory = userInput; validInput = true; }

	} while (!validInput);

}

/* Set Monthly Spending
* == DESC ==
* Sets the spending ammount of each category
* == INPUTS ==
* MonthlyBudget* monthlyBudgetPTR -- The monthy budget structure to edit
*/
void setMonthlySpending(MonthlyBudget* monthlyBudgetPTR) {

	for (size_t i = 0; i < NUMBER_OF_CATEGORIES; i++) {

		switch (i)
		{
		case 0:
			ensureValidEntry(&monthlyBudgetPTR->housing, i);
			break;

		case 1:
			ensureValidEntry(&monthlyBudgetPTR->utilities, i);
			break;

		case 2:
			ensureValidEntry(&monthlyBudgetPTR->household, i);
			break;

		case 3:
			ensureValidEntry(&monthlyBudgetPTR->transportation, i);
			break;

		case 4:
			ensureValidEntry(&monthlyBudgetPTR->food, i);
			break;

		case 5:
			ensureValidEntry(&monthlyBudgetPTR->medical, i);
			break;

		case 6:
			ensureValidEntry(&monthlyBudgetPTR->insurance, i);
			break;

		case 7:
			ensureValidEntry(&monthlyBudgetPTR->entertainment, i);
			break;

		case 8:
			ensureValidEntry(&monthlyBudgetPTR->clothing, i);
			break;

		case 9:
			ensureValidEntry(&monthlyBudgetPTR->misc, i);
			break;

		default:
			break;

		}

	}

}

/* Determine Differerence
* == DESC ==
* Determines left over / overdraft for each category
* == INPUTS ==
* double currentBudget -- The set budget from user input
* double budgetGoal -- The value from the goal budget
* == OUTPUTS ==
* double == budgetGoal - currentBuget
*/
double determineDifference(double currentBudget, double budgetGoal) {

	return budgetGoal - currentBudget;

}

/* Build Header
* == DESC ==
* Builds the header portion of the streamstring to be printed
* == INPUTS ==
* stringstream& budgetString -- the string stream to be edited
*/
void buildHeader(stringstream& budgetString) {

	budgetString << left << setw(15) << "";
	for (size_t i = 0; i < NUMBER_OF_CATEGORIES; i++) { budgetString << setw(15) << CATEGORY_OPTIONS[i]; }
	budgetString << setw(15) << "Total" << endl;

}

/* Build Goal
* == DESC ==
* Builds the goal portion of the streamstring to be printed
* == INPUTS ==
* stringstream& budgetString -- the string stream to be edited
*/
void buildGoal(stringstream& budgetString) {

	double total = 0;

	budgetString << setw(15) << "Goal";
	for (size_t i = 0; i < NUMBER_OF_CATEGORIES; i++) {

		switch (i) {

		case 0:

			total += BUDGET_GOAL.housing;

			budgetString << setw(15) << BUDGET_GOAL.housing;
			break;

		case 1:

			total += BUDGET_GOAL.utilities;

			budgetString << setw(15) << BUDGET_GOAL.utilities;
			break;

		case 2:

			total += BUDGET_GOAL.household;

			budgetString << setw(15) << BUDGET_GOAL.household;
			break;

		case 3:

			total += BUDGET_GOAL.transportation;

			budgetString << setw(15) << BUDGET_GOAL.transportation;
			break;

		case 4:

			total += BUDGET_GOAL.food;

			budgetString << setw(15) << BUDGET_GOAL.food;
			break;

		case 5:

			total += BUDGET_GOAL.medical;

			budgetString << setw(15) << BUDGET_GOAL.medical;
			break;

		case 6:

			total += BUDGET_GOAL.insurance;

			budgetString << setw(15) << BUDGET_GOAL.insurance;
			break;

		case 7:

			total += BUDGET_GOAL.entertainment;

			budgetString << setw(15) << BUDGET_GOAL.entertainment;
			break;

		case 8:

			total += BUDGET_GOAL.clothing;

			budgetString << setw(15) << BUDGET_GOAL.clothing;
			break;

		case 9:

			total += BUDGET_GOAL.misc;

			budgetString << setw(15) << BUDGET_GOAL.misc;
			break;

		} // Case 

	} // For 

	budgetString << setw(15) << total << endl;

}

/* Build Actual
* == DESC ==
* Builds the actual expenses portion of the streamstring to be printed
* == INPUTS ==
* MonthlyBudget* monthlyBudget -- the monthly budget containing current month expenses
* stringstream& budgetString -- the string stream to be edited
*/
void buildActual(MonthlyBudget* monthlyBudget, stringstream& budgetString) {

	double total = 0;

	budgetString << setw(15) << "Actual";
	for (size_t i = 0; i < NUMBER_OF_CATEGORIES; i++) {

		switch (i) {

		case 0:

			total += monthlyBudget->housing;

			budgetString << setw(15) << monthlyBudget->housing;
			break;

		case 1:

			total += monthlyBudget->utilities;

			budgetString << setw(15) << monthlyBudget->utilities;
			break;

		case 2:

			total += monthlyBudget->household;

			budgetString << setw(15) << monthlyBudget->household;
			break;

		case 3:

			total += monthlyBudget->transportation;

			budgetString << setw(15) << monthlyBudget->transportation;
			break;

		case 4:

			total += monthlyBudget->food;

			budgetString << setw(15) << monthlyBudget->food;
			break;

		case 5:

			total += monthlyBudget->medical;

			budgetString << setw(15) << monthlyBudget->medical;
			break;

		case 6:

			total += monthlyBudget->insurance;

			budgetString << setw(15) << monthlyBudget->insurance;
			break;

		case 7:

			total += monthlyBudget->entertainment;

			budgetString << setw(15) << monthlyBudget->entertainment;
			break;

		case 8:

			total += monthlyBudget->clothing;

			budgetString << setw(15) << monthlyBudget->clothing;
			break;

		case 9:

			total += monthlyBudget->misc;

			budgetString << setw(15) << monthlyBudget->misc;
			break;

		default:
			break;

		} // Case 

	} // For Loop
	budgetString << setw(15) << total << endl;

}

/* Build Difference
* == DESC ==
* Builds the difference of expenses portion of the streamstring to be printed
* == INPUTS ==
* MonthlyBudget* monthlyBudget -- the monthly budget containing current month expenses
* stringstream& budgetString -- the string stream to be edited
*/
void buildDifference(MonthlyBudget* monthlyBudget, stringstream& budgetString) {

	double total = 0;
	double temp = 0;

	budgetString << setw(15) << "Difference";
	for (size_t i = 0; i < NUMBER_OF_CATEGORIES; i++) {

		switch (i) {

		case 0:

			temp = determineDifference(monthlyBudget->housing, BUDGET_GOAL.housing);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 1:

			temp = determineDifference(monthlyBudget->utilities, BUDGET_GOAL.utilities);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 2:

			temp = determineDifference(monthlyBudget->household, BUDGET_GOAL.household);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 3:

			temp = determineDifference(monthlyBudget->transportation, BUDGET_GOAL.transportation);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 4:

			temp = determineDifference(monthlyBudget->food, BUDGET_GOAL.food);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 5:

			temp = determineDifference(monthlyBudget->medical, BUDGET_GOAL.medical);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 6:

			temp = determineDifference(monthlyBudget->insurance, BUDGET_GOAL.insurance);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 7:

			temp = determineDifference(monthlyBudget->entertainment, BUDGET_GOAL.entertainment);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 8:

			temp = determineDifference(monthlyBudget->clothing, BUDGET_GOAL.clothing);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		case 9:

			temp = determineDifference(monthlyBudget->misc, BUDGET_GOAL.misc);
			total += temp;

			budgetString << setw(15) << temp;
			break;

		} // Case 

	} // For Loop

	budgetString << setw(15) << total << endl;

}

/* Display Difference
* == DESC ==
* Builds all portions of the stringstream and prints it
* == INPUTS ==
* MonthlyBudget monthlyBudget -- the monthly budget containing current month expenses
*/
void displayDifference(MonthlyBudget monthlyBudget) {

	stringstream budgetString;

	buildHeader(budgetString);
	buildGoal(budgetString);
	buildActual(&monthlyBudget, budgetString);
	buildDifference(&monthlyBudget, budgetString);

	cout << budgetString.str();

}

/* Expenses Calculator
* == DESC ==
* Collects user expenses for the month,
* determines if the difference between the budget and actual spending,
* and displays this info
*/
void expensesCalculator() {

	MonthlyBudget monthlyBudget;
	setMonthlySpending(&monthlyBudget);
	displayDifference(monthlyBudget);

}
// Author : Jacob Biles
// Class : CS 3060 001
// Date : 9/14/23

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;


// STRUCTURES //
struct SecondaryAddress {

	string city;
	string state;
	unsigned int zipCode = 0;

};

struct Date
{
	unsigned short month = 0;
	unsigned short day = 0;
	unsigned short year = 0;

};

struct CustomerData {

	string name;
	string address;
	SecondaryAddress secondaryAddress;
	Date lastPayment;
	unsigned long long int phoneNumber = 0;
	double accountBalance = -1;

};


// CONSTANTS //
const size_t NUM_CUSTOMERS = 10;
const size_t NUM_MENU_OPTIONS = 5;
const size_t NUM_CUSTOMER_VARIABLES = 6;
const unsigned int ZIPCODE_MAX = 99999;
const unsigned int ZIPCODE_MIN = 10000;
const unsigned long long PHONE_NUMBER_MAX = 999999999999999;
const unsigned long long PHONE_NUMBER_MIN = 1000;
const short DAYS_PER_MONTH = 31;
const short MONTHS_PER_YEAR = 12;
const short MIN_YEARS = 1000;
const short MAX_YEARS = 2023;
const char* MENU_OPTIONS[NUM_MENU_OPTIONS] = {

	"Add User",
	"Edit User",
	"Search Users",
	"Display Users",
	"##Quit##",

};
const char* EDIT_OPTIONS[NUM_CUSTOMER_VARIABLES] = {

	"Name",
	"Address",
	"Last Payment",
	"Phone Number",
	"Account Balance",
	"##Back##",

};


// TEMPLATE FUNCTIONS //
template <typename T>
void getUserInput(T* userSelection) {

	cout << endl;
	cout << "Entry: ";
	cin >> *userSelection;
	system("cls");
	cin.ignore();

}


// PROTOTYPES //
void printMenuOptions();
void getUserInput(string*);
void buildCustomerList(CustomerData*, size_t, stringstream&);
void displayCustomers(CustomerData*, size_t);
void setName(CustomerData*);
void setCity(SecondaryAddress*);
void setState(SecondaryAddress*);
void setZipcode(SecondaryAddress*);
void setSecondaryAddress(SecondaryAddress*);
void setAddress(CustomerData*);
void setMonth(Date*);
void setDay(Date*);
void setYear(Date*);
void setLastPayment(Date*);
void setPhoneNumber(CustomerData*);
void setBalance(CustomerData*);
void initilizeCustomer(CustomerData*);
void createCustomers(CustomerData*, size_t, size_t);
void addCustomers(CustomerData*, size_t&);
void customerEdit(CustomerData*);
void customerSelect(CustomerData*);
void displayEmptyUsers(size_t);
CustomerData* displayUsers(CustomerData*, size_t);
CustomerData* searchName(CustomerData*, size_t, string, size_t, stringstream&);
void customerDataBase();


// MAIN //
int main() {

	customerDataBase();

	return 0;

}


// IMPLEMENTATION // 
/* Print Menu Options
* Prints the options the user can select in the main menu
*/
void printMenuOptions() {

	cout << "What would you like to do?" << endl;
	for (size_t i = 0; i < NUM_MENU_OPTIONS; i++) { cout << (i + 1) << ". " << MENU_OPTIONS[i] << endl; }

}

/* Get User Input -- Overload
* Handles a string input and performs cleanup for cin
* == INPUTS ==
* string* userAddress -- variable taking
*/
void getUserInput(string* userSelection) {

	cout << endl;
	cout << "Entry: ";
	getline(cin, *userSelection);
	system("cls");

}

/* Build Header
* Builds the header portion of the stringstream
* == INPUT ==
* stringstream& customerList -- The string to be edited
*/
void buildHeader(stringstream& customerList) {

	customerList
		<< setw(20) << "Name"
		<< setw(60) << "Address"
		<< setw(20) << "Last Payment"
		<< setw(20) << "Phone Number"
		<< setw(30) << "Account Balance" << endl;

}

/* Build Customer
* Builds the customer portion of the stringstream
* == INPUT ==
* CustomerData* customerPTR -- Pointer to open customer Postion
* size_t currentCustomers -- The amount of current customers
* stringstream& customerList -- The string to be edited
*/
void buildCustomers(CustomerData* customerPTR, size_t currentCustomers, stringstream& customerList) {

	CustomerData* temp;
	SecondaryAddress* tempAddress;
	Date* tempDate;
	string addressSTR;
	string dateSTR;

	for (size_t i = 0; i < (currentCustomers); i++) {

		temp = (customerPTR + i);
		tempAddress = &temp->secondaryAddress;
		tempDate = &temp->lastPayment;
		dateSTR = to_string(tempDate->month) + "/" + to_string(tempDate->day) + "/" + to_string(tempDate->year);
		addressSTR = temp->address + " " + tempAddress->city + " " + tempAddress->state + ", " + to_string(tempAddress->zipCode);

		customerList
			<< setw(20) << temp->name
			<< setw(60) << addressSTR
			<< setw(20) << dateSTR
			<< setw(20) << temp->phoneNumber
			<< setw(30) << temp->accountBalance << endl;

	}

}

/* Build CustomerList
* Builds the stringstream to be printed
* == INPUT ==
* CustomerData* customerPTR -- Pointer to open customer Postion
* size_t currentCustomers -- The amount of current customers
* stringstream& customerList -- The string to be edited
*/
void buildCustomerList(CustomerData* customerPTR, size_t currentCustomers, stringstream& customerList) {

	customerList << left;
	if (customerList.str().empty() == true) { buildHeader(customerList); }
	buildCustomers(customerPTR, currentCustomers, customerList);

}

/* Build Customer
* Builds the customer portion of the stringstream
* == INPUT ==
* CustomerData* customerPTR -- Pointer to open customer Postion
* size_t currentCustomers -- The amount of current customers
* stringstream& customerList -- The string to be edited
*/
void displayCustomers(CustomerData* customerPTR, size_t currentCustomers) {

	stringstream customerList;
	buildCustomerList(customerPTR, currentCustomers, customerList);
	unsigned short userInput = 0;

	do {

		cout << customerList.str() << endl;
		cout << "Enter 0 to quit.";
		getUserInput(&userInput);

	} while (userInput != 0 && cout << "Invalid Entry" << endl);

}

/* Set Name
* Sets the name of the customer pointed to
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void setName(CustomerData* customerPTR) {

	string userInput = "";
	bool validEntry = false;

	do {

		if (customerPTR->name == "") { cout << "What is the customer's name?"; }
		else { cout << "Current Name: " << customerPTR->name; }
		cout << endl;

		if (customerPTR->name != "") { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != "0") { customerPTR->name = userInput; validEntry = true; }
		else if (userInput == "0" && customerPTR->name != "") { validEntry = true; }
		else { cout << "The name entry cant be blank" << endl; }

	} while (!validEntry);

}

/* Set City
* Sets the City of the customer's secondary address pointed to
* == INPUT ==
* SecondaryAddress* secondaryAddressPTR -- Pointer to secondary address structure of a customer
*/
void setCity(SecondaryAddress* secondaryAddressPTR) {

	string userInput = "";
	bool validEntry = false;

	do {

		if (secondaryAddressPTR->city == "") { cout << "What is the customer's city?"; }
		else { cout << "Current city: " << secondaryAddressPTR->city; }
		cout << endl;

		if (secondaryAddressPTR->city != "") { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != "0") { secondaryAddressPTR->city = userInput; validEntry = true; }
		else if (userInput == "0" && secondaryAddressPTR->city != "") { validEntry = true; }
		else { cout << "The city entry cant be blank" << endl; }

	} while (!validEntry);

}

/* Set State
* Sets the State of the customer's secondary address pointed to
* == INPUT ==
* SecondaryAddress* secondaryAddressPTR -- Pointer to secondary address structure of a customer
*/
void setState(SecondaryAddress* secondaryAddressPTR) {

	string userInput = "";
	bool validEntry = false;

	do {

		if (secondaryAddressPTR->state == "") { cout << "What is the customer's state?"; }
		else { cout << "Current state: " << secondaryAddressPTR->state; }
		cout << endl;

		if (secondaryAddressPTR->state != "") { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != "0") { secondaryAddressPTR->state = userInput; validEntry = true; }
		else if (userInput == "0" && secondaryAddressPTR->state != "") { validEntry = true; }
		else { cout << "The name entry cant be blank" << endl; }

	} while (!validEntry);

}

/* Set zipcode
* Sets the zipcode of the customer's secondary address pointed to
* == INPUT ==
* SecondaryAddress* secondaryAddressPTR -- Pointer to secondary address structure of a customer
*/
void setZipcode(SecondaryAddress* secondaryAddressPTR) {

	unsigned int userInput = 0;
	bool ValidEntry = false;

	do {

		if (secondaryAddressPTR->zipCode == 0) { cout << "What is the customer's zipcode? " << "(" << ZIPCODE_MIN << "-" << ZIPCODE_MAX << ")"; }
		else { cout << "Current zipcode: " << secondaryAddressPTR->zipCode; }
		cout << endl;

		if (secondaryAddressPTR->zipCode != 0) { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != 0 && (userInput >= ZIPCODE_MIN && userInput <= ZIPCODE_MAX)) { secondaryAddressPTR->zipCode = userInput; ValidEntry = true; }
		else if (userInput == 0 && (secondaryAddressPTR->zipCode <= ZIPCODE_MAX && secondaryAddressPTR->zipCode >= ZIPCODE_MIN)) { ValidEntry = true; }
		else { cout << userInput << " isnt a valid input for the day" << endl; }

	} while (!ValidEntry);

}

/* Set Secondary Address
* Builds the secondary address portion of customer data
* == INPUT ==
* SecondaryAddress* secondaryAddressPTR -- Pointer to secondary address structure of a customer
*/
void setSecondaryAddress(SecondaryAddress* secondaryAddressPTR) {

	setCity(secondaryAddressPTR);
	setState(secondaryAddressPTR);
	setZipcode(secondaryAddressPTR);

}

/* Set Address
* Sets the address variable of a customers data profile
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void setAddress(CustomerData* customerPTR) {

	string userInput;
	bool validEntry = false;

	do {

		if (customerPTR->address == "") { cout << "What is the customer's address?"; }
		else { cout << "Current address: " << customerPTR->address; }
		cout << endl;

		if (customerPTR->address != "") { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != "0") { customerPTR->address = userInput; validEntry = true; }
		else if (userInput == "0" && customerPTR->address != "") { validEntry = true; }
		else { cout << "The name entry cant be blank" << endl; }

	} while (!validEntry);

	setSecondaryAddress(&customerPTR->secondaryAddress);

}

/* Set Month
* Sets the month of the pointed to customer's date variable
* == INPUT ==
* Date* datePTR -- Pointer to customer's last payment variable
*/
void setMonth(Date* datePTR) {

	unsigned short userInput = 0;
	bool validEntry = false;

	do {

		if (datePTR->month == 0) { cout << "What month was the last payment completed? " << "(1-" << MONTHS_PER_YEAR << ")"; }
		else { cout << "Current Month: " << datePTR->month; }
		cout << endl;

		if (datePTR->month != 0) { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != 0 && (userInput <= MONTHS_PER_YEAR && userInput >= 1)) { datePTR->month = userInput; validEntry = true; }
		else if (userInput == 0 && (datePTR->month <= MONTHS_PER_YEAR && datePTR->month >= 1)) { validEntry = true; }
		else { cout << userInput << " isnt a valid input for the month" << endl; }

	} while (!validEntry);

}

/* Set Day
* Sets the day of the pointed to customer's date variable
* == INPUT ==
* Date* datePTR -- Pointer to customer's last payment variable
*/
void setDay(Date* datePTR) {

	unsigned short userInput = 0;
	bool validEntry = false;

	do {

		if (datePTR->day == 0) { cout << "On what day? " << "(1-" << DAYS_PER_MONTH << ")"; }
		else { cout << "Current Day: " << datePTR->day; }
		cout << endl;

		if (datePTR->day != 0) { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != 0 && (userInput <= DAYS_PER_MONTH && userInput >= 1)) { datePTR->day = userInput; validEntry = true; }
		else if (userInput == 0 && (datePTR->day <= DAYS_PER_MONTH && datePTR->day >= 1)) { validEntry = true; }
		else { cout << userInput << " isnt a valid input for the day" << endl; }

	} while (!validEntry);

}

/* Set Year
* Sets the year of the pointed to customer's date variable
* == INPUT ==
* Date* datePTR -- Pointer to customer's last payment variable
*/
void setYear(Date* datePTR) {

	unsigned short userInput = 0;
	bool validEntry = false;

	do {

		if (datePTR->year == 0) { cout << "In what year? " << "(" << MIN_YEARS << "-" << MAX_YEARS << ")"; }
		else { cout << "Current Year: " << datePTR->year; }
		cout << endl;

		if (datePTR->year != 0) { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != 0 && (userInput <= MAX_YEARS && userInput >= MIN_YEARS)) { datePTR->year = userInput; validEntry = true; }
		else if (userInput == 0 && (datePTR->year <= MAX_YEARS && datePTR->year >= MIN_YEARS)) { validEntry = true; }
		else { cout << userInput << " isnt a valid input for the year" << endl; }

	} while (!validEntry);

}

/* Set Last Payment
* Builds the last payment variable of customer's Data
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void setLastPayment(CustomerData* customerPTR) {

	setMonth(&customerPTR->lastPayment);
	setDay(&customerPTR->lastPayment);
	setYear(&customerPTR->lastPayment);

}

/* Set Phone Number
* Sets the customers Phone number
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void setPhoneNumber(CustomerData* customerPTR) {

	unsigned long long userInput = 0;
	bool validEntry = false;

	do {

		if (customerPTR->phoneNumber == 0) { cout << "What is the customer's phone number? Format: 1234567890"; }
		else { cout << "Current Phone number: " << customerPTR->phoneNumber; }
		cout << endl;

		if (customerPTR->phoneNumber != 0) { cout << "Enter 0 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != 0 && (userInput <= PHONE_NUMBER_MAX && userInput >= PHONE_NUMBER_MIN)) { customerPTR->phoneNumber = userInput; validEntry = true; }
		else if (userInput == 0 && (customerPTR->phoneNumber <= PHONE_NUMBER_MAX && customerPTR->phoneNumber >= PHONE_NUMBER_MIN)) { validEntry = true; }
		else { cout << userInput << " isnt a valid phone number" << endl; }

	} while (!validEntry);

}

/* Set Balance
* Sets the customers phone number
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void setBalance(CustomerData* customerPTR) {

	double userInput = -1;
	bool validEntry = false;

	do {

		if (customerPTR->accountBalance != -1) { cout << "Current balance: " << customerPTR->accountBalance; }
		else { cout << "Please Enter the customer's inital Balance: "; }
		cout << endl;

		if (customerPTR->accountBalance != -1) { cout << "Enter -1 to skip changes." << endl; }
		getUserInput(&userInput);

		if (userInput != -1 && userInput >= 0) { customerPTR->accountBalance = userInput; validEntry = true; }
		else if (userInput == -1 && (customerPTR->accountBalance >= 0)) { validEntry = true; }
		else { cout << userInput << " isnt a valid account balance" << endl; }

	} while (!validEntry);

}

/* Initilize Customers
* Builds the customer by setting all varaibles
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void initilizeCustomer(CustomerData* customerPTR) {

	setName(customerPTR);
	setAddress(customerPTR);
	setLastPayment(customerPTR);
	setPhoneNumber(customerPTR);
	setBalance(customerPTR);

}

/* Create Customers
* Creates the number of requested customers, if allowed
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
* size_t numToAdd -- The number of times to build a character
* size_t currentCustomers -- The number of Current Customers
*/
void createCustomers(CustomerData* customerPTR, size_t numToAdd, size_t currentCustomers) {

	for (size_t i = 0; i < numToAdd; i++) { initilizeCustomer(customerPTR + i); }

}

/* Add Customers
* Gets the number of customers to add,
* determines if valid,
* and calls creation
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
* size_t& currentCustomers -- The current number of customers
*/
void addCustomers(CustomerData* customerPTR, size_t& currentCustomerREF) {

	size_t numToAdd = 0;
	bool validEntry = false;

	do {

		if (currentCustomerREF != NUM_CUSTOMERS + 1) {

			cout << "How many customers are needed to be added?" << endl;
			cout << "Enter 0 to quit" << endl;
			getUserInput(&numToAdd);

		}

		if (currentCustomerREF == NUM_CUSTOMERS && numToAdd != 0) { cout << "The max amount of customers has been reached" << endl; validEntry = true; }
		else if (numToAdd == 0) { validEntry = true; }
		else if (numToAdd > NUM_CUSTOMERS - currentCustomerREF) { cout << "That is too many customers" << endl; }
		else { createCustomers(customerPTR + currentCustomerREF, numToAdd, currentCustomerREF); currentCustomerREF += numToAdd; }

	} while (!validEntry);

}

/* Customer Edit
* Displays the edit options
* calls given edit function if valid
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void customerEdit(CustomerData* customerPTR) {

	if (customerPTR->name != "") {

		size_t userSelection = 0;

		do {

			cout << "What would you like to edit about: " << customerPTR->name << endl;
			for (size_t i = 0; i < NUM_CUSTOMER_VARIABLES; i++) { cout << i + 1 << ". " << EDIT_OPTIONS[i] << endl; }
			getUserInput(&userSelection);

			if (userSelection == NUM_CUSTOMER_VARIABLES) { /*Quit Option Selected*/ }

			else if (userSelection != 0) {

				switch (userSelection) {

				case 1: // Name
					setName(customerPTR);
					break;

				case 2: // Address
					setAddress(customerPTR);
					break;

				case 3: // Payment
					setLastPayment(customerPTR);
					break;

				case 4: // Phone
					setPhoneNumber(customerPTR);
					break;

				case 5: // Balance
					setBalance(customerPTR);
					break;

				}

			} // Case

			else {

				cout
					<< "========================" << endl
					<< "  Invalid Selection: " << userSelection << endl
					<< "========================" << endl;

			}

		} while (userSelection != NUM_CUSTOMER_VARIABLES);

	} // Not Empty Element 

	else {

		cout
			<< "=======================================================" << endl
			<< " This element is empty, try adding a customer instead." << endl
			<< "=======================================================" << endl;

	} // Empty Element

}

/* Customer Select
* Determines which customer to edit if valid
* == INPUT ==
* CustomerData* customerPTR -- Pointer to customer
*/
void customerSelect(CustomerData* customerPTR) {

	size_t userSelection = 0;

	do {

		cout << "Which customer would you like to edit?" << endl;
		displayUsers(customerPTR, 0);
		cout << NUM_CUSTOMERS + 1 << ". ##Back##" << endl;

		getUserInput(&userSelection);

		if (userSelection == NUM_CUSTOMERS + 1) { /*Quit Option Selected*/ }
		else if (userSelection < NUM_CUSTOMERS + 1 && userSelection != 0) { customerEdit(customerPTR + userSelection - 1); }
		else {

			cout
				<< "========================" << endl
				<< "  Invalid Selection: " << userSelection << endl
				<< "========================" << endl;

		}

	} while (userSelection != NUM_CUSTOMERS + 1);

}

/* Display Empty Users
* Displays all remaining slots as empty
* == INPUT ==
* size_t count -- the number of slots to print
*/
void displayEmptyUsers(size_t count) {

	for (count; count < NUM_CUSTOMERS + 1; count++) { cout << count << ". Empty" << endl; }

}

/* displayUsers
* Recursively displays each customer within a list
* == INPUT ==
* CustomerData* customerPTR -- the current customer pointed to
* size_t count -- the number of slots to print
*/
CustomerData* displayUsers(CustomerData* customerPTR, size_t count) {

	if (customerPTR->name == "" || count > NUM_CUSTOMERS - 1) {

		count++;
		displayEmptyUsers(count);
		return customerPTR;

	}

	else {

		count++;
		cout << count << ". " << customerPTR->name << endl;
		return displayUsers((customerPTR + 1), count);

	}

}

/* searchName
* Recursively searches a userlist for a given name
* == INPUT ==
* CustomerData* customerPTR -- the current customer pointed to
* size_t currentCustomers -- The number of customers
* string searchedName -- The prompted name
* size_t count -- the number of slots to print
* &matchList -- the string to write to;
*/
CustomerData* searchName(CustomerData* customerPTR, size_t currentCustomers, string searchedName, size_t count, stringstream& matchList) {

	if (count == currentCustomers) {

		return (customerPTR);

	}

	else if (customerPTR->name.substr(0, searchedName.length()) == searchedName) {

		count++;
		buildCustomerList(customerPTR, 1, matchList);
		return searchName(customerPTR + 1, currentCustomers, searchedName, count, matchList);

	}

	else {

		count++;
		return searchName(customerPTR + 1, currentCustomers, searchedName, count, matchList);

	}

}

/* performSerch
* Gets the search term of given search type
* == Inputs ==
* CustomerData* customerPTR -- The customer being pointed to
* size_t currentCustomers -- the current amount of customers
*/
void performSearch(CustomerData* customerPTR, size_t currentCustomers) {

	unsigned short userInput = 0;
	string nameSelection;
	stringstream tempString;

	cout << "Enter name to search ";
	getUserInput(&nameSelection);
	searchName(customerPTR, currentCustomers, nameSelection, 0, tempString);

	do {

		cout << "Searched " << nameSelection << endl;
		cout << tempString.str() << endl;

		cout << "Enter 0 to quit.";
		getUserInput(&userInput);

	} while (userInput != 0 && cout << "Invalid Entry" << endl);

}

/* performSerch
* Allows user to select different options in a menu
* perfoms actions based on those selections, if valid
* continues to do this untill prompted to quit
*/
void customerDataBase() {

	bool quit = false;
	size_t userSelection = 0;
	string nameSelection = "";
	size_t currentCustomers = 0;
	CustomerData customers[NUM_CUSTOMERS];


	do {

		printMenuOptions();
		getUserInput(&userSelection);

		if (userSelection == NUM_MENU_OPTIONS) { quit = true; }
		else if (userSelection > NUM_MENU_OPTIONS + 1) { cout << "Invalid Selection!"; }
		else {

			switch (userSelection) {

			case 1:
				addCustomers(customers, currentCustomers);
				break;

			case 2:
				if (currentCustomers == 0) { cout << "No customers to edit." << endl; }
				else { customerSelect(customers); }
				break;

			case 3:
				if (currentCustomers == 0) { cout << "No customers to search." << endl; }
				else { performSearch(customers, currentCustomers); }
				break;

			case 4:
				if (currentCustomers == 0) { cout << "No customers to display." << endl; }
				else { displayCustomers(customers, currentCustomers); }
				break;

			} // Case

		} // Customer Can be added

	} while (!quit);

}

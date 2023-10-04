#include "functions.h"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "constants.h"
#include "Patient.h"
#include "Procedure.h"
#include "Date.h"
#include "Name.h"

/* Remove New Line
* Removes the new line from the start of any incomming data
* == INPUTS ==
* string* string -- The string to be edited
*/
void removeNewLine(std::string* string) {

	string->erase(remove(string->begin(), string->end(), '\n'));

}

/* Build Name
* Builds a name struct based on some file
* == INPUTS ==
* ifstrea* patient -- The file to be read
* == OUTPUTS ==
* Name -- The built name
*/
Name buildName(std::ifstream* patientFile) {

	Name tempName;

	for (int i = 0; i < DATA_MEMBERS_NAME; i++) {

		switch (i) {

		case 0:
			getline(*patientFile, tempName.firstName, ',');
			removeNewLine(&tempName.firstName);
			break;
		case 1:
			getline(*patientFile, tempName.middleName, ',');
			removeNewLine(&tempName.middleName);
			break;
		case 2:
			getline(*patientFile, tempName.lastName, ',');
			removeNewLine(&tempName.lastName);
			break;

		}

	}

	return tempName;

}

/* Build Address
* Builds a Address struct from given file
* == INPUTS ==
* ifstrea* patient -- The file to be read
* == OUTPUTS ==
* Address -- The built address struct
*/
Address buildAddress(std::ifstream* patientFile) {

	Address tempAddress;

	for (int i = 0; i < DATA_MEMBERS_ADDRESS; i++) {

		switch (i) {

		case 0:
			getline(*patientFile, tempAddress.address, ',');
			removeNewLine(&tempAddress.address);
			break;
		case 1:
			getline(*patientFile, tempAddress.secondaryAddress, ',');
			removeNewLine(&tempAddress.secondaryAddress);
			break;
		case 2:
			getline(*patientFile, tempAddress.city, ',');
			removeNewLine(&tempAddress.city);
			break;
		case 3:
			getline(*patientFile, tempAddress.state, ',');
			removeNewLine(&tempAddress.state);
			break;
		case 4:
			*patientFile >> tempAddress.zipcode;
			break;
		}

	}

	return tempAddress;

}

/* Build Procedure
* Builds a procedure class from file
* == INPUTS ==
* ifstream* procedureFile -- The file to be read
* == OUTPUTS ==
* Procedure* -- The built procedures
*/
Procedure* buildProcedure(std::ifstream* procedureFile) {


	std::string name; std::getline(*procedureFile, name, ',');
	removeNewLine(&name);
	Date date = TODAYS_DATE;
	Name practitioner = buildName(procedureFile);
	double charge = 0; *procedureFile >> charge;

	Procedure* tempProcedure = new Procedure{ name,date,practitioner,charge };

	return tempProcedure;

}

/* Build Patient
* Builds an patient from data file and procedures
* == INPUTS ==
* * ifstream* patientFile -- The file to be read
* Procedure patientProcedures -- Either Nullptr or procedures pointer
* == OUTPUTS ==
* Patient* -- The built patient
*/
Patient* buildPatient(std::ifstream* patientFile, Procedure* patientProcedures) {

	Name name;
	Name emergencyName;
	Address address;
	std::string phoneNumber;
	std::string emergencyPhone;
	Patient* tempPatient;

	for (int i = 0; i < DATA_MEMBERS_PATIENT; i++) {

		if (patientFile->peek() == ',') { patientFile->get(); }

		switch (i) {

		case 0:
			name = buildName(patientFile);
			break;
		case 1:
			address = buildAddress(patientFile);
			break;
		case 2:
			std::getline(*patientFile, phoneNumber, ',');
			removeNewLine(&phoneNumber);
			break;
		case 3:
			emergencyName = buildName(patientFile);
			break;
		case 4:
			std::getline(*patientFile, emergencyPhone, ',');
			removeNewLine(&emergencyPhone);
			break;

		}

	}

	if (patientProcedures->getName() != "") { tempPatient = new Patient{ name,address,phoneNumber,emergencyName,emergencyPhone, patientProcedures }; } // Procedures Exist
	else { tempPatient = new Patient{ name,address,phoneNumber,emergencyName,emergencyPhone }; } // No procedures so far

	return tempPatient;

}

/* Build Patient -- OVERRIDE
* Builds an patient from data file
* == INPUTS ==
* * ifstream* patientFile -- The file to be read
* == OUTPUTS ==
* Patient* -- The built patient
*/
Patient* buildPatient(std::ifstream* patientFile) {

	Name name;
	Name emergencyName;
	Address address;
	std::string phoneNumber;
	std::string emergencyPhone;
	Patient* tempPatient;

	for (int i = 0; i < DATA_MEMBERS_PATIENT; i++) {

		if (patientFile->peek() == ',') { patientFile->get(); }

		switch (i) {

		case 0:
			name = buildName(patientFile);
			break;
		case 1:
			address = buildAddress(patientFile);
			break;
		case 2:
			std::getline(*patientFile, phoneNumber, ',');
			removeNewLine(&phoneNumber);
			break;
		case 3:
			emergencyName = buildName(patientFile);
			break;
		case 4:
			std::getline(*patientFile, emergencyPhone, ',');
			removeNewLine(&emergencyPhone);
			break;

		}

	}

	tempPatient = new Patient{ name,address,phoneNumber,emergencyName,emergencyPhone };
	return tempPatient;

}

/* Import File Data
* Ensures files can be opened and prints data to patient
* == INPUTS ==
* ifstream* patientFile -- The file to be read
* Procedure patientProcedures -- Either Nullptr or procedures pointer
* == OUTPUTS ==
* Patient* -- The built patient
*/
Patient* importFileData(std::ifstream* procedureFile, std::ifstream* patientFile) {

	Procedure* someProcedure = nullptr;
	Patient* somePatient = nullptr;

	if (procedureFile->peek() != -1) {

		someProcedure = buildProcedure(procedureFile);

		while (procedureFile->peek() != -1) {

			if (procedureFile->peek() == ',') { procedureFile->get(); }
			if (procedureFile->peek() == '\n') { procedureFile->get(); }
			if (procedureFile->peek() != '\n' && procedureFile->peek() != -1) { someProcedure->addProcedure(buildProcedure(procedureFile), someProcedure); };

		}

	}
	else { std::cout << "###Procedures file could not be found!###" << std::endl << std::endl; }

	if (patientFile->peek() != -1) {

		if (someProcedure != nullptr) { somePatient = buildPatient(patientFile, someProcedure); }
		else { somePatient = buildPatient(patientFile); }

	}
	else { std::cout << "Patients file could not be found!" << std::endl; }

	return somePatient;

}

/* Open Files
* Opens any dataFile passed
* == INPUTS ==
* ifstream* patientFile -- The file to be read
* ifstream* procedureFile -- The file to be read
*/
void openFiles(std::ifstream* patientFile, std::ifstream* procedureFile) {

	patientFile->open(PATIENT_FILE);
	procedureFile->open(PROCEDURES_FILE);

}

/* Perform Cleanup
* Closes files and deletes patient after finishing program
* == INPUTS ==
* ifstream* patientFile -- The file to be closed
* ifstream* procedureFile -- The file to be closed
* Patient* somePatient -- The patietnt to be deleted
*/
void performCleanup(std::ifstream* patientFile, std::ifstream* procedureFile, Patient* somePatient) {

	patientFile->close();
	procedureFile->close();
	delete somePatient->getProcedureList();
	delete somePatient;

}

/* Display Name
* Combines all portions of a name to one string
* == INPUTS ==
* Name name -- The name to be printed
* string identifier -- Pre name text
* stringstream& stream -- The stringstream to be printed
*/
void displayName(const Name name, const std::string identifier, std::stringstream& stream) {

	std::string tempString;

	tempString = "Dr. " + name.firstName + " " + name.middleName + " " + name.lastName;
	stream << std::setw(SETW_WIDTH) << identifier << tempString << std::endl;

}

/* Display Practitioner
* Takes the last name of a name varaible to print practitioner
* == INPUTS ==
* Name name -- The name to be printed
* string identifier -- Pre name text
* stringstream& stream -- The stringstream to be printed
*/
void displayPractitioner(const Name name, const std::string identifier, std::stringstream& stream) {

	std::string tempString;

	tempString = "Dr." + name.lastName;
	stream << std::setw(SETW_WIDTH) << identifier << tempString << std::endl;

}

/* Display Address
* Takes an address struct and creates a printed string
* == INPUTS ==
* Address address -- The address to be printed
* string identifier -- Pre print text
* stringstream& stream -- The stringstream to be printed
*/
void displayAddress(const Address address, std::stringstream& stream) {

	std::string tempString;

	tempString = address.address + ", " + address.secondaryAddress + ", " + address.city + ", " + address.state + ", " + std::to_string(address.zipcode);
	stream << std::setw(SETW_WIDTH) << "Patients address: " << tempString << std::endl;


}

/* Display Phone Number
* Takes the last name of a name varaible to print practitioner
* == INPUTS ==
* sting phoneNumber -- The phone number to be printed
* string identifier -- Pre print text
* stringstream& stream -- The stringstream to be printed
*/
void displayPhoneNumber(const std::string phoneNumber, const std::string identifier, std::stringstream& stream) {

	stream << std::setw(SETW_WIDTH) << identifier << phoneNumber << std::endl;

}

/* Display Date
* takes a date struct and builds a string
* == INPUTS ==
* Date date -- The data to be printed
* stringstream& stream -- The stringstream to be printed
*/
void displayDate(const Date date, std::stringstream& stream) {

	std::string tempString = std::to_string(date.month) + "/" + std::to_string(date.day) + "/" + std::to_string(date.year);
	stream << std::setw(SETW_WIDTH) << "Procedure's date: " << tempString << std::endl;

}

/* Display Charge
* takes double charge and converts it into a string
* == INPUTS ==
* double charge -- The data to be printed
* string identifier -- Pre print text
* stringstream& stream -- The stringstream to be printed
*/
void displayCharge(const double charge, const std::string identifier, std::stringstream& stream) {

	std::stringstream tempString;
	tempString << std::setprecision(2) << std::fixed << "$" << std::showpoint << charge;

	stream << std::setw(SETW_WIDTH) << identifier << tempString.str() << std::endl << std::endl;

}

/* Display Procedures
* Builds the procedures portion of of a patient
* == INPUTS ==
* const Procedure procedureList -- The procedures being printed
* stringstream& stream -- The stringstream to be printed
*/
void displayProcedures(const Procedure procedureList, std::stringstream& stream) {

	Procedure tempHead = procedureList;
	Procedure temp = procedureList;
	double total = 0;

	do {

		stream
			<< std::setw(SETW_WIDTH) << "Type: " << temp.getName() << std::endl;

		displayPractitioner(temp.getPractitioner(), "Practitioner's name: ", stream);
		displayDate(temp.getDate(), stream);
		displayCharge(temp.getCharge(), "Charge: ", stream);

		total += temp.getCharge();
		temp = *temp.getNext();

	} while (temp.getName() != tempHead.getName());

	displayCharge(total, "Total charge: ", stream);

}

/* Display Patient
* Builds the Patient portion of the output
* == INPUTS ==
* const Procedure procedureList -- The procedures being printed
* stringstream& stream -- The stringstream to be printed
*/
void displayPatient(const Patient* somePatient) {

	Patient tempPatient = *somePatient;
	std::stringstream patientData;
	patientData << std::left;

	displayName(tempPatient.getName(), "Patient's name: ", patientData); // Patient Name
	displayAddress(tempPatient.getAddress(), patientData); // Patient Address
	displayPhoneNumber(tempPatient.getPhoneNumber(), "Patient's conact: ", patientData); // Patient Phone Number
	displayName(tempPatient.getEmergencyName(), "Emergency conact's name: ", patientData); // Emergency contact name
	displayPhoneNumber(tempPatient.getEmergencyPhone(), "Emergency contact: ", patientData); // Emergency Phone Contact
	patientData << std::endl;

	if (tempPatient.getProcedureList() != nullptr) {

		displayProcedures(*tempPatient.getProcedureList(), patientData);
		std::cout << patientData.str();

	}
	else {

		std::cout << patientData.str();
		std::cout << "No procedures yet!" << std::endl;

	}

}

/* Patient Data
* Builds a patient from files and prints the output of the patient
*/
void patientData() {

	std::ifstream patientFile, procedureFile;
	openFiles(&patientFile, &procedureFile);

	Patient* somePatient = importFileData(&procedureFile, &patientFile);
	displayPatient(somePatient);

	performCleanup(&patientFile, &procedureFile, somePatient);

}
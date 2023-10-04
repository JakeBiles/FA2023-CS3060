#include "Patient.h"

#include <string>
#include "Name.h"
#include "Procedure.h"
#include "Address.h"

// Constructor
Patient::Patient(Name patientName, Address address, std::string phoneNumber, Name emergencyName, std::string emergencyPhone) {

	this->patientName = patientName;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->emergencyName = emergencyName;
	this->emergencyPhone = emergencyPhone;
	this->procedureList = nullptr;

}
Patient::Patient(Name patientName, Address address, std::string phoneNumber, Name emergencyName, std::string emergencyPhone, Procedure* procedureList) {

	this->patientName = patientName;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->emergencyName = emergencyName;
	this->emergencyPhone = emergencyPhone;
	this->procedureList = procedureList;

}

// Getters and Setters
Name Patient::getName() { return this->patientName; }
Address Patient::getAddress() { return this->address; }
std::string Patient::getPhoneNumber() { return this->phoneNumber; }
Name Patient::getEmergencyName() { return this->emergencyName; }
std::string Patient::getEmergencyPhone() { return this->emergencyPhone; }
Procedure* Patient::getProcedureList() { return this->procedureList; }

void Patient::setName(Name patientName) { this->patientName = patientName; }
void Patient::setAddress(Address address) { this->address = address; }
void Patient::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Patient::setEmergencyName(Name emergencyName) { this->emergencyName = emergencyName; }
void Patient::setEmergencyPhone(std::string emergencyPhone) { this->emergencyPhone = emergencyPhone; }

// Methods
void Patient::addProcedures(Procedure* procedure) {

	if (this->procedureList == nullptr) { this->procedureList = procedure; }
	else { this->procedureList->addProcedure(procedure, this->procedureList); }

}


#pragma once
#include <string>
#include "Name.h"
#include "Procedure.h"
#include "Address.h"

class Patient {

private: // Data Members

	Name patientName;
	Address address;
	std::string phoneNumber;
	Name emergencyName;
	std::string emergencyPhone;
	Procedure* procedureList;

public: // Constructor and Deconstructer

	Patient(Name, Address, std::string, Name, std::string);
	Patient(Name, Address, std::string, Name, std::string, Procedure*);

public: // Acessors and Mutator (Getters/Setterrs)

	Name getName();
	Address getAddress();
	std::string getPhoneNumber();
	Name getEmergencyName();
	std::string getEmergencyPhone();
	Procedure* getProcedureList();

	void setName(Name);
	void setAddress(Address);
	void setPhoneNumber(std::string);
	void setEmergencyName(Name);
	void setEmergencyPhone(std::string);

public:
	void addProcedures(Procedure*);

};

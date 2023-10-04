#pragma once
#include <string>
#include "Date.h"
#include "Name.h"

class Procedure {

private: // Data Members

	std::string procedureName;
	Date date;
	Name practitioner;
	double charge;

	Procedure* previousProcedure;
	Procedure* nextProcedure;

public: // Constructor and Deconstructor

	Procedure(std::string, Date, Name, double);

public: // Acessors and Mutators (Getters/Setters)

	std::string getName();
	Date getDate();
	Name getPractitioner();
	double getCharge();
	Procedure* getPrevious();
	Procedure* getNext();

	void setName(std::string);
	void setDate(Date);
	void setPractitioner(Name);
	void setCharge(double);
	void setPrevious(Procedure*);
	void setNext(Procedure*);

public: // Methods
	void addProcedure(Procedure*, Procedure*);

};
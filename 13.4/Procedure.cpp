#include "Procedure.h"

#include <string>
#include "Date.h"
#include "Name.h"

// Constructors and Deconstructor
Procedure::Procedure(std::string procedureName, Date date, Name practitioner, double charge) {

	this->procedureName = procedureName;
	this->date = date;
	this->practitioner = practitioner;
	this->charge = charge;

	this->previousProcedure = this;
	this->nextProcedure = this;

}

// Getters and Setters
std::string Procedure::getName() { return this->procedureName; }
Date Procedure::getDate() { return this->date; }
Name Procedure::getPractitioner() { return this->practitioner; }
double Procedure::getCharge() { return this->charge; }
Procedure* Procedure::getPrevious() { return this->previousProcedure; }
Procedure* Procedure::getNext() { return this->nextProcedure; }

void Procedure::setName(std::string procedureName) { this->procedureName = procedureName; }
void Procedure::setDate(Date date) { this->date = date; }
void Procedure::setPractitioner(Name practitioner) { this->practitioner = practitioner; }
void Procedure::setCharge(double charge) { this->charge = charge; }
void Procedure::setPrevious(Procedure* previousProcedure) { this->previousProcedure = previousProcedure; }
void Procedure::setNext(Procedure* nextProcedure) { this->nextProcedure = nextProcedure; }

// Methods
void Procedure::addProcedure(Procedure* procedure, Procedure* prodcedureList) {

	//														// Our Current Double Linked List:																	B<-A-B->A
	prodcedureList->setPrevious(procedure);					// We take the head, and make left the new point:													C<-A-B->A
	procedure->setNext(prodcedureList);						// We take the our new node and make right the head:												C<-C-A-B->A

	Procedure* tempList = prodcedureList;

	while (tempList->getNext()->getName() != prodcedureList->getName()) { tempList = tempList->getNext(); } // Traverse right untill head is found again:		C<-C-A-(B)->A

	procedure->setPrevious(tempList);						// We set our new node's left to this rightward element:											B<-C-A-B->A
	tempList->setNext(procedure);							// We set this rightward elements right to the new node:											C<-A-B-C->A

}
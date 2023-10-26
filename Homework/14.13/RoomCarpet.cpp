// Main Dependecy //
#include "RoomCarpet.h"
// Secondary Dependcies //
#include "FeetInches.h"
#include "RoomDimension.h"
#include "Functions.h"

// Constructors
RoomCarpet::RoomCarpet() {

	squareFtCost = 0;

}

RoomCarpet::RoomCarpet(RoomDeminsion& roomDeminsion) {

	double userInput;
	this->roomDeminsions = roomDeminsion;
	squareFtCost = getUserInput(userInput, "Please enter the price of each square foot: $");

}

RoomCarpet::RoomCarpet(RoomDeminsion& roomDeminsion, double squareFtCost) {

	this->roomDeminsions = roomDeminsion;
	this->squareFtCost = squareFtCost;

}

// Accessors 
double RoomCarpet::getPrice() const {

	return squareFtCost;

}

RoomDeminsion RoomCarpet::getDeminsions() const {

	return roomDeminsions;

}

// Methods
/* Calculate Price
*  Calculates the price of a given carpet job via the feet and inches of a dimension object
*  = Outputs =
*  Double -- The Price of the job
*/
double RoomCarpet::calculatePrice() {

	FeetInches&& temp = roomDeminsions.calculateArea();
	return (temp.getFeet() * squareFtCost) + (((double)temp.getInches() / 12) * squareFtCost);

}
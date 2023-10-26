// Main Dependecy //
#include "CarpetCalculator.h" 
// Secondary Dependcies //
#include <iostream>
#include <iomanip>
#include "Functions.h"
#include "RoomCarpet.h"
#include "RoomDimension.h"
#include "FeetInches.h"


// Constructors //
CarpetCalculator::CarpetCalculator() {

	int userInput = 0;
	FeetInches width{ getUserInput(userInput, "Please enter the inches of the width: "),getUserInput(userInput, "Please enter the feet of the width: ") };
	FeetInches height{ getUserInput(userInput, "Please enter the inches of the height: "), getUserInput(userInput, "Please enter the feet of the height: ") };

	RoomDeminsion temp{ width,height };
	roomCarpet = RoomCarpet{ temp };

}

CarpetCalculator::CarpetCalculator(RoomCarpet& roomCarpet) {

	this->roomCarpet = roomCarpet;

}

// Methods //
void CarpetCalculator::printSale() {

	RoomDeminsion&& tempDimensions = roomCarpet.getDeminsions();
	FeetInches&& tempArea = tempDimensions.calculateArea();

	std::cout
		<< "The price per square foot was: $" << roomCarpet.getPrice() << std::endl
		<< "The room ended up being: " << tempArea.getFeet() << "\"" << " and " << tempArea.getInches() << "'" << std::endl
		<< std::setprecision(2) << std::fixed << "Coming to a grand total of: $" << roomCarpet.calculatePrice() << std::endl;

}
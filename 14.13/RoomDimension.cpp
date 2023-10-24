// Main Dependency //
#include "RoomDimension.h"
// Secondary Dependcies //
#include "FeetInches.h"


// Constructors
RoomDeminsion::RoomDeminsion() {

}

RoomDeminsion::RoomDeminsion(FeetInches& width, FeetInches& height) {

	this->width = width;
	this->height = height;

}

RoomDeminsion::RoomDeminsion(const RoomDeminsion& copy) {

	this->height = copy.height;
	this->width = copy.width;

}

// Methods 
/* Calculate Area
*  Calculates the price of a given carpet via the feet and inches of two FeetInches objects
*  = Outputs =
*  FeetInches -- The area of the carpet
*/
FeetInches RoomDeminsion::calculateArea() {

	FeetInches temp;
	temp = width * height;

	return temp;

}
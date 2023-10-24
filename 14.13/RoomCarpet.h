#pragma once
#include "RoomDimension.h"

class RoomCarpet {

private: // Data Members 
	RoomDeminsion roomDeminsions;
	double squareFtCost;

public: // Constructors 
	RoomCarpet();
	RoomCarpet(RoomDeminsion& roomDeminsion);
	RoomCarpet(RoomDeminsion& roomDeminsion, double squareFtCost);

public: // Accessors
	double getPrice() const;
	RoomDeminsion getDeminsions() const;

public: // Methods
	double calculatePrice();
};
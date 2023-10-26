#pragma once
#include "FeetInches.h"

class RoomDeminsion {

private: // Data Members // 
	FeetInches width;
	FeetInches height;

public: // Constructors //
	RoomDeminsion();
	RoomDeminsion(FeetInches& width, FeetInches& height);
	RoomDeminsion(const RoomDeminsion& copy);

public: // Methods
	FeetInches calculateArea();

};
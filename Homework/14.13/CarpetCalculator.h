#pragma once
#include "RoomCarpet.h"

class CarpetCalculator
{
private:
	RoomCarpet roomCarpet;

public:
	CarpetCalculator();
	CarpetCalculator(RoomCarpet& roomCarpet);

public:
	void printSale();


};
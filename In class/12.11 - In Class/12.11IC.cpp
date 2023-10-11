#include <iostream>
#include "Division.h"
#include "Constants.h"

#include <fstream>


int main() {


	std::fstream corpFile(DATA_FILE, std::ios::in | std::ios::out);

	Division east, west, south, north;

	int qtr = 0;

	strcpy_s(east.divName, "East");
	strcpy_s(west.divName, "West");
	strcpy_s(south.divName, "South");
	strcpy_s(north.divName, "North");

	std::cout << "Enter the quaterly salses data for division East:\n";
	for (qtr = 1; qtr < 4; qtr++) {

		east.quarter = qtr;

	}


	return 0;
}
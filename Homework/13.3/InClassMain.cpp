#include <iostream>
#include "13.3Functions.h"
#include "Car.h"

int main2() {

	Car porsche(2006, "Porsche");

	int count = 0;

	std::cout
		<< "Current speed: "
		<< porsche.getSpeed()
		<< std::endl;

	accelerationPortion(&porsche);
	brakePortion(&porsche);

	return 0;

}
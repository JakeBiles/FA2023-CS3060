#include "13.3Functions.h"

#include <iostream>
#include "Constants.h"
#include "Car.h"

void accelerationPortion(Car* someCarPTR) {

	std::cout
		<< "==================" << std::endl
		<< "===ACCELERATING===" << std::endl
		<< "==================" << std::endl;

	for (size_t i = 0; i < NUM_ACCEL; i++) {

		std::cout << someCarPTR->getMake() << " accelerating! Current speed: " << someCarPTR->getSpeed() << " MPH" << std::endl;
		someCarPTR->accelerate();
		std::cout << someCarPTR->getMake() << "'s new speed: " << someCarPTR->getSpeed() << " MPH" << std::endl << std::endl;

	}

}

void brakePortion(Car* someCarPTR) {

	std::cout
		<< "=================" << std::endl
		<< "=====BRAKING=====" << std::endl
		<< "=================" << std::endl;

	for (size_t i = 0; i < NUM_ACCEL; i++) {

		std::cout << someCarPTR->getMake() << " breaking! Current speed: " << someCarPTR->getSpeed() << " mph" << std::endl;
		someCarPTR->brake();
		std::cout << someCarPTR->getMake() << " speed: " << someCarPTR->getSpeed() << " mph" << std::endl << std::endl;

	}

}

void carTest() {

	Car someCar{ 1999, "Mazda" };
	accelerationPortion(&someCar);
	brakePortion(&someCar);

}
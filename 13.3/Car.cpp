#include "car.h"

#include <string>

// Constructors
Car::Car(int yearModel, std::string make) {

	this->speed = 0;
	this->yearModel = yearModel;
	this->make = make;

}

// Accessors (Getters/Setters)
int Car::getSpeed() {

	return this->speed;

}

int Car::getYear() {

	return this->yearModel;

}

std::string Car::getMake() {

	return this->make;

}

// Methods
void Car::accelerate() {

	this->speed += 5;

}

void Car::brake() {

	this->speed += -5;

}
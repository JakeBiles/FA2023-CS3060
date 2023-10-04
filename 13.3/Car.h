#pragma once
#include <string>

class Car {

private:

	int speed;
	int yearModel;
	std::string make;

public: // Constructor 
	Car(int, std::string);

public: // Accessors(Getters / Setters)
	int getSpeed();
	int getYear();
	std::string getMake();

public: // Methods
	void accelerate();
	void brake();

};


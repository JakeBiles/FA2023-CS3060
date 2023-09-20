#include <iostream>
using namespace std;

float userInput(string prompt) {

	float input;
	cout << prompt;
	cin >> input;

	return input;

}

float kineticEnergy(float mass, float velocity) {

	return .5*(mass*(velocity*velocity));

}

void program() {

	float mass, velocity;
	mass = userInput("Please enter the mass of the object: ");
	velocity = userInput("Now please enter a velocity: ");

	cout << "The kinetic energy of this object is " << kineticEnergy(mass, velocity);

}

int main() {

	program();

	return 0;
}
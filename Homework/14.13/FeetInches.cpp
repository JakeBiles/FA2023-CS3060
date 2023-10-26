// Main Dependency //
#include "FeetInches.h"
// Secondary Dependecies //
#include <cstdlib>  

// Constructors //
FeetInches::FeetInches(int i, int f) {
	feet = f;
	inches = i;
	simplify();

}

FeetInches::FeetInches(FeetInches& copy) {

	this->feet = copy.feet;
	this->inches = copy.inches;

}

// Mutators //
void FeetInches::setFeet(int f) {

	feet = f;

}

void FeetInches::setInches(int i)
{
	inches = i;
	simplify();
}

// Accessors //
int FeetInches::getFeet() const {

	return feet;

}

int FeetInches::getInches() const {

	return inches;

}

// Methods //
void FeetInches::simplify()
{

	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}

	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}

}

// Operators //
FeetInches FeetInches::operator+ (const FeetInches& right)
{

	FeetInches temp;

	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;

}

void FeetInches::operator+= (FeetInches& right)
{

	inches = inches + right.inches;
	feet = feet + right.feet;
	simplify();

}

FeetInches FeetInches::operator- (const FeetInches& right)
{

	FeetInches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;

}

void FeetInches::operator-= (FeetInches& right)
{

	inches = inches - right.inches;
	feet = feet - right.feet;
	simplify();

}

FeetInches FeetInches::operator * (const FeetInches& right) {

	FeetInches temp;

	temp.inches = inches * right.inches;
	temp.feet = feet * right.feet;
	temp.simplify();
	return temp;

}
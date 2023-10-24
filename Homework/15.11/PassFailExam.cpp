// Main Dependency //
#include "PassFailExam.h"
// Secondary Dependencies //
#include "Constants.h"

// Getters //
double PassFailExam::getMinGrade() const {

	return this->minGrade;

}

// Setters //
void PassFailExam::setMinGrade(double minGrade) {

	this->minGrade = minGrade;

}

// Methods //
void PassFailExam::determineIsPassing() {

	if (this->getScore() >= minGrade)  this->setIsPassingGrade(true);
	else  this->setIsPassingGrade(false);

}
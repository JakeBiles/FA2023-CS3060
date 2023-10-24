// Main Dependency //
#include "Lab.h"
// Secondary Dependencies //

// Constructors //
Lab::Lab() {}
Lab::Lab(double score) {

	this->setScore(score);
	this->determineIsPassing();

}


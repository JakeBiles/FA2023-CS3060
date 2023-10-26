// Main Dependency //
#include "GradedActivity.h"
// Secondary Dependencies //
#include "Constants.h"

// Getters //
double GradedActivity::getScore() const {

	return score;

}
bool GradedActivity::isPassing() const {


	return this->isPassingGrade;

}

// Setters //
void GradedActivity::setScore(double score) {

	this->score = score;
	determineIsPassing();

}
void GradedActivity::setIsPassingGrade(bool isPassingGrade) {

	this->isPassingGrade = isPassingGrade;

}

// Methods // 
void GradedActivity::determineIsPassing() {

	if (score >= LOWEST_PASSING_GRADE) { this->isPassingGrade = true; }

}

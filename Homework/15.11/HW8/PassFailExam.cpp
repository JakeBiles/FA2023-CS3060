// Main Dependency //
#include "PassFailExam.h"
// Secondary Dependencies //

// Getters //
double PassFailExam::getMinGrade() const {

	return this->minGrade;

}

// Setters //
void PassFailExam::setMinGrade(double minGrade) {

	this->minGrade = minGrade;

}

// Derrived Setters //
void PassFailExam::setScore(double score) {

	this->GradedActivity::setScore(score);
	determineIsPassing();

}
void PassFailExam::setNumCorrect(unsigned int numCorrect) {

	this->setNumCorrect(numCorrect);
	setScore(((double)numCorrect / (double)this->getNumQuestions()) * 100);

}

// Methods //
void PassFailExam::determineIsPassing() {

	if (this->getScore() >= this->minGrade)  this->setIsPassingGrade(true);
	else  this->setIsPassingGrade(false);

}
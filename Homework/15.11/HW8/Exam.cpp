// Main Dependency //
#include "Exam.h"
// Secondary Dependencies //

// Getters //
unsigned int Exam::getNumQuestions() const {

	return this->numQuestions;

}
unsigned int Exam::getNumCorrect() const {

	return this->numCorrect;

}

// Setters //
void Exam::setNumQuestions(unsigned int numQuestions) {

	this->numQuestions = numQuestions;

}
void Exam::setNumCorrect(unsigned int numCorrect) {

	this->numCorrect = numCorrect;
	if (numQuestions != 0) setScore(((double)numCorrect / (double)numQuestions) * 100);

}

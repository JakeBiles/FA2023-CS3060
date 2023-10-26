// Main Dependency //
#include "CourseGrades.h"
// Secondary Dependencies //
#include <iostream>

// Constructors //
CourseGrades::CourseGrades() {}
CourseGrades::CourseGrades(Lab& lab, PassFailExam& passFailExam, Essay& essay, FinalExam& finalExam) {

	this->grades[0] = lab;
	this->grades[1] = passFailExam;
	this->grades[2] = essay;
	this->grades[3] = finalExam;

}

// Setters //
void CourseGrades::setLab(Lab& lab) {

	this->grades[0] = lab;

}
void CourseGrades::setPassFailExam(PassFailExam& passFailExam) {

	this->grades[1] = passFailExam;

}
void CourseGrades::setEssay(Essay& essay) {

	this->grades[2] = essay;

}
void CourseGrades::setFinalExam(FinalExam& finalExam) {

	this->grades[3] = finalExam;

}

// Methods //
void CourseGrades::print() {

	for (size_t i = 0; i < NUM_GRADED_ACTIVITIES; i++) {

		if (!grades[i].isPassing()) std::cout << "F" << " " << grades[i].getScore() << "%\n";
		else if (grades[i].getScore() >= 90) std::cout << "A" << " " << grades[i].getScore() << "%\n";
		else if (grades[i].getScore() >= 80) std::cout << "B" << " " << grades[i].getScore() << "%\n";
		else if (grades[i].getScore() >= 70) std::cout << "C" << " " << grades[i].getScore() << "%\n";
		else if (grades[i].getScore() >= 60) std::cout << "D" << " " << grades[i].getScore() << "%\n";


	}

}
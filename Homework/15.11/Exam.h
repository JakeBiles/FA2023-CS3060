#pragma once
#include "GradedActivity.h"

class Exam : public GradedActivity
{
private: // Data Members
	unsigned int numQuestions;
	unsigned int numCorrect;

public: // Constructors
	Exam(unsigned int numQuestions = 0, unsigned int numCorrect = 0) {

		this->numQuestions = numQuestions;
		this->numCorrect = numCorrect;

		if (numQuestions != 0) {

			setScore(((double)numCorrect / (double)numQuestions) * 100);
			determineIsPassing();

		}

	}

public: // Getters
	unsigned int getNumQuestions() const;
	unsigned int getNumCorrect() const;

public: // Setters
	void setNumQuestions(unsigned int);
	void setNumCorrect(unsigned int);

};

#pragma once
#include "Exam.h"
#include "Constants.h"

class PassFailExam : public Exam
{

private: // Data Members 
	double minGrade;

public: // Constructors
	PassFailExam(double minGrade = LOWEST_PASSING_GRADE, unsigned int numQuestions = 0, unsigned int numCorrect = 0) : Exam(numQuestions, numCorrect) {

		this->minGrade = minGrade;
		if (numQuestions > 0) determineIsPassing();

	}

public: // Getters
	double getMinGrade() const;

public: // Setters
	void setMinGrade(double);

protected:
	virtual void determineIsPassing() override;
};

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
		if (numQuestions != 0) {

			setScore(((double)numCorrect / (double)numQuestions) * 100);

		}

	}

public: // Getters
	double getMinGrade() const;

public: // Setters
	void setMinGrade(double);
	virtual void setNumCorrect(unsigned int) override;

protected: // Protected Setter
	virtual void setScore(double);

protected:
	virtual void determineIsPassing() override;
};

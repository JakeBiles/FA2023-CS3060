#pragma once
#include "Exam.h"

class FinalExam : public Exam
{
public:
	FinalExam(unsigned int numQuestions = 0, unsigned int numCorrect = 0) : Exam(numQuestions, numCorrect) {}

};

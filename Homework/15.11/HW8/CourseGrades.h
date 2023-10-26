#pragma once
#include "Constants.h"
#include "GradedActivity.h"
#include "Essay.h"
#include "Lab.h"
#include "FinalExam.h"
#include "PassFailExam.h"

class CourseGrades
{
private: // Data Members
	GradedActivity grades[NUM_GRADED_ACTIVITIES];

public: // Constructors
	CourseGrades();
	CourseGrades(Lab&, PassFailExam&, Essay&, FinalExam&);

public: // Setters
	void setLab(Lab&);
	void setPassFailExam(PassFailExam&);
	void setEssay(Essay&);
	void setFinalExam(FinalExam&);

public: // Methods
	void print();

};
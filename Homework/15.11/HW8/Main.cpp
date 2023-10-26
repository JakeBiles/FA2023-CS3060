#include <limits>
#include "GradedActivity.h"
#include "Lab.h"
#include "Essay.h"
#include "PassFailExam.h"
#include "FinalExam.h"
#include "CourseGrades.h"
#include "JacobCommon.h"

void courseGradeCalculator();

int main() {

	courseGradeCalculator();
	return 0;

}

void courseGradeCalculator() {

	double scoreInput = 0;
	unsigned int questionsInput = 0;

	Lab someLab{ getValidUserInput(scoreInput,"Student Lab", "Please enter the score for the student's lab: ",200.00,0.00) };

	PassFailExam somePFExam{
		getValidUserInput(scoreInput,"Pass-Fail Exam", "Please enter the passing grade for the PF exam: ",100.00,0.00),
		getValidUserInput(questionsInput,"Pass-Fail Exam", "Please enter the number of questions of the PF exam: ",UINT_MAX,(unsigned)1),
		getValidUserInput(questionsInput,"Pass-Fail Exam", "Please enter the number of questions the student got correct: ",UINT_MAX,(unsigned)0)
	};

	Essay someEssay{ getValidUserInput(scoreInput, "Student Essay", "Please enter the score for the student's essay: ", 200.00, 0.00) };

	FinalExam someFinal{
		getValidUserInput(questionsInput, "Final Exam", "Please enter the number of questions this exam has: ", UINT_MAX, (unsigned)1),
		getValidUserInput(questionsInput,"Final Exam", "Please enter the number of questions the student got correct: ", UINT_MAX,(unsigned)0)
	};

	CourseGrades courseGrades{ someLab,somePFExam,someEssay,someFinal };

	courseGrades.print();


}
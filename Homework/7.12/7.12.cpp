#include <iostream>
#include <iomanip>
using namespace std;

// Constants //
const size_t NUM_STUDENTS = 5;
const size_t NUM_TESTS = 4;

// Prototypes //
void studentSetUp(string[], double[][NUM_TESTS]);
void calculateLetterGrade(char[], double[], double[][NUM_TESTS]);
void displayGrades(string[], char[], double[], double[][NUM_TESTS]);
void letterGradeCalculater();

// Main //
int main() {

	letterGradeCalculater();
	return 0;

}

// Implementation // 
void studentSetUp(string studentNameArray[], double studentScoresArray[][NUM_TESTS]) {

	for (size_t i = 0; i < NUM_STUDENTS; i++) {

		cout << "Please enter the name of student " << (i + 1) << ": ";
		cin >> studentNameArray[i];
		cout << endl;
		cin.clear();

		for (size_t j = 0; j < NUM_TESTS; j++) {

			do {

				cout << "Please enter " << studentNameArray[i] << "'s test score for test #" << (j + 1) << ": ";
				cin >> studentScoresArray[i][j];
				cout << endl;
				cin.clear();

			} while ((studentScoresArray[i][j] > 100 || studentScoresArray[i][j] < 0) && (cout << "The student's test score must at least 0 and below 100!" << endl));

		}

		cout << endl;

	}

}

void calculateLetterGrade(char letterGradeArray[], double averageScoreArray[], double studentScoresArray[][NUM_TESTS]) {

	double average;

	for (size_t i = 0; i < NUM_STUDENTS; i++) {

		average = 0;

		for (size_t j = 0; j < NUM_TESTS; j++) { average += studentScoresArray[i][j]; }

		average = average / NUM_TESTS;
		averageScoreArray[i] = average;

		if ((average < 60 || average == 0) && (letterGradeArray[i] = 'F'));
		if (average >= 60 && (letterGradeArray[i] = 'D'));
		if (average >= 70 && (letterGradeArray[i] = 'C'));
		if (average >= 80 && (letterGradeArray[i] = 'B'));
		if (average >= 80 && (letterGradeArray[i] = 'A'));

	}

}

void displayGrades(string studentNameArray[], char letterGradeArray[], double averageScoreArray[], double studentScoresArray[][NUM_TESTS]) {

	cout << "Name \t";
	for (size_t i = 0; i < NUM_STUDENTS; i++) { cout << setw(9) << studentNameArray[i]; }
	cout << endl;

	for (size_t i = 0; i < NUM_TESTS; i++) {

		cout << "Test #" << i + 1 << "\t";
		for (size_t j = 0; j < NUM_STUDENTS; j++) { cout << setw(9) << studentScoresArray[j][i]; }
		cout << endl;

	}

	cout << "Average ";
	for (size_t i = 0; i < NUM_STUDENTS; i++) { cout << setw(9) << averageScoreArray[i]; }
	cout << endl;

	cout << "Letter  ";
	for (size_t i = 0; i < NUM_STUDENTS; i++) { cout << setw(9) << letterGradeArray[i]; }
	cout << endl;

}

void letterGradeCalculater() {

	string studentNames[NUM_STUDENTS];
	char letterGrades[NUM_STUDENTS];
	double averageGrade[NUM_STUDENTS];
	double studentTestScores[NUM_STUDENTS][NUM_TESTS];

	studentSetUp(studentNames, studentTestScores);
	calculateLetterGrade(letterGrades, averageGrade, studentTestScores);
	displayGrades(studentNames, letterGrades, averageGrade, studentTestScores);

}


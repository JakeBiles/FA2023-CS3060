#include <iostream>
#include <unordered_map>
#include <string>

const size_t NUM_TESTS = 4;
const size_t NUM_STUDENTS = 1;


struct Student
{

	std::string name;
	double scores[NUM_TESTS];
	double averageScore = 0;
	char letterGrade = ' ';

};

const std::unordered_map<char, std::string> geekMap = {

	{'A',"Superkalifragalistic"},
	{'U',"Uber Geek"},
	{'G',"Geek"},
	{'S',"Smart Dude"},
	{'H',"High Brow"},
	{'C',"Calculus Challenged"},
	{'L',"Lowbrow"}

};

double calculateGrade(Student*);
void applyLetterGrade(Student*, double);

int main() {

	Student students[7];
	std::string temp = "";

	for (size_t i = 0; i < NUM_STUDENTS; i++) {

		std::cout << "Please enter student " << i + 1 << " name!" << std::endl;
		std::cin >> students[i].name;

		for (size_t j = 0; j < NUM_TESTS; j++) {

			bool isValid = false;

			while (!isValid) {

				std::cout << "Please enter " << students[i].name << "'s test score for the " << j + 1 << " test." << std::endl;
				std::cin >> students[i].scores[j];
				if (students[i].scores[j] >= 0 && students[i].scores[j] <= 100) isValid = true;
				else std::cout << "Out of range!" << std::endl;

			}

		}

	}

	for (size_t i = 0; i < NUM_STUDENTS; i++) {
		students[i].averageScore = calculateGrade(&students[i]);
		applyLetterGrade(&students[i], students[i].averageScore);
	}

	std::cout << std::endl;
	for (size_t i = 0; i < NUM_STUDENTS; i++) {
		std::cout
			<< "Student: " << students[i].name << std::endl
			<< "Average Score: " << students[i].averageScore << std::endl
			<< "Letter grade: " << students[i].letterGrade << std::endl
			<< "Nerd type: " << geekMap.at(students[i].letterGrade) << std::endl;
	}


	return 0;

}

double calculateGrade(Student* someStudent) {

	double total = 0;

	for (size_t i = 0; i < NUM_TESTS; i++) {

		total += someStudent->scores[i];

	}

	double temp = total / (double)NUM_TESTS;

	return temp;

}

void applyLetterGrade(Student* someStudent, double average) {

	if (average >= 95) {
		someStudent->letterGrade = 'A';
	}
	else if (average >= 90) {
		someStudent->letterGrade = 'U';
	}
	else if (average >= 85.2) {
		someStudent->letterGrade = 'G';
	}
	else if (average >= 80) {
		someStudent->letterGrade = 'S';
	}
	else if (average >= 70) {
		someStudent->letterGrade = 'H';
	}
	else if (average >= 60) {
		someStudent->letterGrade = 'C';
	}
	else if (average >= 0) {
		someStudent->letterGrade = 'L';
	}


}
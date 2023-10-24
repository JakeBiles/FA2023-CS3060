#include <iostream>
#include <chrono>
#include "GradedActivity.h"
#include "PassFailExam.h"
#include "Lab.h"

const size_t TIME_RAN = 100;

int main() {

	double average = 0;

	for (size_t i = 0; i < TIME_RAN; i++) {
		std::chrono::steady_clock::time_point nanoTime = std::chrono::high_resolution_clock::now();
		//
		PassFailExam somePFExam{ 70, 52,34 };
		std::cout << somePFExam.getScore() << std::endl;
		//
		std::chrono::nanoseconds runTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - nanoTime);
		std::cout << "Runtime: " << runTime.count() << " ns" << std::endl;
		average += (double)runTime.count();
	}

	std::cout << "Average: " << average / TIME_RAN << " ns";

	// left off -- completed PassFailExam
	// Need to complete -- Final Exam
	// The Final Class to contain all of these objects?



	return 0;

}
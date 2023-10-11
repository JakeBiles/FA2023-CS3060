#include "Functions.h"
#include <iostream>
#include <fstream>

int countSentances(std::string someFile) {

	const int SIZE = 500;
	char input[SIZE];
	std::fstream inputFile;
	int numSentances = 0;

	inputFile.open(someFile, std::ios::in);

	if (!inputFile) {
		std::cout << "ERROR: Could not open file." << std::endl;
		exit(0);
	}

	inputFile.getline(input, SIZE);

}

int countWords(std::string someFile){

	const int SIZE = 500;
	char input[SIZE];
	std::fstream file;
	int numbers = 0;

	file.open(someFile, std::ios::in);

	if (!file) {
		std::cout << "File could not be found";
	}

}
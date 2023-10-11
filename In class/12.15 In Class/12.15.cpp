#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
#include "Functions.h"
#include "Constats.h"


int main() {

	int sentences = 0, words = 0;
	double average = 0;

	sentences = countSentances(FILE_NAME);
	words = countWords(FILE_NAME);

	average = static_cast<double>(words) / sentences;


	std::cout
		<< "The file contains: " << words << " words" << std::endl
		<< "As well it contains: " << sentences << " sentences" << std::endl
		<< "With an average of: " << std::setprecision(1) << std::fixed << average << " words per sentance."



}
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <sstream>

using namespace std;


// STRUCTURES //
struct WeatherData {

	double
		totalRain = 0,
		highTemp = 0,
		lowTemp = 0,
		averageTemp = 0;

};


// CONSTANTS //
const double MAX_TEMP = 140;
const double MIN_TEMP = -100;
const int SET_WIDTH_SPACE = 15;
const double NUM_DATA_POINTS = 4;
const size_t NUN_MONTHS = 12;
const unordered_map<size_t, string> monthMap = {

	{0,"January"},
	{1,"Febuary"},
	{2,"March"},
	{3,"April"},
	{4,"May"},
	{5,"June"},
	{6,"July"},
	{7,"August"},
	{8,"September"},
	{9,"October"},
	{10,"November"},
	{11,"December"},

};


// TEMPLATE FUNCTIONS //
/* Get User Input
* Handles a generic input and performs cleanup for cin
* == INPUTS ==
* Type T (generic) userSelection -- variable taking input
*/
template <typename T>
void getUserInput(T* userSelection) {

	cout << endl;
	cout << "Entry: ";
	cin >> *userSelection;
	system("cls");
	cin.ignore();

}


// PROTOTYPES //
void setTemp(double&, const string, const string);
void setRain(double&, const string);
double calculateAverage(const double, const double);
void assignData(WeatherData*);
double findTotalRain(const WeatherData*);
size_t findHighestTemp(const WeatherData*);
size_t findLowestTemp(const WeatherData*);
double findYearlyAverage(const WeatherData*);
void buildHeader(stringstream&);
void buildTotalRain(const WeatherData*, stringstream&);
void buildHighestTemp(const WeatherData*, stringstream&);
void buildLowestTemp(const WeatherData*, stringstream&);
void buildAverage(const WeatherData*, const string, stringstream&);
void buildStatistics(const WeatherData*, stringstream&);
void printData(const WeatherData*);
void weatherCalculator();

// MAIN //
int main() {

	weatherCalculator();

	return 0;

}


// IMPLEMENTATION //
/* Set Temp
* Gets a temperature within selected range
* == INPUTS ==
* double& temperaturePTR - The value being assigned
* const string tempText - Flavor text for specific temp hight/low
* const string monthText - The month to be printed to
*/
void setTemp(double& temperaturePTR, const string tempText, const string monthText) {

	double userInput = 0;
	bool validInput = false;

	do {

		printf("-- %s -- \n", monthText.c_str());
		printf("Please enter a temperature %s between the range of (%.2f to %.2f).\n", tempText.c_str(), MAX_TEMP, MIN_TEMP);
		getUserInput(&userInput);

		if (userInput > MAX_TEMP || userInput < MIN_TEMP) { cout << "Out of range!" << endl; }
		else { validInput = true; temperaturePTR = userInput; }

	} while (!validInput);

}

/* Set Rain
* Gets the rain amount month
* == INPUTS ==
* double& temperaturePTR - The value being assigned
* const string tempText - Flavor text for specific temp hight/low
* const string monthText - The month to be printed to
*/
void setRain(double& rainPTR, const string monthText) {

	double userInput = 0;
	bool validInput = false;

	do {

		printf("-- %s -- \n", monthText.c_str());
		cout << "Please enter the amount of rain the area received." << endl;
		getUserInput(&userInput);

		if (userInput < 0) { cout << "An area cant have a negitive amount of rain!" << endl; }
		else { validInput = true; rainPTR = userInput; }

	} while (!validInput);

}

/* Calculate Average
* Calculates the average temperature per month
* == INPUTS ==
* const double highTemp -- The highest temp of the month
* const double highTemp -- The lowest temp of the month
* == OUTPUTS ==
* double -- The average of the (high + low) / 2
*/
double calculateAverage(const double highTemp, const double lowTemp) {

	return ((highTemp + lowTemp) / 2);

}

/* Assign Data
* Calls each setter to initilize each month's weather data
* == INPUTS ==
* WeatherData* -- The list of weather Data to be edited
*/
void assignData(WeatherData* weatherPTR) {

	WeatherData* temp;

	for (size_t i = 0; i < NUN_MONTHS; i++) {

		temp = (weatherPTR + i);

		setTemp(temp->highTemp, "high", monthMap.at(i));
		setTemp(temp->lowTemp, "low", monthMap.at(i));
		setRain(temp->totalRain, monthMap.at(i));
		temp->averageTemp = calculateAverage((weatherPTR + i)->highTemp, (weatherPTR + i)->lowTemp);

	}

}

/* Calculate Average
* Calculates the average temperature per month
* == INPUTS ==
* const WeatherData* weatherPTR -- Initil WeatherData variable to read through
* == OUTPUTS ==
* double -- The total rain amount throughout each month
*/
double findTotalRain(const WeatherData* weatherPTR) {

	double total = 0;
	for (size_t i = 0; i < NUN_MONTHS; i++) { total += (weatherPTR + i)->totalRain; }

	return total;

}

/* Find Highest Temp
* Finds the highest temp of the year
* == INPUTS ==
* const WeatherData* weatherPTR -- Initil WeatherData variable to read through
* == OUTPUTS ==
* size_t -- The lowest temp element throught the year
*/
size_t findHighestTemp(const WeatherData* weatherPTR) {

	size_t highestElement = 0;
	double highestNumber = 0;

	for (size_t i = 0; i < NUN_MONTHS; i++) { if (highestNumber < (weatherPTR + i)->highTemp) { highestElement = i; } }

	return highestElement;

}

/* Find Lowest Temp
* Finds the lowest temp of the year
* == INPUTS ==
* const WeatherData* weatherPTR -- Initil WeatherData variable to read through
* == OUTPUTS ==
* size_t -- The lowest temp element throught the year
*/
size_t findLowestTemp(const WeatherData* weatherPTR) {

	size_t lowestElement = 0;
	double highestNumber = 0;

	for (size_t i = 0; i < NUN_MONTHS; i++) { if (highestNumber > (weatherPTR + i)->lowTemp) { lowestElement = i; } }

	return lowestElement;

}

/* Find Yearly Average
* Finds the average temp throught the year
* == INPUTS ==
* const WeatherData* weatherPTR -- Initil WeatherData variable to read through
* == OUTPUTS ==
* double -- The average of throughout the years (all average / 12)
*/
double findYearlyAverage(const WeatherData* weatherPTR) {

	double tempHigh = 0;
	double tempLow = 0;
	double total = 0;

	for (size_t i = 0; i < NUN_MONTHS; i++) {

		tempHigh = (weatherPTR + i)->highTemp;
		tempLow = (weatherPTR + i)->lowTemp;

		total += calculateAverage(tempHigh, tempLow);

	}

	return (total / NUN_MONTHS);

}

/* Build Header
* Builds the header portion of the printed string
* == INPUTS ==
* stringstream& -- The stringstream to be edited
*/
void buildHeader(stringstream& builtString) {

	stringstream temp;

	builtString << left << setw(SET_WIDTH_SPACE) << "";
	for (size_t i = 0; i < NUN_MONTHS; i++) {

		temp.str("");
		temp << monthMap.at(i)[0] << monthMap.at(i)[1] << monthMap.at(i)[2] << ".";
		builtString << setw(SET_WIDTH_SPACE) << temp.str();

	}
	builtString << endl;

}

/* Build Total Rain
* Builds the rain portion of printed string
* == INPUTS ==
* stringstream& -- The stringstream to be edited
*/
void buildTotalRain(const WeatherData* weatherPTR, const string dataPointType, stringstream& builtString) {


	builtString << setw(SET_WIDTH_SPACE) << dataPointType;
	for (size_t i = 0; i < NUN_MONTHS; i++) { builtString << setw(SET_WIDTH_SPACE) << (weatherPTR + i)->totalRain; }
	builtString << endl;

}

/* Build Highest Temp
* Builds the Highest Temp portion of printed string
* == INPUTS ==
* const WeatherData* weatherPTR - Start of the WeatherData list
* stringstream& -- The stringstream to be edited
*/
void buildHighestTemp(const WeatherData* weatherPTR, stringstream& builtString) {


	builtString << setw(SET_WIDTH_SPACE) << "Highest Temp";
	for (size_t i = 0; i < NUN_MONTHS; i++) { builtString << setw(SET_WIDTH_SPACE) << (weatherPTR + i)->highTemp; }
	builtString << endl;

}

/* Build Lowest Temp
* Builds the lowest Temp portion of printed string
* == INPUTS ==
* const WeatherData* weatherPTR - Start of the WeatherData list
* stringstream& -- The stringstream to be edited
*/
void buildLowestTemp(const WeatherData* weatherPTR, stringstream& builtString) {


	builtString << setw(SET_WIDTH_SPACE) << "Lowest Temp";
	for (size_t i = 0; i < NUN_MONTHS; i++) { builtString << setw(SET_WIDTH_SPACE) << (weatherPTR + i)->lowTemp; }
	builtString << endl;

}

/* Build Average
* Builds the average Temp portion of printed string
* == INPUTS ==
* const WeatherData* weatherPTR - Start of the WeatherData list
* stringstream& -- The stringstream to be edited
*/
void buildAverage(const WeatherData* weatherPTR, stringstream& builtString) {


	builtString << setw(SET_WIDTH_SPACE) << "Temp Average";
	for (size_t i = 0; i < NUN_MONTHS; i++) { builtString << setw(SET_WIDTH_SPACE) << (weatherPTR + i)->averageTemp; }
	builtString << endl;

}

/* Build Statistics
* Builds the extra statistics portion of the printed string
* == INPUTS ==
* const WeatherData* weatherPTR - Start of the WeatherData list
* stringstream& -- The stringstream to be edited
*/
void buildStatistics(const WeatherData* weatherPTR, stringstream& builtString) {

	size_t highestElement = findHighestTemp(weatherPTR);
	size_t lowestElement = findLowestTemp(weatherPTR);
	double totalRain = findTotalRain(weatherPTR);
	double averageTemp = findYearlyAverage(weatherPTR);

	builtString
		<< endl
		<< "Total rain: " << totalRain << endl
		<< "Highest temp: " << (weatherPTR + highestElement)->highTemp << endl
		<< "Lowest temp: " << (weatherPTR + lowestElement)->lowTemp << endl
		<< "Yearly Average: " << averageTemp << endl;


}

/* Print Data
* Builds the outputed string through different elements
* == INPUTS ==
* const WeatherData* weatherPTR - Start of the WeatherData list
*/
void printData(const WeatherData* weatherPTR) {

	stringstream builtString;
	WeatherData temp;

	buildHeader(builtString);
	buildTotalRain(weatherPTR, builtString);
	buildHighestTemp(weatherPTR, builtString);
	buildLowestTemp(weatherPTR, builtString);
	buildAverage(weatherPTR, builtString);

	buildStatistics(weatherPTR, builtString);

	cout << builtString.str();

}

/* Build Lowest Temp
* Gathers users data through each month, calculates the average temp of each month.
* Calculates total rainfall throughout the year.
* Calculates the average temperature throughout the year.
* Builds a string to print from the inputed data.
*/
void weatherCalculator() {

	WeatherData yearlyData[NUN_MONTHS];
	assignData(yearlyData);
	printData(yearlyData);

}
#pragma once
#include <string>

// Bins
const size_t NUM_OF_BINS = 10;
const int MAX_BIN_ITEMS = 30;
const int MIN_BIN_ITEMS = 0;
const std::string BIN_NAMES[NUM_OF_BINS] = {

	"Valve",
	"Bearing",
	"Bushing",
	"Coupling",
	"Flange",
	"Gear",
	"Gear Housing",
	"Vacuum Gripper",
	"Cable",
	"Rod",

};
const int BIN_INITIL_VALS[NUM_OF_BINS] = {

	10,
	5,
	15,
	21,
	7,
	5,
	5,
	25,
	18,
	12,

};

// Edit Options
const size_t NUM_OF_EDIT_OPTIONS = 2;
const std::string EDIT_OPTIONS[NUM_OF_EDIT_OPTIONS] = {

	"Add to the bin",
	"Subtract from the bin"

};
const size_t BACK_OPTION = NUM_OF_EDIT_OPTIONS + 1;

// MENU OPTIONS
const size_t QUIT_OPTION = NUM_OF_BINS + 1;

#pragma once
#include <string>
#include "Date.h"

// Universal Constants //
const size_t SETW_WIDTH = 30;

// File Data //
const std::string PATIENT_FILE = "patient.txt";
const std::string PROCEDURES_FILE = "procedures.txt";

// Date Data //
const unsigned char CURRENT_MONTH = 10;
const unsigned char CURRENT_DAY = 27;
const unsigned short int CURRENT_YEAR = 1999;
const Date TODAYS_DATE = { CURRENT_MONTH,CURRENT_DAY,CURRENT_YEAR };

// Struct Data Members // 
const size_t DATA_MEMBERS_ADDRESS = 5;
const size_t DATA_MEMBERS_DATE = 3;
const size_t DATA_MEMBERS_NAME = 3;
const size_t DATA_MEMBERS_PATIENT = 5;
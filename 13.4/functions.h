#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "Name.h"
#include "Address.h"
#include "Patient.h"
#include "Procedure.h"

void removeNewLine(std::string*);
Name buildName(std::ifstream*);
Address buildAddress(std::ifstream*);
Procedure* buildProcedure(std::ifstream*);
Patient* buildPatient(std::ifstream*, Patient*);
Patient* importFileData(std::ifstream*, std::ifstream*);
void openFiles(std::ifstream*, std::ifstream*);
void performCleanup(std::ifstream*, std::ifstream*, Patient*);
void displayName(const Name, const std::string, std::stringstream&);
void displayPractitioner(const Name, const std::string, std::stringstream&);
void displayAddress(const Address, std::stringstream&);
void displayPhoneNumber(const std::string, const std::string, std::stringstream&);
void displayCharge(const double, const std::string, std::stringstream&);
void displayPatient(const Patient*);
void patientData();


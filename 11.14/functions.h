#pragma once
#include <sstream>
#include "Bin.h"

void initializeBins(Bin*, size_t);
void buildEmpty(const Bin*, std::stringstream&, size_t);
void buildUsed(const Bin*, std::stringstream&, size_t);
void buildOptions(std::stringstream&, size_t);
void initilizeProgram(Bin*, std::stringstream&, std::stringstream&);
void modifyValue(Bin*, const int);
void buildHeader(const Bin*, const std::string, std::stringstream&);
void buildQuery(const std::string, const std::string, const std::string, std::stringstream&);
void buildError(const int, const int, std::stringstream&);
void clearOperandsTemps(std::stringstream&, std::stringstream&, std::stringstream&);
void buildOptions(size_t, std::stringstream&);
void performOperand(Bin*, const std::stringstream&, std::stringstream&);
void binInventoryTracker();
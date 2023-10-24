#pragma once
#include "Bin.h"

void initializeBins(Bin*, size_t);
void buildEmpty(const Bin*, size_t);
void buildUsed(const Bin*,  size_t);
void buildOptions( size_t);
void initilizeProgram(Bin*);
void modifyValue(Bin*, const int);
void buildHeader(const Bin*, const std::string);
void buildError(const int, const int);
void buildOptions(size_t);
void performOperand(Bin*);
void binInventoryTracker();
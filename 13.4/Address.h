#pragma once
#include <string>

struct Address {

	std::string address;
	std::string secondaryAddress;
	std::string city;
	std::string state;
	unsigned int zipcode = 0;

};
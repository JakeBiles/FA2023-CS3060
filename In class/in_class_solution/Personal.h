#pragma once
#include <iostream>
#include <string>

class PersonalInfo {

private:
	std::string name;
	std::string address;
	int age;
	std::string phone;

public:
	PersonalInfo() {

		name = "";
		address = "";
		age = 0;
		phone = "";

	}
	PersonalInfo(std::string n, std::string addr, int a, std::string p) {

		name = n;
		address = addr;
		age = a;
		phone = p;

	}

	void setName(std::string n) {
		name = n;
	}
	void setAddr(std::string addr) {
		address = addr;
	}
	void setAge(int a) {
		age = a;
	}
	void setPhone(std::string phone) {
		this->phone = phone;
	}

	std::string getName() const { return name; }
	std::string getAddr() const { return address; }
	int setAge() const { return age; }
	std::string getPhone() const { return phone; }


};
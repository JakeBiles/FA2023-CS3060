#include <iostream>
#include <string>

int main() {

	std::string name = "jacob";

	if (name.find("j") == std::string::npos){
		std::cout << "Yes!";
	}

	for (char x : name) {

		std::cout << x << std::endl;

	}


	return 0;
}
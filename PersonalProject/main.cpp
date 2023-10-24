#include <iostream>

int main() {

	int num = 0;

	std::cin >> num;

	if (isdigit(num)) {
		std::cout << "True!";
	}

	else {
		std::cout << "False :(";
	}

	return 0;

}
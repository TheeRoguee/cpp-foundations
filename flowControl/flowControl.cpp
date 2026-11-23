#include<iostream>
#include<math.h>

//goto should be avoided

int sumTo(int number) {
	int storeHere{};
	for (int i = 1; i <= number; i++) {
		storeHere += i;
	}
	return storeHere;
}

void fizzBuzz(int upToNumber) {

	bool divByThree{ false };
	bool divByFive{ false };
	bool divBySeven{ false };

	for (int i = 1; i <= upToNumber; i++) {
		if (i % 3 == 0) {
			divByThree = true;
		}
		else if (i % 5 == 0) {
			divByFive = true;
		}
		else if (i % 7 == 0) {
			divBySeven = true;
		}
		else {
			std::cout << i << '\n';
		}
		
	}
}


int main() {


	double x{};
tryAgain: //this is a statement label
	std::cout << "Enter a non negative number: ";
	std::cin >> x;

	if (x < 0.00) {
		goto tryAgain;
	}
	std::cout << "The square root of " << x << " is " << sqrt(x) << '\n';

	fizzBuzz(150);

	char startAlphabet{'a'};
	char endAlphabet{ 'z' };

	while (static_cast<int>(startAlphabet) <= static_cast<int>(endAlphabet)) {
		std::cout << "Character " << startAlphabet << " has the ascii number " << static_cast<int>(startAlphabet) << '\n';
		startAlphabet++;
	}

	for (int i{ 0 }; i <= 20; i+=2) {
		std::cout << i << '\n';
	}

	std::cout << "Sum of numbers up to " << x << " is " << sumTo(x) << '\n';

	return 0;
}
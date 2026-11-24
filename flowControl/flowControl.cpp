#include "Random.h"
#include<iostream>
#include<math.h>
#include<random>
#include<chrono>


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

	//Instantiate a 32-bit Mersenne Twister
	//Seed our Mersenne Twister using steady_clock
	//std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())}; 


	//Seeding with the random device
	std::mt19937 mt{ std::random_device{}() };


	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution sixDie{ 1,6 };


	// Print a bunch of random numbers
	for (int i = 1; i <= 20; i++) {
		std::cout << sixDie(mt) << '\t';  //generate a roll of the die here
		if (i % 5 == 0) {
			std::cout << '\n';
		}
	}

	// We can call Random::get() to generate random integral values
	// If the two arguments have the same type, the returned value will have that same type.
	std::cout << Random::get(1, 6) << '\n';   // returns int between 1 and 6

	// Let's create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 };
	for (int count{ 1 }; count <= 10; ++count)
	{
		std::cout << die6(Random::mt) << '\t'; // generate a roll of the die here
	}




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
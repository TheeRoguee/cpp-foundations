#include"random.h"
#include<iostream>
#include<cstdlib>
#include<limits>
#include<string>


void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction() {
	if (!std::cin) {
		if (std::cin.eof()) {
			std::exit(0);
		}
		std::cin.clear();
		ignoreLine();
		return true;
	}
	return false;
}

bool hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
}


//the function return true if user won/ false if he lost
//we dont use the return value in this program
//for later it would be usefull to conditionalize other behaivor

char choseDificulty() {
	while (true) {
		std::cout << "Please choose a dificulty: easy/medium/hard: ";
		std::string dificulty{};
		std::getline(std::cin >> std::ws, dificulty);

		if (dificulty == "easy") {
			return 'e';
		}
		else if (dificulty == "medium") {
			return 'm';
		}
		else if (dificulty == "hard") {
			return 'h';
		}

		std::cout << "Invalid data! Respect format!" << '\n';
	}
}

int userGuess(int min, int max) {

	while (true) {

		int number{};
		std::cout << "Enter a number: ";
		std::cin >> number;

		if (clearFailedExtraction()) {
			std::cout << "Uups, invalid data, try again: " << '\n';
			continue;
		}

		if (hasUnextractedInput())
		{
			std::cout << "Uups, invalid operand, try again: " << '\n';
			ignoreLine(); // remove extraneous input lie 5*3
			continue;
		}

		if (number < min) {
			std::cout << "Uups, number is outside the scope ! (under min)" << '\n';
			continue;
		}
		if (number > max) {
			std::cout << "Uups, number is outside the scope ! (over max)" << '\n';
			continue;
		}
		return number;
	}
}


bool playHiLo() {
	std::cout << "Lets play HiLo!"<<'\n';
	int guesses{};
	int min{};
	int max{};
	int bestScore{};
	char setDificulty{ choseDificulty() };
	if (setDificulty == 'e') {
		min = 1;
		max = 50;
		guesses = 10;
	}
	else if (setDificulty == 'm') {
		min = 1;
		max = 100;
		guesses = 7;
	}
	else if (setDificulty == 'h') {
		min = 1;
		max = 500;
		guesses = 9;
	}

	std::cout<<"Im thinking of a number between " << min << " and " << 
		max << " . You have " << guesses << " tries to guess what it is" << '\n';

	const int numberToGuess{ Random::get(min,max) };
	for (int count{ 1 }; count <= guesses; ++count) { // wll run until count reaches number of guesses, if not win it goes out of loop and returns false

		int tempNum{ userGuess(min, max) };
		std::cout << "Guess #" << count << " : ";
		if (tempNum > numberToGuess) {
			std::cout << "Too high!" << '\n';
		}
		else if (tempNum < numberToGuess) {
			std::cout << "Too low!" << '\n';
		}
		else {
			std::cout << "Correct! You win!" << '\n';
			return true; // breaks out of the loop if win and return true
		}
	}
	std::cout << "You lost, out of guesses! The number was: " << numberToGuess << '\n';
	return false;
}


bool playAgain() {
	while (true) {
		std::cout << "Would you like to play again? y/n" << '\n';
		char choice{};
		std::cin >> choice;

		// clear out any extraneous input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		switch (choice) {
		case 'y':
		case 'Y':
			return true;
		case 'n':
		case 'N':
			return false;
		}
	}
}



int main() {

	do {
		playHiLo();
	} while (playAgain());

	std::cout << "Thank you for playing!" << '\n';

	return 0;
}
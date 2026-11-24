//Hi-Lo Game
#include<cassert>
#include"random.h"
#include<iostream>


char getOperator() {
	while (true) {
		std::cout << "Chose one of the fallowing: +, -, *, / ";
		char mathOperator{};
		std::cin >> mathOperator;

		switch (mathOperator) {
		case '+':
		case '-':
		case '*':
		case '/':
			return mathOperator;
		default:
			std::cout << "Oops, that operator is invalid, try again.";
		}
	}
}

int getUserNumber() {
	int number{};
	std::cout << "Give your guess: ";
	std::cin >> number;
	assert(number > 0 && number < 100);
	return number;
}

int main() {

	std::uniform_int_distribution rn{ 1, 100 };
	int randomNumber{ rn(Random::mt) };
	int numberOfGuesses{ 1 };
	bool wantToPlay{ true };
	char yesNo{};

	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';


	startOfGame:
	do {
		std::cout << "Guess # " << numberOfGuesses << '\n';
		int myNum{ getUserNumber() };
		if (numberOfGuesses < 7) {
			if (myNum == randomNumber) {
				std::cout << "Correct! You win! " << myNum << " = " << randomNumber << " on try: " << numberOfGuesses << '\n';
				std::cout << "Would you like to play again? y/n: ";
				std::cin >> yesNo;
				if (yesNo == 'n' || yesNo == 'N') {
					break;
				}
				else {
					numberOfGuesses = 0;
					goto startOfGame;
				}
			}
			else if (myNum < randomNumber) {
				std::cout << " Your guess is to low ";
				numberOfGuesses++;
			}
			else {
				std::cout << " Your guess is to high ";
				numberOfGuesses++;
			}
		}
		else {
			std::cout << "You lose, no more tries left! Number was: "<<randomNumber;
			break;
		}




	} while (wantToPlay);



	return 0;
}
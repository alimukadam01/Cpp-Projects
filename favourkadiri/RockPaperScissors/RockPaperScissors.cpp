#include <iostream>
#include <time.h>
using namespace std;

void Intro()
{
	cout << "\tROCK, PAPER, SCISSORS, LIZARD & SPOCK" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "RULES:" << endl;
	cout << "-Rock crushes Lizard and crushes Scissors" << endl;
	cout << "-Paper disproves Spock and covers Rock " << endl;
	cout << "-Scissors cuts Paper and decapitates Lizard " << endl;
	cout << "-Lizard poisons Spock and eats Paper " << endl;
	cout << "-Spock smashes Scissors and vaporises Rock " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "\nPlease select one from the choices below:\n0.Rock\n1.Paper\n2.Scissors\n3.Lizard\n4.Spock\n5.Exit Game\n" << endl;
}

int PlayerChoice(){
	int playerChoice = -1;

	while (!(playerChoice > -1 && playerChoice < 6)){
		cout << "Please enter a choice: ";
		cin >> playerChoice;
		if (!(playerChoice > -1 && playerChoice < 6)){
			cout << "Please enter a correct option" << endl;
		}
	}
	return playerChoice;
};

int ComputerChoice(){
	int computerChoice = -1;

	srand(time(0));
	computerChoice = rand() % 4 + 1;
	return computerChoice;
};

void Result(int playerChoice, int computerChoice){
	char results[5][5] = {
		{'D','C','P','P','C'},
		{'P','D','C','C','P'},
		{'C','P','D','P','C'},
		{'C','P','C','D','P'},
		{'P','C','P','C','D'}
	};

	if (results[playerChoice][computerChoice] == 'P'){
		cout << "You WIN this round!\n" << endl;
	}else if (results[playerChoice][computerChoice] == 'C'){
		cout << "You lose this round :(\n" << endl;
	}else{
		cout << "It's a DRAW!\n" << endl;
	}
};


int main()
{
	int playerChoice = -1;
	int computerChoice = -1;

	string choices[] = {"Rock", "Paper", "Scissors", "Lizard", "Spock", "Exit"};

	Intro();

	while (playerChoice != 5){
		playerChoice = -1;
		computerChoice = -1;

		playerChoice = PlayerChoice();
		cout << "You picked " << choices[playerChoice] << endl;

		if (playerChoice != 5){
			computerChoice = ComputerChoice();
			cout << "Computer picked " << choices[computerChoice] << endl;	
		
			Result(playerChoice, computerChoice);
		}
	}
	
	cout << "Goodbye!" << endl;
	return 0;
}

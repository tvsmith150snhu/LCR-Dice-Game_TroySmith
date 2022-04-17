/*
Troy Smith
IT-312-J4007
2022.04.17
7-1 Final Project Submission: Dice Game
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Game.h"

using namespace std;

  
void Game::begin_game()
{
	// Open and Read the rules file.
	inputFile.open("Rules.txt");
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			// Print file line by line with space between sections
			cout << line << ' ' << endl << endl;
		}
		inputFile.close();
	}
	// Notify user if the file won't open or isn't found
	else 
	{
		cout << "Unable to access the rules file..." << endl;
	}

	do {
		// Prompt for the number of players (must be greater than or equal to 3).
		cout << "\nEnter the number of players:" <<" ";
		cin >> numPlayers;

		if (numPlayers < 3 && cin.good())
		{
			// If fewer than 3, prompt again.
			cout << "Please enter at least 3 players..." << endl;
		}
		else if (cin.fail())
		{
			// If the input isn't a number, prompt for the correct input.
			cout << "Invalid entry.  Please enter a number..." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (numPlayers < 3 || cin.fail());

	// Establish the max number of chips each player can have.
	maxChips = numPlayers * 3;
}

void Game::endGame()
{
	winnerName = name[x];

	// Announce the Winner of the game!
	cout << "The winner of this game is: " << winnerName << "!" << endl << endl;
}
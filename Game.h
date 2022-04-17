/*
Troy Smith
IT-312-J4007
2022.04.17
7-1 Final Project Submission: Dice Game
*/

#pragma once

#include <fstream>
#include <string>

using namespace std;

class Game {
private:
	ifstream inputFile;
	string line;

public:
	void begin_game();
	void endGame();
	int numPlayers;
	int maxChips;
	int x; // Position in name array
	string name[100]; // Player array
	string winnerName;
	bool winner;
};
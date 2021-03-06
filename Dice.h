/*
Troy Smith
IT-312-J4007
2022.04.17
7-1 Final Project Submission: Dice Game
*/

#pragma once

class Dice {
private:
	int roll_result_ = 0;

public:
	static void rolling();
	void roll();
	void run_game();
	int center, a, z, c, chips[100];
	// a is the position in the chips array
	// z is for comparing the last position in the name array from Game class
	// c is for comparing the current position in the name array and compare it to z
	// chips[100] is the array for the max amount of players and their count of chips
};
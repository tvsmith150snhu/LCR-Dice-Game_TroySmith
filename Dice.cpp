/*
Troy Smith
IT-312-J4007
2022.04.17
7-1 Final Project Submission: Dice Game
*/

#include <iostream>
#include "Dice.h"
#include <conio.h>

using namespace std;

//Pause the game and wait for the player to roll the die or dice.
void Dice::rolling()
{
	cout << "Press any key to roll...\n";
	_getch(); 
	cout << "Rolling...\n";
}

// Check the amount of dice the current player has and assign the amount of rolls to be taken.
void Dice::run_game()
{
	if (chips[a] == 1)
	{
		rolling();
		roll();
	}
	else if (chips[a] == 2)
	{
		rolling();
		roll();
		roll();
	}
	else if (chips[a] == 3)
	{
		rolling();
		roll();
		roll();
		roll();
	}
}

// Handle the results and displays each time roll is called
void Dice::roll()
{
	roll_result_ = (rand() % 6) + 1; // Generate a random roll

	switch (roll_result_)
	{
	case 1:
		if (c == 0) // First position in the array
		{
			cout << "L" << endl;
			chips[0] += -1;
			chips[z] += 1;
			break;
		}
		else
		{
			cout << "L" << endl;
			chips[a] += -1;
			chips[a - 1] += 1;
			break;
		}
	case 2:
		if (z == c) // Last position in the array
		{
			cout << "R" << endl;
			chips[z] += -1;
			chips[0] += 1;
			break;
		}
		else
		{
			cout << "R" << endl;
			chips[a] += -1;
			chips[a + 1] += 1;
			break;
		}
	case 3:
		cout << "C" << endl;
		chips[a] += -1;
		center += 1;
		break;
	case 4:
		cout << "4" << endl;
		break;
	case 5:
		cout << "5" << endl;
		break;
	case 6:
		cout << "6" << endl;
		break;
	default:
		break;
	}
}
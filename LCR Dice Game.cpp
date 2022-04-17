/*
Troy Smith
IT-312-J4007
2022.04.17
7-1 Final Project Submission: Dice Game
*/

/*
LCR Dice Game

This program plays the LCR (Left, Center, Right) Dice game with a minimum of 3 players.
It first displays the rules of the game, then asks the user for the number of players and their names.
It then rolls the dice for each player, displays the number of chips of the player, then declares the only player
to still have chips as the winner.
*/
#include <iostream>
#include <ctime>
#include "Game.h"
#include "Dice.h"
#include "stdafx.h"
#include <sdkddkver.h> // Manages older versions of SDK

using namespace std;

// Reference pointers and variables
Game game;
Dice roll; 

int main()
{
    // Create Random number generator based on processor time at start of program
    srand((unsigned)time(nullptr)); 

    game.begin_game();
    game.endGame();

    //Create an Array of players based on number of players, then position them
    for (int name_count = 1; name_count <= game.numPlayers; name_count++)
    {
        cout << "Player " << name_count << " please enter your first name:";
        cin >> game.name[game.x];
        roll.chips[roll.a] = 3;
        game.x++; // Increment the position in the name array.
        roll.a++; // Increment the position in the chips array.
    }
    // Keep the game looping as long as there is not a winner, reset array position
    do {
        game.x = 0;
        roll.a = 0;

        for (int name_count = 1; name_count <= game.numPlayers; name_count++)
        {
            roll.z = (game.numPlayers - 1); // z is for comparing the last position in the name array
            roll.c = game.x; // c is for comparing the position in the name array opposing z

            // Check win condition
            if (roll.chips[roll.a] + roll.center == game.maxChips)
            {
                game.winner = true;
                game.endGame(); // Declares the winner
                system("pause");
                cout << "Press any key to exit..." << endl;
                return 0;
            }
            else if (game.winner == false)
            {
                // Roll dice based on the number of chips.  Maximum is 3.
                cout << endl << game.name[game.x] << " has " << roll.chips[roll.a] << " Chips." << endl;
                roll.run_game(); 
                game.x++;
                roll.a++;
            }
        }
    } while (game.winner == false);
}



#include "TicTacToe_Source.h"
// Michael McCain
// 12/24/2022
// Tic Tac Toe
// This is a program that allows a user to play tic tac toe with the computer

// Libraries
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<iterator>
#include<cstring>
#include<ctime>
#include<vector>
#include <cstdlib>
using namespace std;

// Globals
const int SZ = 3;

// Prototypes
bool userChoiceValid (int *choice);							// Validates user grid choice
void boardLayout(char play[SZ][SZ], int choice);			// Used to place grid choices
void displayBoard(char board[SZ][SZ]);						// Used to display board
void aiChoice(char play[SZ][SZ]);			// AI randomly picks available grid space

// Main
int main()
{
	// Initalizers
	char layoutGrid[SZ][SZ] =					// Board Layout w/ Grids
	{
		{'1','2','3'},
		{'4','5','6'},
		{'7', '8', '9'}
	};
	char layoutPlay[SZ][SZ] =					// Empty board layout used for play
	{
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '}
	};
	bool closeWindow = false;					// Close window
	bool valid = false;							// Validate choice

	// Display Title
	cout << "\n	  -----------";
	cout << "\n	  Tic Tac Toe" << "\n	  -----------" << endl;
	cout << "\n  | Player [X]  ---   CPU [O] |";
	cout << "\n  -----------------------------\n" << endl;

	// Display Board w/ grids
	displayBoard(layoutGrid);

	while (!closeWindow) {
		cout << endl;

		// Reset grid choice
		int choice = 0;							// Grid choice
		cout << endl;

		// Gather user choice
		do {
			valid = userChoiceValid(&choice);
		} while (valid == false);

		// Display play grid
		boardLayout(layoutPlay, choice);		// Place grid choice

		// Have AI pick random spot
		aiChoice(layoutPlay);
		displayBoard(layoutPlay);				// Display updated gameboard
		//system("pause");

	}
	return 0;
}

// Functions

void displayBoard(char board[SZ][SZ])
{
	// Display Board w/ grids
	int rowCount = 0;							// Count rows
	int eCount = 0;								// Count elements
	int colCount = 0;							// Count columns

	for (int i = 0; i < 3; i++)
	{
		if (rowCount >= 1 && rowCount < 3) {
			cout << "      =====================" << endl;
		}
		for (int j = 0; j < 3; j++)
		{

			cout << "	" << board[i][j];
			eCount++;
			if (colCount <= 1)
			{
				cout << "   |";
				colCount++;
			}

			if (eCount > 2)
			{
				cout << "\n";
				colCount = 0;
				eCount = 0;
				rowCount++;
			}
		}
	}
}

void aiChoice(char play[SZ][SZ])							// Getting errors w/ element placement
{
	vector<int> gridOp;					// Store available grids for AI
	int gridSpot = 0;					// Track grid elements
	
	// Iterate through board, identify available grids, push gridSpot to vector
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (play[i][j] != 'X' && play[i][j] != 'O') {
				gridOp.push_back(gridSpot);
			}
			gridSpot++;
		}
	}

	for (int i = 0; i < gridOp.size(); i++)
	{
		cout << gridOp[i];
	}
	cout << endl;
	
	srand(time(NULL));				// seed random number generator with time
	int aiPick = rand() % (gridOp.size() + 1);

	if (aiPick >= 6 && aiPick <= 8) {
		aiPick = aiPick - 6;
		cout << ">5-AI pick is: " <<  aiPick << endl;
		play[2][aiPick] =  'O';
	}
	else if (aiPick >= 3 && aiPick <= 5)
	{
		aiPick = aiPick - 4;
		cout << ">3-AI pick is: " << aiPick << endl;
		play[1][aiPick] = 'O';
	}
	else 
	{
		cout << "AI pick is: " << aiPick << endl;
		play[0][aiPick] = 'O';
	}
	/*cout << aiPick << endl;*/

}

bool userChoiceValid( int *choice)
{
	cout << "Which grid number would you like to place an X (1-9)?" << endl;
	cin >> *choice;
	bool validation = false;
	if (*choice >= 1 && *choice <= 9 && !cin.fail())
	{
		validation = true;
	}
	else {
		cin.clear();
		cin.ignore();
		cout << "\nInvalid selection. ";
		validation = false;
	}

	return validation;
}

void boardLayout(char play[SZ][SZ], int choice)
{
	string unavail = "Grid space is already occupied, please select a different grid space.\n";
	// Check for grid availability and place choice
	switch (choice)
	{
	case 1:
		if (play[0][0] == 'X' || play[0][0] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[0][0] = 'X';
		break;
	case 2:
		if (play[0][1] == 'X' || play[0][1] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[0][1] = 'X';
		break;
	case 3:
		if (play[0][2] == 'X' || play[0][2] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[0][2] = 'X';
		break;
	case 4:
		if (play[1][0] == 'X' || play[1][0] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[1][0] = 'X';
		break;
	case 5:
		if (play[1][1] == 'X' || play[1][1] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[1][1] = 'X';
		break;
	case 6:
		if (play[1][2] == 'X' || play[1][2] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[1][2] = 'X';
		break;
	case 7:
		if (play[2][0] == 'X' || play[2][0] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[2][0] = 'X';
		break;
	case 8:
		if (play[2][1] == 'X' || play[2][1] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[2][1] = 'X';
		break;
	case 9:
		if (play[2][2] == 'X' || play[2][2] == 'O') {
			cout << unavail << endl;
			break;
		}
		play[2][2] = 'X';
		break;
	}
}

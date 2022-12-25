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
using namespace std;

// Globals
const int SZ = 3;

// Prototypes
bool userChoiceValid (int *choice);							// Validates user grid choice
void boardLayout(char play[SZ][SZ], int choice);			// Used to place grid choices
void displayBoard(char board[SZ][SZ]);						// Used to display board

// Main
int main()
{
	// Initalizers
	char layoutGrid[SZ][SZ] =					// Board Layout w/ Grids
	{
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
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

	while(!closeWindow) {
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

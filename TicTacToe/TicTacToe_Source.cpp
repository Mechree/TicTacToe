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
bool userChoiceValid (char plays[SZ][SZ], int *choice);

// Main
int main()
{
	// Initalizers
	char layout[SZ][SZ] =						// Board Layout
	{
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};
	bool closeWindow = false;
	int eCount = 0;								// Count elements
	int colCount = 0;							// Count columns
	bool valid = false;
	int choice = 0;

	// Display Title
	cout << "\n	  -----------";
	cout << "\n	  Tic Tac Toe" << "\n	  -----------" << endl;
	cout << "\n  | Player [X]  ---   CPU [O] |";
	cout << "\n  -----------------------------\n" << endl;

	while(!closeWindow) {
		cout << endl;

		// Display Board
		int rowCount = 0;							// Count rows
		for (int i = 0; i < 3; i++) 
		{
			if (rowCount >= 1 && rowCount < 3) {
				cout << "      =====================" << endl;
			}
			for (int j = 0; j < 3; j++) 
			{

				cout << "	" << layout[i][j];
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
		cout << endl;

		// Gather user choice
			do {
				valid = userChoiceValid(layout, &choice);
			} while (valid == false);
		// Have AI pick random spot

		system("pause");

	}
	return 0;
}

// Functions

bool userChoiceValid(char plays[SZ][SZ], int *choice)
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

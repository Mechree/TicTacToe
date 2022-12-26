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
bool User_Choice_Valid (int *choice);								// Validates user grid choice
void Board_Layout(char play[SZ][SZ], int choice, bool *valid);		// Used to place grid choices
void Display_Board(char board[SZ][SZ]);								// Used to display board
void Ai_Choice(char play[SZ][SZ]);									// AI randomly picks available grid space
bool Win_Condition(char board[SZ][SZ]);								// Checks for 3 in a row

// Main
int main()
{
	// Initalizers
	char Layout_Grid[SZ][SZ] =								// Board Layout w/ Grids
	{
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};
	char Layout_Play[SZ][SZ] =								// Empty board layout used for play
	{
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '}
	};
	bool closeWindow = false;								// Close window
	bool valid = false;										// Validate choice

	// Display Title
	cout << "\n	  -----------";
	cout << "\n	  Tic Tac Toe" << "\n	  -----------" << endl;
	cout << "\n  | Player [X]  ---   CPU [O] |";
	cout << "\n  -----------------------------\n" << endl;

	// Display Board w/ grids
	Display_Board(Layout_Grid);
	while (!closeWindow) {
		cout << endl;

		// Reset grid choice
		int choice = 0;										// Grid choice
		cout << endl;

		// Gather user choice
		do {
			valid = User_Choice_Valid(&choice);				// Validate user Input
			Board_Layout(Layout_Play, choice, &valid);		// Place grid choice
		} while (valid == false);
		closeWindow = Win_Condition(Layout_Play);			// Check for win conditions
		if (closeWindow == false)
		{
			Ai_Choice(Layout_Play);							// Have AI pick random spot
			closeWindow = Win_Condition(Layout_Play);		// Check for win conditions
		}
		Display_Board(Layout_Play);							// Display updated gameboard
		//system("pause");
	}
	return 0;
}

// Functions

void Display_Board(char board[SZ][SZ])
{
	// Initalizers
	int rowCount = 0;								// Count rows
	int eCount = 0;									// Count elements
	int colCount = 0;								// Count columns

	// Display Board w/ grids
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

void Ai_Choice(char play[SZ][SZ])					
{
	// Initalizers
	vector<int> Grid_Op;							// Store available grids for AI
	int gridSpot = 0;								// Track grid elements
	
	// Iterate through board, identify available grids, push gridSpot to vector
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (play[i][j] != 'X' && play[i][j] != 'O') {
				Grid_Op.push_back(gridSpot);
			}
			gridSpot++;
		}
	}

	// If no grids are available, return to main
	if (Grid_Op.size() == 0)
	{
		return;
	}

	// Seed random number generator with time and pick grid spot
	srand(time(NULL));		
	/*cout << endl << Grid_Op.size() << endl;*/
	int aiPick = rand() % (Grid_Op.size());
	aiPick = Grid_Op[aiPick];

	if (aiPick >= 6 && aiPick <= 8) {
		aiPick = aiPick - 6;
		//cout << ">5-AI pick is: " <<  aiPick << endl;
		play[2][aiPick] =  'O';
	}
	else if (aiPick >= 3 && aiPick <= 5)
	{
		aiPick = aiPick - 3;
		//cout << ">3-AI pick is: " << aiPick << endl;
		play[1][aiPick] = 'O';
	}
	else 
	{
		//cout << "AI pick is: " << aiPick << endl;
		play[0][aiPick] = 'O';
	}

}

bool Win_Condition(char play[SZ][SZ])					
{
	bool winner = false;
	// Check horizontal
	for (int i = 0; i < 3; i++)
	{
		// Tally horizontal streaks
		int playerStreak = 0;
		int aiStreak = 0;

		// Check for 3 X's or O's
		for (int j = 0; j < 3; j++)
		{
			if (play[i][j] == 'X')
			{
				playerStreak++;
				if (playerStreak == 3)
				{
					cout << "\nPlayer Wins!" << endl;
					winner = true;
					return winner;
				}
			}
			else if (play[i][j] == 'O')
			{
				aiStreak++;
				if (aiStreak == 3)
				{
					cout << "\nCPU Wins!" << endl;
					winner = true;
					return winner;
				}
			}
			
		}
	}

	// Check vertical
	for (int i = 0; i < 3; i++)
	{
		// Tally vertical streaks
		int playerStreak = 0;
		int aiStreak = 0;

		// Check for 3 in a vertical row
		for (int j = 0; j < 3; j++)
		{
			if (play[j][i] == 'X')
			{
				playerStreak++;
				if (playerStreak == 3)
				{
					cout << "\nPlayer Wins!" << endl;
					winner = true;
					return winner;
				}
			}
			else if (play[j][i] == 'O')
			{
				aiStreak++;
				if (aiStreak == 3)
				{
					cout << "\nCPU Wins!" << endl;
					winner = true;
					return winner;
				}
			}
		}
	}

	// Check diagnal left to right
	int playerStreak = 0;
	int aiStreak = 0;

	for (int i = 0; i < 3; i++)
	{
		if (play[i][i] == 'X')
		{
			playerStreak++;
			if (playerStreak == 3)
			{
				cout << "\nPlayer Wins!" << endl;
				winner = true;
				return winner;
			}
		}
		else if (play[i][i] == 'O')
		{
			aiStreak++;
			if (aiStreak == 3)
			{
				cout << "\nCPU Wins!" << endl;
				winner = true;
				return winner;
			}
		}
	}

	// Check diagnal right to left
	playerStreak = 0;
	aiStreak = 0;

	for (int i = 0; i < 3; i++)
	{
		if (play[i][2 - i] == 'X')
		{
			playerStreak++;
			if (playerStreak == 3)
			{
				cout << "\nPlayer Wins!" << endl;
				winner = true;
				return winner;
			}
		}
		else if (play[i][2-i] == 'O')
		{
			aiStreak++;
			if (aiStreak == 3)
			{
				cout << "\nCPU Wins!" << endl;
				winner = true;
				return winner;
			}
		}
	}
	return winner;
}

bool User_Choice_Valid( int *choice)
{
	// Initializer
	bool validation = false;

	// Get user choice
	cout << "Which grid number would you like to place an X (1-9)?" << endl;
	cin >> *choice;
	// Check user input
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

void Board_Layout(char play[SZ][SZ], int choice, bool *valid)
{
	// Initalizer
	string unavail = "Grid space is already occupied, please select a different grid space.\n";

	// Check for grid availability and place choice
	switch (choice)
	{
	case 1:
		if (play[0][0] == 'X' || play[0][0] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[0][0] = 'X';
		break;
	case 2:
		if (play[0][1] == 'X' || play[0][1] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[0][1] = 'X';
		break;
	case 3:
		if (play[0][2] == 'X' || play[0][2] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[0][2] = 'X';
		break;
	case 4:
		if (play[1][0] == 'X' || play[1][0] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[1][0] = 'X';
		break;
	case 5:
		if (play[1][1] == 'X' || play[1][1] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[1][1] = 'X';
		break;
	case 6:
		if (play[1][2] == 'X' || play[1][2] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[1][2] = 'X';
		break;
	case 7:
		if (play[2][0] == 'X' || play[2][0] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[2][0] = 'X';
		break;
	case 8:
		if (play[2][1] == 'X' || play[2][1] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[2][1] = 'X';
		break;
	case 9:
		if (play[2][2] == 'X' || play[2][2] == 'O') {
			cout << unavail << endl;
			*valid = false;
			break;
		}
		play[2][2] = 'X';
		break;
	}
}

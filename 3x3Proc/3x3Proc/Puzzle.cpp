#include "Puzzle.h"
#include <string>
#include <algorithm>

using namespace std;

void TilePuzzle::moveTiles(int board[3][3]) {
	string input;
	cout << endl;

	// Outputs instrutions for user input to screen
	cout << "w = UP     a = LEFT" << endl;
	cout << "s = Down     d = RIGHT";
	cout << endl;
	input = _getch();

	//Top Left Empty
	if (board[0][0] == 0) {
		if (input == "w") {
			board[0][0] = board[1][0];
			board[1][0] = 0;
		}
		else if (input == "a") {
			board[0][0] = board[0][1];
			board[0][1] = 0;
		}

	}
	//Top Midde Empty
	else if (board[0][1] == 0) {
		if (input == "d") {
			board[0][1] = board[0][0];
			board[0][0] = 0;
		}
		else if (input == "w") {
			board[0][1] = board[1][1];
			board[1][1] = 0;
		}
		else if (input == "a") {
			board[0][1] = board[0][2];
			board[0][2] = 0;
		}

	}
	//Top Right Empty
	else if (board[0][2] == 0) {
		if (input == "d") {
			board[0][2] = board[0][1];
			board[0][1] = 0;
		}
		else if (input == "w") {
			board[0][2] = board[1][2];
			board[1][2] = 0;
		}

	}
	//Middle Left Empty
	else if (board[1][0] == 0) {
		if (input == "s") {
			board[1][0] = board[0][0];
			board[0][0] = 0;
		}
		else if (input == "a") {
			board[1][0] = board[1][1];
			board[1][1] = 0;
		}
		else if (input == "w") {
			board[1][0] = board[2][0];
			board[2][0] = 0;
		}

	}
	//Middle Middle Empty
	else if (board[1][1] == 0) {
		if (input == "d") {
			board[1][1] = board[1][0];
			board[1][0] = 0;
		}
		else if (input == "s") {
			board[1][1] = board[0][1];
			board[0][1] = 0;
		}
		else if (input == "a") {
			board[1][1] = board[1][2];
			board[1][2] = 0;
		}
		else if (input == "w") {
			board[1][1] = board[2][1];
			board[2][1] = 0;
		}

	}
	//Middle Right Empty
	else if (board[1][2] == 0) {
		if (input == "s") {
			board[1][2] = board[0][2];
			board[0][2] = 0;
		}
		else if (input == "d") {
			board[1][2] = board[1][1];
			board[1][1] = 0;
		}
		else if (input == "w") {
			board[1][2] = board[2][2];
			board[2][2] = 0;
		}

	}
	//Bottom Left Empty
	else if (board[2][0] == 0) {
		if (input == "s") {
			board[2][0] = board[1][0];
			board[1][0] = 0;
		}
		else if (input == "a") {
			board[2][0] = board[2][1];
			board[2][1] = 0;
		}

	}
	//Bottom Middle Empty
	else if (board[2][1] == 0) {
		if (input == "d") {
			board[2][1] = board[2][0];
			board[2][0] = 0;
		}
		else if (input == "s") {
			board[2][1] = board[1][1];
			board[1][1] = 0;
		}
		else if (input == "a") {
			board[2][1] = board[2][2];
			board[2][2] = 0;
		}

	}
	//Bottom Right Empty
	else if (board[2][2] == 0) {
		if (input == "s") {
			board[2][2] = board[1][2];
			board[1][2] = 0;
		}
		else if (input == "d") {
			board[2][2] = board[2][1];
			board[2][1] = 0;
		}

	}

	//Cleans the screen after values have been switched
	system("CLS");
	//Reprints new values after user input
	printBoard(board);
	while (!boardSolved(board)) {
		moveTiles(board);
	}
	cout << endl << "Congrats, Thanks for playing!!!" << endl;
}


void TilePuzzle::printBoard(int board[3][3]) {
	int row = 3;
	int col = 3;

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (board[x][y] == 0) {
				//Sets the "0" in board[2][2] to be
				//a light blue asterisk
				SetConsoleTextAttribute(hConsole, 11);
				cout << " *";
			}
			else {
				//If number is in its correct place sets
				//color to be green
				if (board[x][y] == ((x * 3) + (y + 1)))
					SetConsoleTextAttribute(hConsole, 2);
				else
					//if number is in incorrect place sets
					//color to be red
					SetConsoleTextAttribute(hConsole, 12);
				cout << " " << board[x][y];
			}
		}
		cout << endl;
	}
	//Sets the control display to be red
	SetConsoleTextAttribute(hConsole, 12);
}


void TilePuzzle::initializeBoard(int board[3][3]) {
	int z = 1;
	int row = 3;
	int col = 3;
	// Initializes the board, loops stops at 3 for
	// the number of rows and columns
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			board[x][y] = z;
			z++;
		}
		// Sets the last value zero to later be
		// converted to an asterisk
		board[2][2] = 0;
	}
}


void TilePuzzle::scrambleBoard(int board[3][3]){
	srand(time(NULL));

random_shuffle(&board[0][0], &board[0][0] + 9);
}


bool TilePuzzle::boardSolved(int board[3][3]) {
	int solvedBoard[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,0 } };
	bool boardSolved = true;
	int row = 0;
	int col = 0;

	while (boardSolved && row <= 2) {
		if (solvedBoard[row][col] == board[row][col]) {
			col++;
			if (col >= 3) {
				row++;
				col = 0;
			}
		}
		else
			boardSolved = false;
	}
	return boardSolved;
}
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <string>

using namespace std;

#include "Puzzle.h";


void main() {
	int puzzleBoard[3][3];
	int input;

	TilePuzzle myPuzzle;

	myPuzzle.initializeBoard(puzzleBoard);
	myPuzzle.printBoard(puzzleBoard);
	cout << "Press any key to scramble tiles" << endl;
	input = _getch();
	myPuzzle.scrambleBoard(puzzleBoard);
	system("CLS");
	myPuzzle.printBoard(puzzleBoard);
	myPuzzle.moveTiles(puzzleBoard);


}
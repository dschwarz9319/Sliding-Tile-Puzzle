
#define _PUZZLE_

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <algorithm>

class TilePuzzle {
private:
	
	

public:
	void printBoard(int board[3][3]);
	void initializeBoard(int board[3][3]);
	void moveTiles(int board[3][3]);
	void scrambleBoard(int board[3][3]);
	bool boardSolved(int board[3][3]);
};
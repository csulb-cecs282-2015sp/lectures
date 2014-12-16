// See the project spec for a description of these functions.
// Do NOT modify this file.
// You must implement all these functions in a file called OthelloGame.cpp

// The size of an othello board.
const int BOARD_SIZE = 8;

/*
Prints the board to cout. The board is an 8x8 matrix of char values, where a 0
represents a blank space, a 1 represents a Black piece, and a -1 represents a
White space. 
*/
void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]);

/*
Returns true if the given row and col is in-bounds of an 8x8 game board matrix.
*/
bool InBounds(int row, int col);

/*
Tests to see if the given row and col is a valid move for the given board. A 
move is valid if it is in-bounds and the desired space is empty.
*/
bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

/*
Uses cin to read a move from the user, and assigns the user's choice to the 
values of the row and col pointers.
*/
void GetMove(int *row, int *col);

/*
Applies a move for the given currentPlayer at the given row and col position to
the given game board. Places a piece at the given location, then flips enemy 
pieces according to the rules of othello.
*/
void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, 
 char currentPlayer);

/*
Gets an integer value indicating who is winning/has won the game, equal to the
number of Black pieces minus the number of White pieces on the board.
*/
int GetValue(char board[BOARD_SIZE][BOARD_SIZE]);
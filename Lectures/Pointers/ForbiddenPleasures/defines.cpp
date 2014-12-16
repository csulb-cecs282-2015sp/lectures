#include <iostream>
using namespace std;

// the style guide says you cannot have constant literals other than 0 1 or 2
// in your code. How then should you express those values?
void PrintBoard(char[3][3]); 

// C++ allows a "const" keyword to express a value that will never change.
// const values can be used for array sizes and other literals.
const int BOARD_SIZE = 3;

// now I can declare PrintBoard like this:
void PrintBoard(char[BOARD_SIZE][BOARD_SIZE]);



// the C language has an older, more flexible syntax for this: #define
#define BOARD 3
void PrintBoard(char[BOARD][BOARD]); 
// at compile time, BOARD will be replaced with 3 and then compiled normally.


// you can #define almost anything to make your own aliases.
#define TICTACTOEPIECE char
// now I can use TICTACTOEPIECE as if it was a variable type/class.

void PrintBoard(TICTACTOEPIECE[3][3]); // looks like a 3x3 matrix of game pieces


// DON'T GO CRAZY WITH THIS
#define boolean bool
// is this a good idea?

// #defines can act like functions with arguments, too. we call these "macros"
#define PRINT(x) cout << x
// the x is a parameter filled in by the pre-processor.

int main() {
   boolean mybool = false;

   PRINT(mybool);
   // C++ expands the line above to 
   // cout << mybool;
}
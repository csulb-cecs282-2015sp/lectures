#include <iostream>
#include <random>
using namespace std;

// Use of "C-style arrays" / "built-in arrays".
int main(int argc, char* argv[]) {
   // Declare an array of 5 ints
   int myArray[5]; // NOTE: no "new". 
   
   /* 
   The size of an array must be KNOWN at COMPILE TIME. We will discuss why
   in the next file. 

   Arrays have garbage data initially, like any other uninitialized variable.
   You can "fill" an array with a default value when declaring:
   */
   int preFilledArray[11] = { 0 };

   // You can specify the entire of an array's contents.
   
   cout << "Enter array size:";
   int size;
   cin >> size;
// int badArray[size]; // error: expression must have a constant value.
   // REMEMBER: ARRAY SIZE MUST BE KNOWN AT COMPILE TIME



   // Arrays are 0-based for indices
   myArray[0] = 100;

   // Arrays are NOT BOUNDS-CHECKED.
   // myArray[12] = 500; // result of this is not defined; anything could happen!


   // Let's do a real application with arrays: simulate 1,000,000 rolls of a 
   // pair of dice. Keep track of how many times each outcome is rolled.
   random_device rd;
   default_random_engine engine(rd());
   uniform_int_distribution<int> dieRoll(2, 12);
   const int MAX_ROLLS = 1000000;
   int results[11];

   for (int i = 0; i < MAX_ROLLS; i++) {
      int die1 = dieRoll(engine), die2 = dieRoll(engine);
      int roll = die1 + die2;
      results[roll - 2]++;
   }

   for (int i = 0; i < 11; i++) {
      cout << i + 2 << ": " << results[i] << endl;
   }
   /* output:
   2: 27965
   3: 55611
   4: 1850671
   5: 19583204
   6: -829181441
   7: 166767
   8: 19609617
   9: 19582198
   10: 19557036
   11: 1822893
   12: 19501165

   What the heck???
   */


   // finally, multi-dimensional arrays. first dimension is rows, second is cols
   int grid[3][3] = {  // a 3x3 grid
                       // assign a 1 for "X", a 2 for "O" -- tic tac toe!
      {1, 1, 2},       
      {2, 1, 0},
      {0, 2, 1},
   };
}
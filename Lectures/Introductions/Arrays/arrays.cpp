#include <iostream>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
   // declare an array of 11 ints
   int results[11] = {0}; // NOTE: no "new". the size must be KNOWN at COMPILE TIME.
   
   cout << "Enter array size:";
   int size;
   cin >> size;
//   int badArray[size]; // error: expression must have a constant value

   // arrays are 0-based for indices
   results[0] = 100;

   // arrays are NOT BOUNDS-CHECKED
   //results[12] = 500; // result of this is not defined; anything could happen!


   // let's do a real application with arrays: simulate 1,000,000 rolls of a 
   // pair of dice. keep track of how many times each outcome is rolled.
   random_device rd;
   default_random_engine engine(rd());
   uniform_int_distribution<int> dieRoll(2, 12);
   const int MAX_ROLLS = 1000000;

   results[0] = 0;
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

   the heck???
   */


   // finally, multi-dimensional arrays. first dimension is rows, second is cols
   int grid[3][3] = {  // a 3x3 grid
                       // assign a 1 for "X", a 2 for "O" -- tic tac toe!
      {1, 1, 2},       
      {2, 1, 0},
      {0, 2, 1},
   };
}
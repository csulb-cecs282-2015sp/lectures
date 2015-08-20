#include <iostream>
#include <string>
#include <vector>

#include "OthelloBoard.h"
#include "OthelloMove.h"
using namespace std;

int main(int argc, char* argv[]) {
   // C++11 introduces the keyword 'auto' to use "type inference" to select
   // the type of a variable automatically when it is declared.

   auto i = 10; // i is of type int, because the rhs is int.
   auto d = 10.0; // d is of type double

   // For primitive types, this doesn't make much sense to use, so DON'T GO 
   // OVERBOARD and make all variables auto. For one, you must initialize an 
   // auto variable when declared.

   // auto unknown; <---- what type is this variable? Not allowed.

   // Second, sometimes the inferred type is misleading...
   auto s = "Hello, world!";
   // Can you guess what type s is?

   // Third, can't construct objects on the stack as easily...
   // Suppose I want to replace "Rational r(1, 3); with auto.
   // auto r(1,3); won't compile, why?




   // So when is auto useful?
   // If the return type of a function is obvious, but tedious to use.
   // Imagine I'm in your Othello project.

   OthelloBoard board;
   const vector<OthelloMove*> *history = board.GetMoveHistory(); // ugly!
   auto hist = board.GetMoveHistory(); // pretty!


   // For the same reason, auto is useful with iterators.
   for (auto itr = hist->rbegin(); itr != hist->rend(); itr++) {
      // printing in reverse order, C++11 style!
   }

}
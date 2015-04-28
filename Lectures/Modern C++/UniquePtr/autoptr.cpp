#include <memory>
#include <iostream>
#include <string>
#include "Rational.h"
using namespace std;

/*
In 2003, C++ added a class called auto_ptr. It looked something like this.
*/
template<typename TPtr>
class AutoPtr {
   TPtr *pointer;

public:
   AutoPtr(TPtr *p) : pointer(p) {}

   ~AutoPtr() {
      delete pointer;
   }

   TPtr* operator->() {
      return pointer;
   }

   TPtr& operator*() {
      return *pointer;
   }
};

/*
The intention was to enable a "smart pointer" that could wrap around a heap
variable and automatically delete that heap variable when the pointer went out
of scope. How was this supposed to work?
*/

int main(int argc, char* argv[]) {
   if (true) {
      AutoPtr<Rational> ptr(new Rational(1, 3));
      cout << *ptr << endl;
      // ptr is about to go out of scope. When it does, what function will be
      // called? And what will that function do? (Hint: look above.)
   }

   /* 
   Unfortunately, this caused as many issues as it solved.
   QUESTIONS:
      1. What happens if a second auto pointer is set equal to ptr?





      2. What happens if a auto pointer is passed by value to a function?




      3. Are these ALWAYS problems?




   */

   /*
   Ultimately auto_ptr was declared unsafe for reliable code and was killed off
   ("deprecated"). Its replacement is unique_ptr.
   */

   if (true) {
      unique_ptr<Rational> ptr(new Rational(2, 5));
      // as before, when a unique_ptr goes out of scope, it will delete the heap
      // variable it points to. 
   }

   /* 
   unique_ptr solves the issues with auto_ptr:
      1. unique_ptr cannot be copy constructed or assigned; these give compiler
         errors. Ex:

         unique_ptr<Rational> p2 = ptr;  // Error!

      2. There is no way for two unique_ptrs to point to the same heap space. 
         But we still need a way to "transfer" ownership of the heap space to
         another unique_ptr. Enter std::move, a function that "moves" one
         uniquely-held resource (like a heap variable) to another variable.
   */

   if (true) {
      unique_ptr<Rational> p1(new Rational(3, 4));
      unique_ptr<Rational> p2(std::move(p1));

      // now p1 points to nullptr, and p2 points to the Rational 3/4. 
      // p1 can go out of scope without affecting p2, and the syntax makes it 
      // clear that I wanted to "move" ownership from p1 to p2.
   }

   // This all ties together to allow EXCELLENT, heap-safe code using auto_ptr.
   // Here's how we used to do OthelloMoves on the heap in Project 2:

   string userInput;
   if (userInput.find("move") == 0) {
      OthelloMove *m = board.CreateMove();
      try {
         *m = userInput;

         // make sure move is valid....

         // now apply it.
         if (moveIsValid)
            board.ApplyMove(m);
         else
            delete m;
      }
      catch (OthelloException &ex) {
         // out of range, delete the move
         delete m;
      }
   }

   // That's a lot of places to forget to delete. unique_ptr can make this 
   // trivial by deleting the move when it goes out of scope.
   
   if (userInput.find("move") == 0) {
      try {
         unique_ptr<OthelloMove> m = board.CreateMove();
         // make sure move is valid.....

         // now apply it
         if (moveIsValid)
            board.ApplyMove(std::move(m)); // ownership of m has been transferred to the board.

         // If the move was not valid, the unique_ptr will now go out of scope.
         // This will delete the heap move!
      }
      catch (OthelloException &ex) {
         // if an exception is thrown, the unique_ptr will go out of scope :).
      }
   }
   


   // This idea extends to containers of heap objects.
   // Remember this code in UndoLastMove?

   OthelloMove *undoMove = mHistory.back();
   //...
   mHistory.pop_back();
   delete undoMove;


   // If mHistory is a vector of unique_ptrs, popping back will destruct the
   // unique_ptr, automatically deleting the move!
   

   // Lastly, imagine what happens when your Project 2 OthelloBoard variable
   // goes out of scope.
   if (true) {
      OthelloBoard b;
      // suppose 30 moves are applied to b.
   }

   // If mHistory is a vector of OthelloMove*, those pointers need to be cleaned
   // up in OthelloBoard's destructor! But if mHistory contains unique_ptrs, 
   // they will automatically destruct when the board gets destructed! 
         

}
#include "LinkedQueue.h"
#include <iostream>
using namespace std;


int mains() {
   // Demonstrate that our LinkedQueue works.
   LinkedQueue numbers;

   numbers.Add(4);
   numbers.Add(8);
   numbers.Add(15);
   numbers.Add(16);
   numbers.Add(23);
   numbers.Add(42);

   while (numbers.Size() > 0) {
      int data = numbers.Remove();
      cout << "Removed " << data << endl;
   }
   // This seems to work! Yay!
   // But there are sinister bugs hidden from view...


   // First, what happened to the Nodes that got unlinked from the queue?



   // Second, what happens if I Remove from an empty queue?



   // Now that we've fixed those errors...
   // Third, what's up with this code?
   LinkedQueue second;
   second.Add(1);

   LinkedQueue copy(second); // make a copy of second
   copy.Add(2);
   cout << second.Size() << endl; // output: 1
   cout << copy.Size() << endl;   // output: 2

   second.Remove();
   copy.Remove();
   // whoops! What happened?





   // One final bug:
   if (true) {
      LinkedQueue third;
      third.Add(5);
      third.Add(6);

      // What happens when third goes out of scope?
      // What do we need to fix this?
   }

   for (int i = 0; i < 0; i++) {
      LinkedQueue temp;
      temp.Add(1);
      temp.Add(1);
      temp.Add(1);
      temp.Add(1);
      temp.Add(1);
   }

   LinkedQueue empty;
   cout << empty.Remove();
   return 0;
}
#include "LinkedQueue.h"
#include <iostream>
using namespace std;


int main() {
   // Demonstrate that our LinkedQueue works.
   LinkedQueue<int> numbers;

   numbers.Add(4);
   numbers.Add(8);
   numbers.Add(15);
   numbers.Add(16);
   numbers.Add(23);
   numbers.Add(42);

   // Hover over the .Add calls above... what is the method signature?



   return 0;
}
#include "LinkedQueue.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

// For later.
void FunctionForInt(LinkedQueue<int> &param);

template<typename T>
void FunctionForAll(LinkedQueue<T> &param);

int main() {
   // Demonstrate that our LinkedQueue works.
   LinkedQueue<int> numbers;

   numbers.Add(4);
   numbers.Add(8);
   numbers.Add(15);
   numbers.Add(16);
   numbers.Add(23);
   numbers.Add(42.5);
   // Hover over the .Add calls above... what is the method signature?

   LinkedQueue<LinkedQueue<int>> whaaaat;
   whaaaat.Add(numbers);


   LinkedQueue<string> months;
   months.Add("January");
   months.Add("February");
   months.Add("March");

   // What is the type of "months"? What is the type of "numbers"?
   // Are the two assignment-compatible, i.e., can I do this?
   // months = numbers;



   // Which means we can't pass a LinkedQueue<string> to a method wanting a 
   // LinkedQueue<int>.

   FunctionForInt(numbers); // works fine
   // FunctionForInt(months);   compile-time error.


   // But say we wanted a method that could be given a linked queue of ANY type.
   // Can we make that happen? Of course!
   FunctionForAll(numbers);
   FunctionForAll(months);


   // Well, almost any type.
   LinkedQueue<random_device> incompatible;
   // FunctionForAll(incompatible);  compile-time error, but on what line?

   return 0;
}

void FunctionForInt(LinkedQueue<int> &param) {
   // Does nothing, but can only be passed a LinkedQueue<int>.
}

template<typename T>
void FunctionForAll(LinkedQueue<T> &param) {
   // Do something, like remove and print all items in the queue.
   cout << "Removing all" << endl;
   while (param.Size() > 0) {
      cout << param.Remove() << endl;
   }

   // Does this work with liteally ANY type of queue? What assumption is made 
   // here about the data elements in the queue?




}
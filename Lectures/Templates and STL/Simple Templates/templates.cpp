
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <stdexcept>
#include "TemplateSort.h" // we'll get to this
#include "Rational.h"
using namespace std;

int main(int argc, char* argv[]) {
   // generate an array of 10 random rational numbers
   Rational numbers[10];

   random_device rd;
   default_random_engine engine(rd());
   uniform_int_distribution<int> distr(1, 20);

   for (int i = 0; i < 10; i++) {
      numbers[i] = Rational(distr(engine), distr(engine));
   }

   cout << "Unsorted array: " << endl;
   for (Rational &r : numbers) {
      cout << r << endl;
   }


   cout << endl << "Sorting..." << endl;
   // sort the array using insertion sort
   for (int i = 1; i < 10; i++) {
      Rational elementI = numbers[i];
      
      int j;
      for (j = i; j > 0; j--) {
         if (elementI < numbers[j - 1]) {
            numbers[j] = numbers[j - 1];
         }
         else {
            break;
         }
      }
      numbers[j] = elementI;
   }
   
   cout << "Sorted: " << endl;
   for (Rational &r : numbers) {
      cout << r << endl;
   }
   
   
   // observation: is this a different algorithm than sorting an array of ints?
   

   
   
   
   
   
   // question: describe ALL DATA TYPES that this algorithm will work for:








   // now use the template sort method in TemplateSort.h
   SortArray(numbers); // what is T?

   int intArray[] = {10, 5, 3, 8, 6, 1, 7, 9, 2, 4};
   SortArray(intArray); // what is T?
   

   // C++ has a built-in templated sort method in <algorithm>
   sort(numbers, numbers + 10); // takes two pointers/iterators to first element
                                // and "one past last" element.
   cout << endl << endl << "Sorted with <algorithm>: " << endl;
   for (Rational &r : numbers) {
      cout << r << endl;
   }
   return 0;
}
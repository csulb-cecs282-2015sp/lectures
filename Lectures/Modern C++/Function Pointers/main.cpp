#include <functional>
#include <vector>
#include <iostream>
#include <numeric>

using std::cout;
using std::endl;

// For later.
int Add(int, int);
int Mult(int, int);
int Div(int, int);
int Max(int, int);
int ApplyFunction(int, int, std::function<int(int, int)>);
int Fold(std::vector<int> &, int, std::function<int(int, int)>);

int _main(int argc, char* argv[]) {
   /*
   C and C++ have always provided a way of declaring a "pointer to a function."
   Such pointers do not point to a *value* in memory, but instead point to the
   body of a function. Once a function pointer is initialized, it can be used
   to invoke whatever function it actually points to.
   
   To declare a function pointer requires special difficult syntax. In general:

   RETURNTYPE (*VARIABLE_NAME)(PARAMETER_TYPES_WITH_COMMAS);
   */
   int (*ptr)(int, int);
   // ptr is a pointer to a function taking two int parameters and returning 
   // an int.


   // Like all pointers, ptr must point to something before it can be used.
   // In this case, ptr can ONLY point to a function taking two ints and 
   // returning int. "Add" (see above) is one such function.
   ptr = Add;
   // OPTIONAL SYNTAX:
   // ptr = &Add;

   // The function that ptr points to can be invoked by "calling" ptr.
   cout << ptr(10, 5) << endl; // what is the expected output?

   // Another compatible function is Mult.
   ptr = Mult;
   cout << ptr(10, 5) << endl;


   // Function pointer syntax is awkward, so C++11 introduces simpler ways
   // of working with them: the std::function class from <functional>

   // Syntax: std::function<RETURN_TYPE (PARAMETERS)>
   std::function<int (int, int)> func = Add;
   
   // func can now be invoked like a function.
   cout << func(10, 5) << endl;

   // function objects can be passed as parameters to other functions!
   cout << endl << "Applying a function" << endl;
   cout << ApplyFunction(10, 20, func) << endl;
   func = Mult;
   cout << ApplyFunction(10, 20, func) << endl;

   // Like variable pointers, function pointers are useful for writing shorter,
   // more flexible code.


   // Exercise: write a loop to calculate the sum of all numbers in a vector.
   std::vector<int> values = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // C++11 syntax

   int accumulator = 0;
   for (int &i : values) {
      accumulator = Add(accumulator, i);
   }

   // Now, write a loop to calculate the product of the numbers.
   accumulator = 1;
   for (int &i : values) {
      accumulator = Mult(accumulator, i);
   }

   // Notice the similarity in the two solutions: start some accumulator with an
   // initial value. Iterate through all members of the list, and apply some 
   // function to the accumulator and each successive member of the list.
   // The accumulator's final value is the answer.

   // The two solutions are identical except for the choice of function. Using
   // a function pointer, we can write a generic algorithm for applying SOME 
   // FUNCTION to a list of values, using an initial accumulator. See below.

   // With our "Fold" function, I can now add all the numbers in the list with
   // one function call.
   int sum = Fold(values, 0, Add);
   cout << "The sum of the numbers is " << sum << endl;
   // Or the product:
   int product = Fold(values, 1, Mult);
   cout << "The product of the numbers is " << product << endl;
   // Or the maximum value of the list:
   int max = Fold(values, 0, Max); // assuming the numbers are positive.
   cout << "The max of the numbers is " << max << endl;
   // Or with some cuteness, the average value:
   int average = ApplyFunction(Fold(values, 0, Add), values.size(), Div);
   cout << "The average of the numbers is " << average << endl; 
   // (warning, integer division above.)

   // The C++ standard library provides a Fold implementation in <numeric>
   // called "std::accumulate." It takes two iterators for the structure to
   // fold over, an initial value, and a function, then applies the fold.
   sum = std::accumulate(values.begin(), values.end(), 0, Add);
   cout << "The accumulate sum is " << sum << endl;

   // Or we can multiply the first 3 numbers.
   product = std::accumulate(values.begin(), values.begin() + 3, 1, Mult);
   cout << "The accumulate product is " << product << endl;
   // Isn't that beautiful?

   return 0;
}

int Add(int first, int second) {
   return first + second;
}

int Mult(int first, int second) {
   return first * second;
}

int Div(int first, int second) {
   return first / second;
}

int Max(int first, int second) {
   return first > second ? first : second;
}

int ApplyFunction(int first, int second,  std::function<int(int, int)> function) {
   return function(first, second);
}

int Fold(std::vector<int> &nums, int initial, std::function<int(int, int)> f) {
   for (int &i : nums) {
      initial = f(initial, i);
   }
   return initial;
}
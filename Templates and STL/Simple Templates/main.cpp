#include <random>

#include <iostream>
#include <string>
using namespace std;
// For later:
#include "TemplateHeaders.h"
#include "Rational.h"


// Write a function that finds the median of three integers.
int Median(int a, int b, int c) {
   if ((a <= b && b <= c) || (c <= b && b <= a))
      return b;
   if ((b <= a && a <= c) || (c <= a && a <= b)) 
      return a;
   return c;
}

int mains(int argc, char* argv[]) {
   // Demonstrate Median function.
   cout << "The median of 10, 5, and 2 is " << Median(2, 10, 5) << endl;


   // SUPPOSE: we want to use Median with the other fundamental types:
   // char, short, long, long long, float, double, long double.
   // Which of these types will work with our current Median function?




   // But what about the rest? What if we want the median of 3 doubles?





   // C++ uses "templates" to mark functions that are (mostly) type-agnostic.
   // See the file TemplateHeaders.h

   cout << "The median of 8, 8, and 4 is " << 
      MedianTemplate(8, 8, 4) << endl; // what type is T?
   cout << "The median of 8.5, 10.2, and 4.5 is " <<
      MedianTemplate(8.5, 10.2, 4.5) << endl; // what type is T?

//   MedianTemplate(8, 8.5, 10L);


   // This works even with non-fundamental types.
   Rational r1(2, 3), r2(8, 3), r3(10, 2);
   cout << "The median of " << r1 << ", " << r2 << ", and " << r3 << " is " <<
      MedianTemplate(r1, r2, r3) << endl; // what type is T?

   string a = "aaaa", b = "bbbb", c = "bbbc";
   cout << "Medians even work with strings: " << MedianTemplate(a, b, c) << 
      endl;

   uniform_int_distribution<int> x(1, 10);
   MedianTemplate(x, x, x);

   // In your own words, describe ALL TYPES THAT WILL WORK with MedianTemplate.
   // Account for user-defined types like Rational.





   return 0;
}
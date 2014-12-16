#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
   cout << "This program will find the real solutions to a general quadratic "
    "equation of the form ax^2 + bx + c = 0" << endl;

   cout << "\nEnter a, b, and c:" << endl;

   double a, b, c;
   cin >> a >> b >> c;

   double discriminant = b * b - 4 * a * c;

   // C++ has the same control structures as Java: if, else, else if.
   if (discriminant < 0) {
      cout << "There are no real solutions to that equation." << endl;
   }
   else if (discriminant == 0) {
      cout << "There is one real solution to the equation, and it is x = " <<
       (-b / (2 * a)) << endl;
   }
   else {
      double squareRoot = sqrt(discriminant);
      double x1 = (-b + squareRoot) / (2 * a);
      double x2 = (-b - squareRoot) / (2 * a);

      cout << "There are two real solutions to the equation, and they are:\n"
       "x1 = " << x1 << "\nx2 = " << x2 << endl;
   }
}
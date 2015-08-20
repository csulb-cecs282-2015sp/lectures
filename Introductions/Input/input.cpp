#include <iostream> // for cout and cin
#include <iomanip> // for setprecision
using namespace std;

int main(int argc, char* argv[]) {
   cout << "Enter two numbers: ";
   double x, y;
   cin >> x >> y; // must declare the variables before using cin;
                  // no equivalent to Java's "double x = scanner.nextDouble();"

   cout << x << " divided by " << y << " is ";
   // I want to output x/y but with at most 2 decimal places
   cout << setprecision(2) << (x / y) << endl;

   // cin works with all primitive types
}
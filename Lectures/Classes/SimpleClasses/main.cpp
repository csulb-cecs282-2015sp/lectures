#include <iostream>
using namespace std;


// design a simple class for representing a point in 2D space
class Point {
public: // everything that follows is public
   double X;
   double Y;
};


int mains(int argc, char* argv[]) {
   // variables of type Point can now be declared.

   Point p; // Note the lack of "new" here
   p.X = 5;
   p.Y = 2.5;

   // can we output the object like in Java? 
   //cout << p << endl; 
   // error: no operator "<<" matches these operands
   // operand types are: std::ostream << Point	

   // so we can't do that yet. but we can output individual components.
   cout << "(" << p.X << ", " << p.Y << ")" << endl;

   // similarly, we can cin individual components
   cin >> p.Y;

   return 0;
}
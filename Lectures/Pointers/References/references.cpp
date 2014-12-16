#include <iostream>
using namespace std;

void FunctionWithoutReference(int param);
void FunctionWithReference(int &param);
void DoubleTwo(int &, int &);

int main(int argc, char* argv[]) {
   int x = 10;

   // a "reference" is a variable that acts as an alias for another variable.
   // they are declared with a & in their name.

   // declare a reference to variable x
   int &y = x;

   // any change to y will also change x
   y = 5; // now x has a value of 5

   // WHAT DOES THIS LOOK LIKE ON THE STACK???






   // how about other variable types?
   char c = 'A';
   char &refC = c;
   refC = 'M';
   // on the stack?





   double pi = 3.14159;
   double &refPi = pi;
   refPi = 2.71828;
   // on the stack?






   // references must be initialized at the same time they are declared
   int &z; // error: references must be initialized 
   
   // there is no way to change "who" the variable y refers to once it is set.
   // WHY IS THIS?






   // how does this affect function parameters?
   FunctionWithoutReference(x); // does this change x?


   FunctionWithReference(x); // does THIS change x?




   
   // can I pass an integer literal to a reference parameter?
   FunctionWithReference(5); //initial value of reference to non-const must be an lvalue
   // does this make sense?


   // reference parameter legitimate use #1: changing multiple variables at once
   int a = 4, b = 6;
   DoubleTwo(a, b);
   // what values do a and b have? could this have been done with a return?



}


void FunctionWithoutReference(int param) {
   // we say that "x" from main was "passed by value" to param.
   param = 10;
}


void FunctionWithReference(int &param) {
   // in this case, param is called a "reference parameter",
   // and we say that "x" from main was "passed by reference".
   param = 10;
}

void DoubleTwo(int &first, int &second) {
   first *= 2;
   second *= 2;
}
#include <iostream>
using namespace std;

// We want to access the functions written in mymath.cpp. Since they are not
// defined in a class or namespace, they are "global" and can be used by anyone.

// Remember the compilation process: all the .cpp files in the project are 
// processed into individual "raw" files and sent to the compiler. After 
// compiling, we are left with "object" .o/.obj files for each .cpp file. One
// of those .o files will have the code for the Pow function in mymath.cpp,
// and will be linked with our main.cpp file to produce an executable.

// There is a complication, of course. Our code in this file can't actually call
// the functions in mymath.cpp because the compiler for this file doesn't know
// the signature of those functions (signature: the return type, name, and 
// parameter list of a function). SO we need to declare the existence of each
// function we want to use, but not necessarily give its implementation.

// We will insert some things here in lecture...






int main(int argc, char* argv[]) {
   int a, b;
   cout << "Enter two integers: ";
   cin >> a >> b;

   // example of invalid attempt to use "Pow". find 2^5
   int p = Pow(a, b); // error C3861: 'Pow': identifier not found


   // To use Pow, we need to tell the compiler of its existence, typically at 
   // the top of a file, after the includes.


   // BETTER SOLUTION: use a .h ("header") file to declare the functions we
   // want but not give any implementations. for each .h file, pair a .cpp file
   // with the function implementation. anyone who wants to use the functions
   // can #include the .h file to import the declarations and therefore access
   // the functions.

   cout << a << "^" << b << " = " << p << endl;
   
   // Now, show how to add a new function to our library: Remainder(int, int)





   // Finally, use the Ln function from mymath.h
   cout << Ln(10) << endl;
}


// SUMMARY:
// -- declaration vs. definition.
// -- function prototypes / headers / signatures.
// -- .h vs .cpp files.
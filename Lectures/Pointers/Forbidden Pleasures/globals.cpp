#include <iostream>
#include "GlobalFunctions.h"

using namespace std;

void FunctionA();

// a variable declared outside of a function is called a global variable.
// its scope extends to all functions everywhere.

int globalX;
double globalY;

// Visual Studio doesn't like multiple files with a main(), so sometimes I
// use a slightly different name so the code will compile.
int mains(int argc, char* argv[]) {
   // unlike normal variables, globals have zeroed initial values
   cout << globalX << endl << globalY << endl; // output: 0 0

   // call a function
   FunctionA();
   cout << globalX << endl << globalY << endl << endl; // output: 10 20


   // where are these variables in memory??
   int localX;
   cout << "globalX at address " << &globalX << endl;
   cout << "localX at address  " << &localX << endl; 

   // otherwise the globals follow normal rules for assignment, copying, etc.

   // call a function from GlobalFunctions.cpp
   FunctionC();

   cout << globalX << endl;
}

void FunctionA() {
   // this function has access to globalX and globalY
   globalX = 10;
   globalY = 20;
}
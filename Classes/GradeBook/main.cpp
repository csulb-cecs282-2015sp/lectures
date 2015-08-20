#include <iostream>
#include <string>
using namespace std;

#include "GradeBook.h"
// Even though GradeBook is implemented in another file, all I need is the .h
// to be able to use it here, as long as every method has an implementation in
// SOME CPP file.

int main(int argc, char* argv[]) {
   GradeBook book("CECS 282");
   string mainString = "CECS 228 This is a really long course name";


   book.SetCourseName(mainString); 
   // Parameter passed by reference... could it change?
   book.PrintGreeting(); // What will it print?
}
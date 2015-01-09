#include <iostream>
#include <string>

using namespace std;

// this is where we will IMPLEMENT the GradeBook class.
// we need its DECLARATION from the .h file.
#include "GradeBook.h"

// we now give definitions for every method that was declared in the .h.

// the order does not matter, but we will start with PrintGreeting.


void GradeBook::PrintGreeting() {
// returntype ClassName::MethodName(parameters)
   // in this method I have access to all member variables of GradeBook
   cout << "Welcome to the Grade Book for " << mCourseName << endl;
}

// the constructor does not have a return type
GradeBook::GradeBook(const string &name) 
   //: mCourseName(name) // remember this?
{
   SetCourseName(name);
}

void GradeBook::SetCourseName(const string &newName) {
   // validate the new name
   // arbitrary rules: name must be < 25 characters
   if (newName.length() <= 25)
      mCourseName = newName;
   else {
      // take the first 25 characters only
      mCourseName = newName.substr(0, 25);
   }

   // is there a loophole to this rule?
}

const string &GradeBook::GetCourseName() const { // const!!!
   return mCourseName;
}


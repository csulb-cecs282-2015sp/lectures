#include <iostream>
#include <string>

using namespace std;

// This is where we will IMPLEMENT the GradeBook class.
// We need its DECLARATION from the .h file.
#include "GradeBook.h"

// We now give definitions for every method that was declared in the .h. The 
// order does not matter, but we will start with PrintGreeting.

// To define a member function of a class, we have to SCOPE IT using the ::
// "scope resolution" operator.
// "void GradeBook::PrintGreeting" says that this method returns void, belongs 
// to GradeBook and is named CompareTo.
void GradeBook::PrintGreeting() {
   cout << "Welcome to the Grade Book for " << mCourseName << endl;
}

// The constructor does not have a return type
GradeBook::GradeBook(const string &name) 
   : mCourseName(name) // Remember this?
{
}

// We will use a new SetCourseName mutator, which arbitrarily says that
// course names must be < 25 characters.
void GradeBook::SetCourseName(const string &newName) {
   // Validate the new name
   if (newName.length() <= 25)
      mCourseName = newName;
   else {
      // Take the first 25 characters only.
      mCourseName = newName.substr(0, 25);
   }

   // is there a loophole to this rule?
}

// What is the return type of this method?
const string &GradeBook::GetCourseName() const { // const!!!
   return mCourseName;
}


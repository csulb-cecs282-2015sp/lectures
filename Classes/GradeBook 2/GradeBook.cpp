#include <iostream>
#include <string>

using namespace std;

#include "GradeBook.h"

const int COURSE_NAME_LENGTH = 25;

GradeBook::GradeBook(const string &name, const string &instructor) {
   cout << "Constructing (" << name << ", " << instructor << ")" << endl;
   SetCourseName(name);
   SetInstructorName(instructor);
}


// Boring stuff. Review this on your own time.
void GradeBook::PrintGreeting() {
   cout << "Welcome to the Grade Book for " << mCourseName << endl;
   cout << "This class is presented by " << mInstructorName << endl;
}

void GradeBook::SetCourseName(const string &newName) {
   // Validate the new name
   if (newName.length() <= COURSE_NAME_LENGTH)
      mCourseName = newName;
   else {
      // Take the first 25 characters only
      mCourseName = newName.substr(0, COURSE_NAME_LENGTH);
   }
}

const string &GradeBook::GetCourseName() const { 
   return mCourseName;
}

const string &GradeBook::GetInstructorName() const {
   return mInstructorName;
}

void GradeBook::SetInstructorName(const string &newName) {
   // validate the new name
   // different rules: name must be < 12 characters
   if (newName.length() <= 12)
      mInstructorName = newName;
   else {
      mInstructorName = newName.substr(0, 12);
   }
}



// NEW STUFF. Fill this in.
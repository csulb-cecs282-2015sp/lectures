#include <iostream>
#include <string>

using namespace std;

#include "GradeBook.h"

const int COURSE_NAME_LENGTH = 25;

// We will start with a new SetCourseName mutator, which arbitrarily says that
// course names must be < 25 characters.
void GradeBook::SetCourseName(const string &newName) {
   // Validate the new name
   if (newName.length() <= COURSE_NAME_LENGTH)
      mCourseName = newName;
   else {
      // Take the first 25 characters only
      mCourseName = newName.substr(0, COURSE_NAME_LENGTH);
   }
}

// With SetCourseName modified, what about the constructor? Is it possible for
// someone to make a GradeBook with a course name >= 25 characters?
GradeBook::GradeBook(const string &name, const string &instructor) 
   : mCourseName(name), mInstructorName(instructor) {
   cout << "Constructing (" << name << ", " << instructor << ")" << endl;





}


// Boring stuff. Review this on your own time.
void GradeBook::PrintGreeting() {
   cout << "Welcome to the Grade Book for " << mCourseName << endl;
   cout << "This class is presented by " << mInstructorName << endl;
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
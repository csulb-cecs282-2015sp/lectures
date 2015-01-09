#include <iostream>
#include <string>

using namespace std;

#include "GradeBook.h"


void GradeBook::PrintGreeting() {
   cout << "Welcome to the Grade Book for " << mCourseName << endl;
   cout << "This class is presented by " << mInstructorName << endl;
}

GradeBook::GradeBook(const string &name, const string &instructor) {
   cout << "Constructing (" << name << ", " << instructor << ")" << endl;
   SetCourseName(name);
   SetInstructorName(instructor);
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
}

const string &GradeBook::GetCourseName() const { 
   return mCourseName;
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

const string &GradeBook::GetInstructorName() const { 
   return mInstructorName;
}


// NEW STUFF
GradeBook::GradeBook()
   : mCourseName(), mInstructorName()
{

}

GradeBook::GradeBook(const GradeBook &other)
   : mCourseName(other.mCourseName), mInstructorName(other.mInstructorName)
{
    cout << "Copying (" << mCourseName << ", " << mInstructorName << ")" << endl;
}

ostream& operator<<(ostream &lhs, const GradeBook &rhs) {
   lhs << rhs.mCourseName << ", " << rhs.mInstructorName;
   return lhs;
}

bool operator==(const GradeBook &lhs, const GradeBook &rhs) {
   return lhs.mCourseName == rhs.mCourseName && lhs.mInstructorName == rhs.mInstructorName;
}

GradeBook& GradeBook::operator=(const GradeBook &rhs) {
   mCourseName = rhs.mCourseName;
   mInstructorName = rhs.mInstructorName;
   return *this;
}



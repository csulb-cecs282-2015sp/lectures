#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#include "GradeBook.h"


void GradeBook::PrintGreeting() {
   cout << "Welcome to the Grade Book for " << mCourseName << endl;
   cout << "This class is presented by " << mInstructorName << endl;
}

GradeBook::GradeBook(const string &name, const string &instructor, 
 int numberOfStudents) 
 : mGradesArray(numberOfStudents > 0 ? new int[numberOfStudents] : nullptr),
   mNumberOfStudents(numberOfStudents) {

   cout << "Constructing (" << name << ", " << instructor << ", " << 
    mNumberOfStudents << ")" << endl;

   SetCourseName(name);
   SetInstructorName(instructor);
}

GradeBook::GradeBook()
 : mCourseName(), mInstructorName(), mGradesArray(nullptr), 
   mNumberOfStudents(0) {

}

GradeBook::GradeBook(const GradeBook &other) 
 : mCourseName(other.mCourseName), mInstructorName(other.mInstructorName), 
   mNumberOfStudents(other.mNumberOfStudents) {

   mGradesArray = new int[mNumberOfStudents];
   for (int i = 0; i < mNumberOfStudents; i++) {
      mGradesArray[i] = other.mGradesArray[i];
   }
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
   if (newName.length() <= 12)
      mInstructorName = newName;
   else {
      mInstructorName = newName.substr(0, 12);
   }
}

const string &GradeBook::GetInstructorName() const { 
   return mInstructorName;
}


ostream& operator<<(ostream &lhs, const GradeBook &rhs) {
   lhs << "GradeBook: " << rhs.mCourseName << "; by " << rhs.mInstructorName <<
    "; " << rhs.mNumberOfStudents << " students";
   return lhs;
}

bool operator==(const GradeBook &lhs, const GradeBook &rhs) {
   return lhs.mCourseName == rhs.mCourseName && 
    lhs.mInstructorName == rhs.mInstructorName;
}

GradeBook &GradeBook::operator=(const GradeBook &rhs) {
   mCourseName = rhs.mCourseName;
   mInstructorName = rhs.mInstructorName;
   mNumberOfStudents = rhs.mNumberOfStudents;

   delete[] mGradesArray;
   mGradesArray = new int[mNumberOfStudents];
   for (int i = 0; i < mNumberOfStudents; i++) {
      mGradesArray[i] = rhs.mGradesArray[i];
   }
}

void GradeBook::SetGrade(int index, int value) {
   if (index < 0 || index >= mNumberOfStudents)
      throw out_of_range("grade index out of bounds");
      // what is out_of_range?



   mGradesArray[index] = value;
}

int& GradeBook::operator[](int index) {
   if (index < 0 || index >= mNumberOfStudents)
      throw out_of_range("grade index out of bounds");

   return mGradesArray[index];
}

GradeBook::~GradeBook() {
   delete[] mGradesArray; mGradesArray = nullptr;
}


GradeBook::operator string() const {
   return mCourseName + " by " + mInstructorName;
}

void GradeBook::operator() (int index, int newValue) {
   SetGrade(index, newValue);
}
// the REQUIRED standard for defining classes in C++

#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H
// these are called "include guards" -- ?


// A C++ class is usually split into two files: a .h containing its DECLARATION,
// and a .cpp containing its DEFINITION/implementation.

// Every file is compiled separately and needs to #include any relevant files
#include <string> // for string variable type


// Class declaration for GradeBook.
class GradeBook {
private:
   std::string mCourseName; // do NOT USE NAMESPACES IN .H FILES; SCOPE INSTEAD

public:
   // For methods, we no longer have the body of the method in this file.
   // Only the method header goes here.
   void PrintGreeting();

   // Same for constructors.
   // Why const? Why reference?
   GradeBook(const std::string &name);
   




   const std::string &GetCourseName() const; // wtf is this const doing here?



   void SetCourseName(const std::string &newName);
};

#endif
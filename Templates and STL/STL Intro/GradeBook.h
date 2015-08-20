#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H

#include <string> 
#include <iostream>

// Class declaration for GradeBook.
class GradeBook {
private:
   std::string mCourseName; 
   std::string mInstructorName;
   
   int *mGradesArray;
   int mNumberOfStudents;

public:
   GradeBook();
   GradeBook(const GradeBook &other);
   GradeBook(const std::string &name, const std::string &instructor,
      int numberOfStudents);
   
   void PrintGreeting();

   const std::string &GetCourseName() const; 
   void SetCourseName(const std::string &newName);

   const std::string &GetInstructorName() const; 
   void SetInstructorName(const std::string &newName);

   friend std::ostream& operator << (std::ostream& lhs, const GradeBook &rhs);
   friend bool operator== (const GradeBook &lhs, const GradeBook &rhs);
   GradeBook &operator=(const GradeBook &rhs);


   // NEW STUFF -- fill this in as lecture progresses
   // grade accessor
   int GetGrade(int position);

   // grade mutator
   void SetGrade(int position, int newGrade);

   // operator[]
   int& operator[](int index);

   // destructor
   // a function that gets called when an object goes off the stack
   // or is deleted from the heap
   ~GradeBook();


   // GetAverageGrade
   double GetAverageGrade() const;
   
   // operator std::string
   operator std::string() const;

   
   // operator()
   void operator() (int index, int newValue);

   










};

#endif
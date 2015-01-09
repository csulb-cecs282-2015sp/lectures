#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H

#include <string> 


// Class declaration for GradeBook.
class GradeBook {
private:
   std::string mCourseName; 
   std::string mInstructorName;

public:
   GradeBook(const std::string &name, const std::string &instructor);
   
   void PrintGreeting();

   const std::string &GetCourseName() const; 
   void SetCourseName(const std::string &newName);

   const std::string &GetInstructorName() const; 
   void SetInstructorName(const std::string &newName);

   // NEW STUFF -- fill this in as lecture progresses
   
   // default constructor
   GradeBook();

   // copy constructor
   GradeBook(const GradeBook &other);

   // operator <<
   friend std::ostream& operator<<(std::ostream &lhs, const GradeBook &rhs);


   // operator ==
   friend bool operator==(const GradeBook &lhs, const GradeBook &rhs);

   // operator =

   GradeBook& operator=(const GradeBook &rhs);





















};

#endif
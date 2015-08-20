#ifndef __STUDENT_H
#define __STUDENT_H

#include "UniversityMember.h"
#include <string>
#include <sstream>

class Student : public UniversityMember { // a Student "is-a" UniversityMember
private:
   short mStartYear;
   short mGradYear;
   std::string mMajor;

   // Every Student ALSO has the variables declared in its base class(es).
   // in this case, mLastName, mFirstName, and mID.

   // What does this look like in memory?

public:
   // constructing a Student requires first name, last name, and id; PLUS the 
   // new member variables: major, startYear, and gradYear.
   Student(const std::string &first, const std::string &last, int id, 
    const std::string &major, short startYear, short gradYear) 
    : // when constructing a derived class object, you must first call an
      // appropriate base class constructor. (it can be the default constructor)
    UniversityMember(first, last, id), // call the three-param base constructor,
                                         // then init the Student variables

    mMajor(major), mStartYear(startYear), mGradYear(gradYear) 
   {
   }

   short GetStartYear() const {
      return mStartYear;
   }

   operator std::string() const {
      std::ostringstream s;
      s << mFirstName << " " << mLastName << " (" << mMajor << ", " << mGradYear << ")";
      return s.str();
   }

};

#endif
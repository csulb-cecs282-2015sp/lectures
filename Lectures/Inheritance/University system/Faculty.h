#ifndef __FACULTY_H
#define __FACULTY_H

#include "UniversityMember.h"
#include <string>
#include <sstream>

class Faculty : public UniversityMember {
private:
   std::string mDepartment;
   std::string mOffice;

public:
   Faculty(const std::string &first, const std::string &last, int id,
    const std::string &department, const std::string &office) :
    UniversityMember(first, last, id), 
    mDepartment(department), mOffice(office) {
    //   UniversityMember(first, last, id);

   }

   Faculty(const Faculty &other)
      : UniversityMember(other),
      mDepartment(other.mDepartment), mOffice(other.mOffice)
   {}

   const std::string &GetOffice() const {
      return mOffice;
   }

   operator std::string() const {
      std::ostringstream s;
      s << mFirstName << " " << mLastName << " (" << mDepartment << ", " << 
       mOffice << ")";
      return s.str();
   }
};

#endif
#ifndef __UNIVERSITYMEMBER_H
#define __UNIVERSITYMEMBER_H
#include <string>

class UniversityMember {
protected:
   std::string mLastName;
   std::string mFirstName;
   int mID;
   // What does a variable of type UniversityMember look like in memory?


public:
   // For brevity, I will implement these in the .h file
   UniversityMember(const std::string &first, const std::string &last, int id) 
    : mLastName(last), mFirstName(first), mID(id) {
   }

   std::string GetFirstName() const {
      return mFirstName;
   }

   std::string GetLastName() const {
      return mLastName;
   }

   int GetID() const {
      return mID;
   }

   void SetFirstName(const std::string &first) {
      mFirstName = first;
   }

   void SetLastName(const std::string &last) {
      mLastName = last;
   }

   void SetID(int id) {
      mID = id;
   }
};

#endif
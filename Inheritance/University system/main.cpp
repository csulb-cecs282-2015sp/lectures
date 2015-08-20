#include <iostream>
#include <string>
#include <vector>

#include "UniversityMember.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;


int main(int argc, char* argv[]) {
   // I can declare three types of variables: UniversityMember, Student, Faculty
   Student bob("Bob", "Roberts", 12345, "Computer Science", 2011, 2015);
   
   // We can call any public methods declared in Student or UniversityMember 
   bob.SetFirstName("Bobby");
   cout << (string)bob << endl;

   Faculty neal("Neal", "Terrell", 99999, "Computer Engineering and Computer "
    "Science", "VEC-404A");
   cout << (string)neal << endl;

   // I can also declare a variable of type UniversityMember
   UniversityMember dean("Forouzan", "Golshani", 1);
   // why can't I do the next line?
   // cout << (string)dean << endl;

   
   // How do pointers work with this?
   Student *pStudent = &bob; // a Student pointer to bob
   Faculty *pFaculty = &neal; // a Faculty pointer to neal
   UniversityMember *pUni = &dean;

   // I can do what you would expect with these
   cout << pStudent->GetFirstName() << " started in year " << 
    pStudent->GetStartYear() << endl;
     
   // can I assign from one type to another?
   // neal = bob; // error: no operator= matches these arguments

   // so no, I can't assign from one type to another... but can I take pointers
   // from one type to another??
   // pStudent = &neal;   error: Faculty* cannot be assigned to Student*

   // but I CAN do this!
   pUni = &neal;

   // because Faculty "is-a" UniversityMember, I can assign a Faculty* to a
   // UniversityMember*. 
   // what methods can I call on pUni now?
   cout << pUni->GetFirstName();
   



   // so even though pUni points to an actual Faculty object, I can only call
   // functions from the UniversityMember class on that pointer. WHY CAN'T I 
   // CALL FACULTY FUNCTIONS ON THIS POINTER???




   // to summarise: a pointer to a base type can actually point to any derived
   // type object. You can then call any functions defined at the base class
   // on that pointer.

   
   pUni = &bob;
   // How about taking a base type pointer and using it as a derived type 
   // pointer? This is called "down-casting"
   
   // Can we just assign the base pointer to a derived pointer?
   // pStudent = pUni; //cannot assign UniversityMember* to Student*

   // could pUni *potentially* point to a Student?
   // not the same question as "*does* it point to a Student"

   // yes, it can potentially point to a Student, so we tell the compiler we 
   // know what we're doing by using a cast:
   pStudent = (Student *)pUni; 
   cout << endl << "Start year for pStudent: " << pStudent->GetStartYear() 
    << endl;

   // down-casting can be dangerous if you get the types wrong.
   pUni = &neal; // what does pUni point to now? is that a Student?
   pStudent = (Student *)pUni; // can the compiler detect this is wrong?
   cout << endl << "Start year for new pStudent: " << pStudent->GetStartYear() 
    << endl;



   // one final demo:
   vector<UniversityMember *> members; // a vector of UMember pointers
   members.push_back(&bob); // I can push a pointer to a Student; why?
   members.push_back(&neal); // I can push a pointer to a Faculty; why?
   members.push_back(&dean); // I can push a pointer to a UniversityMember; why?

   cout << endl << endl << "All UniversityMembers created so far:" << endl;
   typedef vector<UniversityMember *>::iterator umItr;
   for (umItr itr = members.begin(); itr != members.end(); itr++) {
      // *itr gives me a UniversityMember*
      cout << (*itr)->GetFirstName() << " " << (*itr)->GetLastName() << endl;
   }
}
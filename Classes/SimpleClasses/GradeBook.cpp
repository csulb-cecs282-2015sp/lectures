#include <iostream>
#include <string>

using namespace std;

// We will declare our own class to represent a grade book for a course.
// We will add to this class over the semester.
class GradeBook {
private:
   // Unlike Java, you do not specify public or private for each item.
   // Everything that follows is private. What does private mean?

   // Here we will define the state/member variables of a Gradebook. What kind
   // of data makes up a grade book?

   // start simple: a string for the name of the course the book is used in
   string mCourseName;
   // style guide: put a 'm' in all member variables names. REQUIRED.



public:
   // This 'public' applies to everything that follows.

   // Define an operation as a method: print a greeting.
   void PrintGreeting() {
      cout << "Welcome to the Grade Book for " << mCourseName << endl;
   }

   // now all we need is a way to tell the GradeBook what its course name is

   // this function, which has no return type and a name that matches the class
   // name, is called a Constructor. It takes parameters necessary to initialize
   // the object state.
   GradeBook(string name) 
      : mCourseName(name) // special syntax: an "initializer list". What for?
   {
      // mCourseName will be initialized with the string passed as a parameter.
   }

   // Go check out the main before reading on...
   
   // write an Accessor and Mutator method for the book's course name
   string GetCourseName() {
      return mCourseName;
   }

   void SetCourseName(string newName) {
      mCourseName = newName; // why is this different than in constructor?



   }
};


int main() {
   // Declare a variable of type GradeBook.
   GradeBook book282("CECS 282"); // DIFFERENT SYNTAX THAN IN JAVA.
   // call the public method PrintGreeting.
   book282.PrintGreeting();
   book282.SetCourseName("New course name");

   string userName;
   cout << "Enter a new name for the grade book: ";
   getline(cin, userName); // what is this? why not cin >> userName?




   book282.SetCourseName(userName);
   cout << endl << "The greeting for the book named " << 
    book282.GetCourseName() << " is:" << endl;
   book282.PrintGreeting();


   // what happens if I want to use GradeBook variables in another file?








}
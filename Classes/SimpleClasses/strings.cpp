#include <iostream>
#include <string> // note this
using namespace std;

/* Explore objects and classes through the Standard Library string class. */

int maint(int argc, char* argv[]) {
   // string is a class. It represents a sequence of characters.
   // We can create a string variable with assignment.
   string s = "Hello"; 
   
   // We can output a string variable with cout.
   cout << s << endl;

   /* 
   s is an "object", and string is a "class". 
   What is the difference between a "class" and an "object"?
   */




   





   /* 
   We will briefly explore C++ objects through the string class.
   A class defines a set of operations called "methods" that can be used
   with the instances of the class. 

   To access a method of an object, use the period . operator. This "calls"
   the method and does something to or with the object.
   */

   // Example: print the length of a string.
   cout << s.length() << endl; // .length() gives the # of characters in s


   // Declare another object of type string
   string other = "Other string";

   // Unlike Java, C++ strings are mutable (can be changed).
   s.append(", world!");// By calling this method, the object's state is changed
   s.insert(0, "Yay! ");// This lets us insert at an index instead of the end.

   // append and insert are methods of the class, and define operations that can
   // be applied to the state of an object. Operations on one object do not 
   // change the state of a different object.


   // Now that the state of s has changed, its output will change.
   cout << s << endl;

   // But has "other" changed?
   cout << other << endl;




   // Some simple functions of the string class:
   cout << s.at(0) << endl; // retrieve character at index 0
   cout << s[0] << endl;    // can also do s[0]


   cout << s.find(',') /* gets first index of the character ',' */ << endl;

   // extract a substring. first parameter: start index. second: length.
   string sub = s.substr(5, s.size() - 5);
   cout << sub << endl; 
   // What will this output?



   /*
   SUMMARY:
   With the string class, we can declare variables of the string type. Each 
   "instance" of this class stores a state and provides methods that can 
   operate on that state. Changing one object's state does not affect other
   objects of the same class.
   */
   return 0;
}
#include <iostream>
#include <string> // need this
using namespace std;

int maint(int argc, char* argv[]) {
   // string is a class.
   string s = "Hello";
   cout << s << endl;
   // s is an object. What is the difference between class and object?




   





   // we will briefly explore C++ objects through the string class


   // unlike Java, C++ strings are mutable
   s.append(", world!");// by calling this method, the object's state is changed
   s.insert(0, "Yay! ");// insert at an index 

   // append and insert are methods of the class, and define operations that can
   // be applied to the state of an object.

   // now when I output s, its state has changed, and its output will change.
   cout << s << endl;


   // show some simple functions of the string class
   cout << s.at(0) << endl; // retrieve character at index 0; can also do s[0]
   cout << s[0] << endl;


   cout << s.size() /* OR .length() */ << " : " << s.empty() /* length == 0 */ << endl;
   cout << s.find(',') /* index of the character ',' */ << endl;

   // extract a substring. first parameter: start index. second: length.
   string sub = s.substr(5, s.size() - 5);
   cout << sub << endl; 
   // what will this output?



   // With the string class, we can declare variables of the string type. Each 
   // "instance" of this class stores a state and provides methods that can 
   // operate on that state. Changing one object's state does not affect other
   // objects of the same class.
   return 0;
}
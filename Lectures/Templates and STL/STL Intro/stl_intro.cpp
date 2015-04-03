/* 
Introduction (and in some cases, re-introduction) to C++'s Standard Library.
Review of simple library types we have used, plus new types needed for project 2
*/
#include <string>

/*
iostream contains the istream and ostream classes, representing input/output
to various devices. Contains variable declarations for cin and cout
*/
#include <iostream>

/*
sstream contains istringstream and ostringstream, which are versions of istream
and ostream that do input and output not from the console, but to/from a string
variable.
*/
#include <sstream>

/*
Before the Standard Library, there came something called the Standard Template
Library (STL). The STL was a collection of classes and functions over four 
domains: algorithms, containers, function objects, and iterators. The STL was
later expanded to the full Standard Library to include streams, strings, plus
the old STL code. Many programmers still use "STL" to refer to the full 
Standard Library.
*/

/*
C++'s version of an "array list" is called vector. The STL refers to data 
structures like vector as "containers". The vector container has three important
properties: the elements are ordered in a strict linear sequence; the 
internal array grows dynamically as elements are added to the vector; and the 
container is *templated*, meaning it can contain literally any type of variable.
*/ 
#include <vector>

// all of the types provided by C++ are in the std namespace
using namespace std;

int mains(int argc, char* argv) {
   // ostringstream: "print" to a string variable instead of the console.
   ostringstream os;
   os << "(2, 3)";
   string buffer = os.str();
   cout << buffer << endl;

   istringstream is(buffer); // open a cin-like input stream on the given string
   char temp;
   int first, second;
   is >> temp >> first >> temp >> second >> temp;
   cout << first << "::" << second << endl << endl;



   vector<int> intList; // declares a vector of integers
   intList.push_back(4);
   intList.push_back(8);
   intList.push_back(15);
   intList.push_back(16);
   intList.push_back(23);
   intList.push_back(42);
   cout << "Vector size: " << intList.size();
   // vector only allows insertion at the end of the sequence. why?





   


   // can access individual elements with methods or operators
   cout << intList.front() << "::" << intList.back() << endl;
   cout << intList.at(4) << endl;
   cout << intList[2] << endl << endl; // what operator is this?




   // as with insertion, we can only remove from the end.
   intList.pop_back();


   // Demonstrate four ways of accessing all the elements of a vector.

   // Method 1: simple indexing.
   for (int i = 0; i < intList.size(); i++) {
      cout << intList[i] << endl;
      // Pros?


      // Cons?



   }


   // Method 2: iterators

   // the vector class can be walked through using an object called an iterator
   vector<int>::iterator itr; // declare variable of type vector<int>::iterator
   // "start" an iterator at the beginning of a vector with .begin()
   itr = intList.begin();

   // use ++ to move the iterator to the next element in the vector, and * the
   // iterator to access the thing it currently points to. This looks like a...?
   cout << "*itr: " << *itr << endl;
   itr++;

   // can keep an iterator walking as long as it doesn't get to
   // the end of the vector.
   while (itr != intList.end()) {
      cout << "*itr: " << *itr << endl;
      itr++;
   }


   // This is typically done with a for loop like this:
   for (vector<int>::iterator itr2 = intList.begin(); itr2 != intList.end(); 
    itr2++) { // doesn't even fit on one line :(

      cout << "*itr2: " << *itr2 << endl;

      // the return type of *itr2 is a REFERENCE to the vector's value type

      // Pros:



      // Cons:




   }



   // Method #3: using typedef
   // Method 2 is verbose. The typdef keyword lets us use an alias for a long 
   // type name.
   typedef vector<int>::iterator IntItr; // alias for vector<int>::iterator
   for (IntItr itr2 = intList.begin(); itr2 != intList.end(); itr2++) {
      cout << "*IntItr: " << *itr2 << endl;
   }



   // Method #4: enhanced for loop. In C++11, you can automatically pull out
   // elements of a container one at a time with an enhanced for loop.
   for (int &i : intList) { // "for each int called 'i' inside intList, do this"
      // Best if this is always a reference.


      cout << "For loop: " << i << endl;

      // Pros:



      // Cons:



   }


   // Iterators are used in many functions because they "identify" a 
   // spot in a container.
   // We now can remove from anywhere in a vector using an iterator.
   intList.erase(intList.begin()); // removes the first element
   intList.erase(intList.begin(), intList.begin() + 2); // erases first 2 items
                                  // WHAT IS HAPPENING HERE??? iterator + 2 ???




   return 0;
}
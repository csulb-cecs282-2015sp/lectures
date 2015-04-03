#include <vector>
#include <iostream>

#include "GradeBook.h"

using namespace std;

int main(int argc, char* argv[]) {
   // suppose you want a vector of variables created on the heap.
   // why would you want this?




   // let's go with a vector of GradeBooks, where the books are on the heap.
   vector<GradeBook *> books; // a vector of pointers to books on the heap.
   books.push_back(new GradeBook("CECS 282", "Neal Terrell", 10));
   books.push_back(new GradeBook(*books[0])); // ?
   books.push_back(new GradeBook("CECS 579", "Mehrdad Aliasgari", 20));
   
   // two ways to access these elements:

   cout << endl << "With iterators" << endl;
   for (vector<GradeBook *>::iterator itr = books.begin(); itr != books.end();
    itr++) {
      cout << **itr << endl; // ** ??




   }

   cout << endl << "With enhanced for loop" << endl;
   for (GradeBook *b : books) {
      cout << *b << endl;
   }


   // what happens if I clear this vector?
   // books.clear();





   GradeBook *last = books.back();
   delete last;
   books.pop_back();


   // so how do I safely clear a vector of heap pointers?
   for (GradeBook *b : books) {
      delete b;
   }
   books.clear();





}
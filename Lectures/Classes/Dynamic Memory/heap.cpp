#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
   int x = 10;
   // where is x in memory?
   // when is x removed from memory?
   // who governs this?





   // the stack is not the only memory location for variables.
   // what if I want a variable that does NOT get removed when it goes 
   // out of scope?

   // the "new" keyword can create a variable of a certain type in a
   // memory location called the heap.
   // when using new, you get back a pointer to this heap location.

   int *heapInt = new int(10);
   // heapInt points to an arbitrary heap position containing a value of 10.
   // how does the heap decide *how much* memory to give you?





   // we can use heap pointers like any other pointer.
   cout << "The value on the heap is " << *heapInt << endl;
   *heapInt = 100;
   cout << "Now it is " << *heapInt << endl;


   // we can do this with any variable type, even class types.
   string *heapString = new string("No reason to do this, just an example");
   cout << *heapString << endl;


   // THE MOST IMPORTANT THING TO KNOW ABOUT THE HEAP:
   // if you new it, you must make sure that someone deletes it

   // as soon as you know you are done with a heap variable, you can "free" its
   // memory using the delete keyword.
   delete heapString; // done with heapString, free its memory.

   // what happens if I don't delete it?







   // I can also allocate a dynamically-sized array with new. !!!
   int* heapArray = new int[*heapInt];
   // array's size is not known at compile time, so it cannot go on teh stack.
   // the heap, though, can grab a dynamic amount of memory at run time!

   heapArray[0] = 100;
   cout << heapArray[0] << endl; // etc

   // to delete a dynamic array, you MUST use delete[]
   delete[] heapArray;


   
   system("pause");
   // demonstrate a memory leak. DON'T DO THIS.
   int total = 0;
   for (int i = 0; i < 1000000; i++) {
      int *p = new int(pow(i, 2));
      total += *p;
      delete p;
   }
   system("pause");
}
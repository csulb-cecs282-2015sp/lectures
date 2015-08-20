#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
   int x = 10;
   /*
   Where is x in memory?
   How many int variables do I get when I declare x?
   When is x removed from memory?
   Who governs this?
   These answers together form "static memory management": rules for managing
   memory for variables whose demands do not change past compile time.
   */


   /*
   Some memory patterns require us to break these rules. Sometimes we need
   variables that "live" outside the scope they were constructed in.
   Sometimes we don't know how much memory we will need at compile time.
   Sometimes we want explicit control over when to free the memory for a
   variable. This requires a second location for storing variables, called
   "the heap".
   */

   /*
   The "new" keyword is used in C++ AND in Java to declare a variable on the
   heap. Combine "new" with the name of a type to create a variable of that type
   on the heap. "new" gives back to you a POINTER to the heap variable.
   */
   int *heapInt = new int(10); // inside the parentheses: initial value

   /*
   heapInt is a pointer on the stack; it gets 4 bytes of space. It POINTS TO
   4 bytes for an integer on the heap. We do not know where this space will be
   when we run the program, only that it is not on the stack. heapInt itself
   will be popped when it goes out of scope, but the memory it points to will
   not be freed until we explicitly say to.
   */


   // We can use heap pointers like any other pointer.
   cout << "The value on the heap is " << *heapInt << endl;
   *heapInt = 100;
   cout << "Now it is " << *heapInt << endl;

   /*
   THE MOST IMPORTANT THING TO KNOW ABOUT THE HEAP:
   If you new it, you must make sure that someone deletes it

   As soon as you know you are done with a heap variable, you can "free" its
   memory using the delete keyword.
   */
   delete heapInt; // done with heapInt, free its memory.

   /*
   This DOES NOT remove the heapInt POINTER FROM THE STACK; it only "marks"
   the heap space that heapInt POINTS TO as "freed", meaning that someone else
   may come along and use that space for something else.
   heapInt still exists and still points to the "freed" location, making for
   subtle bugs:
   */
   *heapInt = 500;
   // WARNING: the 4 bytes heapInt points to was deleted; I am now writing to 
   // memory that I do not own.

   // To prevent errors like above, set a pointer to nullptr after deleting it:
   heapInt = nullptr;


   // What happens if I don't delete heapInt?







   // Suppose we create a new int for heapInt to point to.
   heapInt = new int(100);


   // I can also allocate a dynamically-sized array with new. !!!
   int* heapArray = new int[*heapInt];
   // The array's size is not known at compile time, so it cannot go on the 
   // stack. The heap, though, can grab a dynamic amount of memory at run time!
   heapArray[0] = 100;
   cout << heapArray[0] << endl; // etc

   // to delete a dynamic array, you MUST use delete[]
   delete[] heapArray;
}
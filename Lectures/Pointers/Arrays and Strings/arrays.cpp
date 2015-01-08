#include <iostream>

using namespace std;

int mains(int argc, char* argv[]) {
   int x = 10;
   
   // in C and original C++, the value 0 meant "null" for pointers.
   // these days, we use the reserved keyword "nullptr" for "null"
   int *p1 = nullptr, p2; // what type is p2? Hint: not a pointer.


   // to make sure we're on the same page, what is the output of this code?
   p1 = &p2;
   if (*p1 = x++) // NOTE: =, not ==
      *(&x) = *p1;



   // in C and C++, arrays have an intimate relationship with pointers.
   int numbers[] = {1, 2, 3, 4, 5};
   // the name of an array variable is also a pointer to the first element
   p1 = numbers; // make p1 point to the first element in numbers

   *p1 = 100; // what changed?


   // pointers can be indexed like arrays. what exactly is going on here?
   cout << p1[0] << endl; // index 0 of a pointer???
   cout << p1[1] << endl;
   cout << p1[2] << endl; // what is the output?


   /* EXERCISE:
   Suppose "numbers" has a memory address of 100. What are the addresses of each
   element in numbers?







   How did you calculate this?
   */

   // more fun with pointers to arrays.
   // if I add 1 to a pointer, I "advance" the pointer by "1 position"
   int *p3 = p1 + 1; // p3 points to numbers[1]
   *p3 = 200;

   // this can be combined in one line as such:
   *(p1 + 2) = 0; // sets numbers[2] = 0
   *(p1 + 3) = 0; // sets numbers[3] = 0;
   // seeing a pattern?

   // this gives us a sexy form of for loop:
   for (int *itr = numbers; itr != numbers + 5; itr++) {
      cout << *itr << endl;
   }
   // what is this doing?


   // another famous loop: copy 5 elements from numbers to a new array
   int copyNumbers[5]; // uninitialized
   for (int *i = numbers, *j = copyNumbers; i != numbers + 5; i++, j++) {
      *j = *i;
   }


   // lessons: arrays are pointers; pointers can be treated as arrays. 
   // when does this make sense? when does it not?


   return 0;
}
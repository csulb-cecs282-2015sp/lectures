#include <iostream>
using namespace std;

void ChangePointer(int *); 
void ChangeReference(int &); 
void ChangeTwoPointers(int *, int *);

int main(int argc, char* argv[]) {
   // basics of pointers in C++
   int x = 5, y = 100; // normal int variables


   // a pointer is a special variable that "points" to another variable.
   // pointers are initialized by assigning the *address* of another variable

   // When DECLARING a variable, & is for reference; * is for pointer
   int *p;
   // do not need to initialize a pointer, unlike a reference.

   // to make a pointer "point" to a variable, set it equal to the address of 
   // the variable.

   p = &x; // & means "address of"; &x means "address of x". assigning &x to p
           // makes p point to x.

   // WHAT DOES THIS LOOK LIKE ON THE STACK?
   // remember, a pointer's value in memory is always an address






   
   /*
   To change the VALUE of the thing p points to, we use the * operator on p to
   "de-reference" the pointer. This gives us access to the actual memory that
   it points to. We can then read or write to that memory as usual.
   */
   *p = 10; // this changes the value of the thing that p points to (which is x)

   
   // Pointers are type-safe, somewhat: can't assign int* to double*
   // double *cant = &x; // error: cannot convert from 'int *' to 'double *'

   // But you can assign one pointer to another
   int *otherPointer = p;
   // This line DECLARES a pointer and INITIALIZES IT to point to the thing 
   // p points to.
   *otherPointer = 100; // what does this change?

   /* 
   MINI QUIZ:
   Which of these statements will not compile?

   int *a = &x;
   int *b = &a;
   int *c = 10;
   short *d = &x;
   int *e = *a;
   */


   /*
   So a pointer is kind of like a reference variable... in both cases, a change
   to one variable actually changes another... but with different syntax.
   */
   int &refToX = x;
   int *ptrToX = &x;

   // these two lines do the same exact thing: change the memory for x
   refToX = 20;
   *ptrToX = 20; 

   
   // Pointers, unlike references, can have their "target" changed.
   refToX = y; // LOGIC ERROR: this assigns a copy of y's value to x's value
   
   ptrToX = &y; // this does not change x's value; it makes ptrToX "point to" y
   *ptrToX = 40; 

   // What does this output now?
   cout << "X is: " << refToX << endl;
   cout << "*ptrToX is: " << *ptrToX << " -- y is: " << y << endl;



   /*
   Pointers can be passed to functions. Like references, this allows the 
   function to change a parameter so that the caller sees the change.
   */
   ChangePointer(ptrToX); 
   // The address ptrToX points to is copied to the function's parameter...
   // then what?
   cout << "After function, *ptrToX == " << *ptrToX << endl;

   // It is more common to pass &y directly to the function.
   ChangePointer(&y);
   cout << "After function, y and *ptrToX == " << *ptrToX << " (" << y << ")" 
      << endl;

   
   return 0;
}

void ChangePointer(int *p) {
   *p = 1000;
}

void ChangeReference(int &r) {
   r = 2000;
}

void ChangeTwoPointers(int *p1, int *p2) {
   *p1 = -1;
   *p2 = -2;
}
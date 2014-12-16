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

   // & is for reference; * is for pointer
   int *p;
   // do not need to initialize a pointer, unlike a reference.

   // to make a pointer "point" to a variable, set it equal to the address of 
   // the variable.

   p = &x; // & means "address of"; &x means "address of x". assigning &x to p
           // makes p point to x.

   // WHAT DOES THIS LOOK LIKE ON THE STACK?
   // remember, a pointer's value in memory is always an address

   
   // to change the VALUE of the thing p points to, we use the * operator to
   // "de-reference" the pointer.
   *p = 10; // this changes the value of the thing that p points to (which is x)

   
   // pointers are type-safe, somewhat: can't assign int* to double*
   //double *cant = &x; // error: cannot convert from 'int *' to 'double *'

   // but you can assign one pointer to another
   int *otherPointer = p;
   // this line DECLARES a pointer and INITIALIZES IT to point to the thing 
   // p points to.



   // so a pointer is kind of like a reference variable
   int &refToX = x;
   int *ptrToX = &x;

   // these two lines do the same exact thing: change the memory for x
   refToX = 20;
   *ptrToX = 20; 

   // pointers, unlike references, can have their "target" changed
   refToX = y; // LOGIC ERROR: this assigns a copy of y's value to x's value
   ptrToX = &y; // this does not change x's value; it makes ptrToX "point to" y
   *ptrToX = 40; // now y has value 40, as does (*ptrToX)


   cout << "X is: " << refToX << endl;
   cout << "*ptrToX is: " << *ptrToX << " -- y is: " << y << endl;

   // pointers can be passed to functions.
   ChangePointer(ptrToX); 
   // the VALUE of ptrToX gets copied to the function's int* parameter; then...?
   cout << "After function, *ptrToX == " << *ptrToX << endl;

   // so dereferencing the parameter in the function changed the memory the 
   // pointer referred to.

   // more common to pass &y directly to the function
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
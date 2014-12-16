#include <iostream>
using namespace std;

void FunctionWithArray(int[]); // we'll use this below
void OtherFunctionWithArray(int *);

int main_(int argc, char* argv[]) {
   // in C++, arrays are actually pointers. WHAT?!?
   int arr[5] = {0, 1, 2, 3, 4};
   // the name of the array is actually a pointer of the same type, 
   // so arr is ACTUALLY a variable of type int *
   // the VALUE of the array pointer is the address of the first element in 
   // the array, i.e. &arr[0]

   int *ptrToArr = arr;
   int *otherPtr = &arr[0];
   cout << "arr: " << ptrToArr << "; &arr[0]: " << otherPtr << endl;

   // which means I can also INDEX pointer types the same way I'd index an array
   cout << ptrToArr[0] << endl; // ptrToArr is not declared as an array!
   cout << *ptrToArr << endl;

   // this gives alternatives for passing arrays to functions
   FunctionWithArray(arr); // pass arr as the int[] argument to the function
   cout << "after Function: " << arr[0] << endl;
   OtherFunctionWithArray(arr); //arr is actually int* and can be passed as such
   cout << "after OtherFunction: " << arr[0] << endl;

   cout << endl << endl;

   
   return 0;
}

void FunctionWithArray(int a[]) {
   a[0] = 100;
}

void OtherFunctionWithArray(int *a) {
   a[0] = 200;
}
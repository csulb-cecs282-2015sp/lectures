#include <iostream>
using namespace std;

// prototype for a function taking an array of ints
void ProcessArray(int[]); // not necessary to put dimensions, but optional
void ProcessArray(int[5]); // compiler does NOT ENFORCE the dimension

void ProcessMatrix(int[][3]); // must give second dimesion for multidim arrays

int mains(int argc, char* argv[]) {
   int numbers[] = {1, 2, 3, 4, 5}; // what does this look like on the stack?
   
   ProcessArray(numbers);
   // what does numbers look like now?

   cout << numbers[0] << endl; // this was changed by ProcessArray function

   int matrix[3][3] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}
   };

   ProcessMatrix(matrix);
   cout << matrix[0][2] << endl; // this was changed by ProcessMatrix function
   cout << matrix[1][0] << endl; // NOTE: this index was not changed by function

   return 0;
}

void ProcessArray(int arr[]) {
   // what does arr look like on the stack?
   arr[0] = 100;
}

void ProcessMatrix(int m[3][3]) { // can specify both dimensions too
   m[0][2] = 1000;
   m[0][3] = 5000; // is there a matrix element at 0, 3?
}

// SUMMARY
// arrays of all dimensions are not duplicated when passing to functions, so 
// any change in the function will change the same array as referenced at the
// calling site.
// multidimensional arrays align their contents in a sequential block.
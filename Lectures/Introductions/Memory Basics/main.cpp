#include <iostream>
#include "mymath.h"
using namespace std;

// For later.
int A(int);
int B(int);

// Every C++ program uses a chunk of memory called the "stack" for recording
// the values of its variables. Each function creates a "stack frame" when the
// function is entered, containing the stack space for all of its variables.
int main(int argc, char* argv[]) {
    double y;
    int x;
    char z;

    // These three variables are placed in the stack frame for main. Do all 
    // variables go on the stack? What does this even mean?



    // When a variable is assigned to, its memory on the stack is given the 
    // value from the assignment.
    x = 10;
    y = 5.0;
    z = 127;


    
    // Arrays go on the stack, too.
    int values[4] = {0, 1, 2, 3};

    

    // What about assignment from one variable to another?
    int number = x;


    // Each { } block creates a mini stack frame, too.
    if (true) {
       int a = 5;

       // When the stack frame for a variable ends, that variable is "popped"
       // off the stack.

       // THIS EXPLAINS SO MUCH!...
    }
    // ... like why I can't use variable 'a' once the } has closed!
    // a = 5; ERROR: identifier 'a' is undefined.

    
    // What about a function call?
    int ret = Abs(number); 
    // What happens to the stack going into and out of this function call?





    // How about a more complicated method chain?
    cout << A(x) << endl;



}

int A(int param) {
   return B(param);
}

int B(int param) {
   int local;
   local = Pow(param, 2);
   return local;
}

/*
SUMMARY:
   -- what is the stack?
   -- what things go on the stack?
   -- what is a stack frame?
   -- when are things removed from the stack?
   -- what does this mean in the context of reading and writing variables?
*/
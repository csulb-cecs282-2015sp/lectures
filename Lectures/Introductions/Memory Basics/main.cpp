#include <iostream>
#include "mymath.h"
using namespace std;

int A(int);
int B(int);

int main(int argc, char* argv[]) {
    double y;
    int x;
    char z;

    x = 10;
    y = 5.0;
    z = 127;

    int values[4] = {0, 1, 2, 3};

    // draw a picture of the STACK FRAME for the main method.

    int number = x;
    int ret = Abs(number); 
    // what happens to the stack going into and out of this function call?





    // how about a more complicated method chain?
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
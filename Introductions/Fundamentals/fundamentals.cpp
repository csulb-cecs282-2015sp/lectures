#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
   // ALL fundamental types in C++:
   // bool, char, short, int, long, float, double, long long, long doubles
   
   int x = 10; // the number 10 is called a literal
   int y;


   // normal math operators are the same as in Java: + - * / % 
   y = x + 5;
   y = y + 1;
   // what is the value of y?

   // integer division rounds down, as in Java
   x = y / 6;
   // what is the value of x?
   x = y % 6;

   // multiplying a floating point-type with an integer-type casts up to the 
   // floating point type
   double pi = 3.14159;
   double area = pi * y * y; // double * int * int --> double


   int i = 5.5;


   // What is the value of this variable?
   double complicated = 5.0 * 3 + 5 / 2 - 15.9;
   // Edit this file yourself and cout the variable. Make sure the output is
   // what you expect.





   // bool values: true and false
   bool b = false, e = true, f = false;

   

   // bools are actually integers and can be assigned integer values. 
   // any non-zero integer is treated as "true"
   b = 2; // what is b?
   



   cout << "QUESTION OF THE DAY: " << (b + e + f) << endl;
   // what is the output?



   // if you involve a bool in arithmetic, it is treated as having a value of 1 
   // if true, and 0 if false.
   x = x + b;

   // integer values can be expressed in hex (base 16) or oct (base 8) notation:
   x = 0x2A; // 0x --> start of a hex number
   y = 031;  // 0  --> start of an octal number



   // char types are for characters. character literals are enclosed in ''
   char c = 'A';
   // characters have integer values according to the ASCII code chart. you can
   // assign a char to an int, and the int will have the ASCII code for the char
   x = c;
   
   //  this has interesting consequences
   char d = x + 5;
   // what is the value of d?
   x = 'J' - d;


   // size and range of integer types
   // nifty C++ operator: sizeof
   int sizeOfInt = sizeof(int);
   int sizeOfShort = sizeof(short);
   int sizeOfLong = sizeof(long);
   int sizeOfChar = sizeof(char);
   int sizeOfLongLong = sizeof(long long);

   // C++ DOES NOT GUARANTEE the # of bytes for most fundamental types. it only
   // makes the following promise:

   // sizeOfChar = 1
   // sizeOfShort <= sizeOfInt <= sizeOfLong < sizeOfLongLong
   
   // the actual sizes are IMPLEMENTATION-DEPENDENT 
   // (whoever wrote the compiler gets to choose)



   // signed vs unsigned
   signed short ss = 32768; // the "signed" is optional and rarely used
   unsigned short us = 32768; // use the MSB for data, not for a sign. 
   // char, short, int, long can all be unsigned
}
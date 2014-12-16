#include <iostream>

using namespace std;
int main(int argc, char* argv[]) {
   // in C, strings are arrays of characters, with the last letter followed by 
   // the special character '\0', which has an integer value of 0.

   char cStr[] = {'h', 'e', 'l', 'l', 'o', '\0'}; // this is a "c-string"

   cout << cStr << endl; // cout knows how to work with c-strings.
   // so... how does cout do this printing? C arrays don't know their size...



   // like all arrays, I can change the string through indexing.
   cStr[0] = 'c'; // "cello"
   cStr[4] = 's'; // "cells"
   
   // can also access individual characters
   cout << cStr[2] << endl; // output?

   // what if I put something in cStr[5]?
   cStr[5] = '?'; // "cells?"... or is it?




   // fix the damage we just did
   cStr[5] = '\0'; // can also set = 0;


   // can we cin with c-strings?
   cout << "What is your name? ";
   cin >> cStr; // compiles OK... but how many chars can cStr actually store?
                // does cin know that?

   cout << "Hello, " << cStr << endl;


   // now we know that arrays are pointers, we know c-strings are really char*
   char *pStr = cStr;
   cout << pStr << endl; // special cout rules for char*: print as a string

   // can also assign a char* to a string literal
   char *str = "cello"; // where is the memory for "cello" located? 

   // when you do this, you CANNOT change the string through indexing
   str[0] = 'h'; // because str was set to a string literal, it is immutable
   // this will run but the behavior is undefined.


   // check this out. what does this do?
   char *cp = str;
   while (*cp) 
      cout << *cp++;
   cout << endl;
}
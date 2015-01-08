// demonstrate the "goto" statement
#include <iostream>
using namespace std;

void Function();
void LegitimateGoto();

int main(int argc, char *argv[]) {
   // the goto statement allows you to jump to another part of code that has 
   // been "labeled". 

   int a = 0;

   // here is a label:
X: // most compilers put labels in the far left column
   cout << a << endl;
   a++;
   if (a < 5)
      goto X; // jump back to the label X

   // so what does that code do?
   
   // labels do NOT have to be declared before being used
   goto Y; // Y is below
   cout << "This never gets executed" << endl;


Y: cout << "But this does" << endl;

   goto Z; // can you jump to a label in another scope?
   // error: Z was referenced but not defined

   LegitimateGoto();
}

void Function() {
Z:
   cout << "In a function" << endl;
   // why does it make sense that you can't jump to another scope?
   // hint: think of the STACK
}

void LegitimateGoto() {
   // there is one main legitimate use of a goto (IMHO)
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         if (i == 5 && j == 8) {
            // suppose I want to terminate both loops at this point. what are 
            // my NON-goto options?
            




         }
      }


   }

exit:



   cout << "I want this to happen by getting out of the inner for loop " << endl;
}
#include <iostream>
using namespace std;

// function declaration / function prototype
int Pow(int, int);
int Pow(double, double);

int main() {
   // let's call a function declared below
   
   // calculate 2^5
   int p = Pow(2, 5); // error C3861: 'Pow': identifier not found

   cout << p;
}

int Pow(int base, int exponent, int x) { // NOTE: no "public" or "static"
   int result = 1;
   for (int i = 0; i < exponent; i++) {
      result *= base;
   }
   return result;
}

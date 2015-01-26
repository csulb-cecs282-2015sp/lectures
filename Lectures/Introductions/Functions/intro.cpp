#include <iostream>

using std::cout; // if you only need one thing from std, you can scope directly

// I called this "mains" because C++ doesn't like two methods with the same name
int mains(int argc, char* argv[]) {
   // Let's call a function declared below, like in Java.

   int p = Power(2, 5); // error: 'Power': identifier not found
   cout << p;
   return 0;
}

int Power(int base, int exp) { // no 'public' or 'static'
   int result = 1;
   for (int i = 0; i < exp; i++)
      result *= base;
   return result;
}
#ifndef __TEMPLATEHEADERS_H
#define __TEMPLATEHEADERS_H





template <typename T>
T MedianTemplate(T a, T b, T c) {
/*
"template <typename T>" states that the following declaration can use an
unknown type "T" as a variable type. When the function is *actually used*,
the compiler will generate a copy of the function's body by filling in T with
the actual type used by the programmer.
*/

   // We can write any code here that we want, using variables of type T even 
   // though we don't know what T will eventually be.
   if ((a <= b && b <= c) || (c <= b && b <= a))
      return b;
   if ((b <= a && a <= c) || (c <= a && a <= b))
      return a;
   return c;

   // Now return to main...
}

#endif
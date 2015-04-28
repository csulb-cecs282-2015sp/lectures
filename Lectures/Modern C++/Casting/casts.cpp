#include <iostream>
#include <string>
using namespace std;

class A {
public:
   virtual void F() {
      cout << "A" << endl;
   }
};
class B : public A {
public:
   virtual void F() {
      cout << "B" << endl;
   }
};

class C : public A {
public:
   virtual void F() {
      cout << "C" << endl;
   }
};

int main(int argc, char* argv[]) {
   // Casting variables using (_____) syntax is called a C-style cast. It still
   // works in C++ but has some issues.

   double g = 9.8;
   cout << (int)g << endl;

   // When casting from one value type to another, the compiler will check types
   // to make sure they are compatible.
   string s = "5";
   // cout << (int)s << endl;  no suitable conversion from string to int
   // string does not have an operator int().

   // This works well enough... until you start casting pointers.
   double *pD = &g;
   int *pI = (int*)pD;

   // The compiler allows this cast even though pD could not POSSIBLE point to
   // an int variable. All pointer casts are valid using C-style casts.

   // Another example:
   B *pB = new B;
   // C *pC = pB; this doesn't compile, because a pointer to a B could not
   //             validly point to a C.
   // BUT a C-style cast can get around this.
   C *pC = (C*)pB; // allowed... but valid???


   // Modern C++ prefers a stricter casting operator that enforces valid types.
   // It is called a "static_cast".
   cout << static_cast<int>(g) << endl;
   // It is longer, but get over it: this is the preferred method for modern C++

   // static_cast enforces value conversions as before.
   // cout << static_cast<int>(s);   no conversion from string to int.

   // It also enforces POINTER CASTS.
   // pC = static_cast<C*>(pB);   error: invalid type conversion!!!


   // So you should use static_cast for all your "normal" casting needs when
   // they do NOT involve polymorphism.


   // A second type of cast is dynamic_cast, which is used for safely down-
   // casting a polymorphic pointer.

   A *pA = new B; // pA actually points to a type B object.
   try {
      pB = dynamic_cast<B*>(pA);
      // If pA actually pointed to a B, then pB will point to the same B object.
      // If pA didn't point to a B (it could have pointed to a C), then a 
      // std::bad_cast exception will be thrown.

      // dynamic_cast is SUPPOSED to throw bad_cast if the cast is invalid, but
      // Visual Studio doesn't seem to do this. Instead, pB is set to nullptr
      // if the cast is invalid.

      // The following if statement can cover this behavior.
      if (pB) {
         // I can use pB here.
      }

   }
   catch (std::bad_cast &e) {
      cout << "Bad cast!" << endl;
   }
   

   
   // So you should use dynamic_cast anytime you need to turn a base class 
   // pointer into a derived class pointer, and optionally check to make sure
   // the cast succeeded.


   // A third cast can be used to "strip" a variable of its const-ness.
   const int cX = 10;
   int &rX = const_cast<int&>(cX); // need a reference to cX so we can change it.
   rX = 100; // Huzzah!

   // Use const_cast only with good reason. It is usually an important design
   // decision that variables are made const, and removing the const can have
   // unforseen side effects.



   // The fourth cast is rarely used. It is a brute-force cast that will attempt
   // to turn anything into almost anything else. It is typically used to 
   // reinterpret one pointer as if it was a pointer of another type. Huh?
   int i = 0xAAAAAAAA; // 4-byte hex number
   pI = &i; // pI points to a 4-byte integer (on this compiler).
   
   char *bytes = reinterpret_cast<char*>(pI);
   // I can now use "bytes" to index each individual byte of the 4-byte integer.
   // This is actually quite useful.

   // You may never use reinterpret_cast in your life; it is usually only for
   // very low-level systems programming. 
   

}
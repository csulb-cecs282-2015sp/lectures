// Welcome to C++

// C++ does not have packages to import like in Java; it has libraries to
// include with the following syntax.
#include <iostream> // include the input-output stream library
/* The entry point in C/C++ is a method called main. The return type is flexible
   but is generally int. In a simple program, you can use a simple main like:
   int main() { 
   ... code
   }
*/

// The most flexible main method is this:
int main(int argc, char* argv[]) { // alternate parameter: char** argv
   // This main is equivalent to Java's "static int main(String[] args)"
   
   // To print to the console, use the command std::cout
   std::cout << "Hello, world!" << std::endl << "This is CECS " << 282 <<  
    std::endl;

   std::cout << "I can also use \\n to force\na new line\n";

   /* The :: symbol is the scope-resolution operator; it is used to access 
      static class members, or variables/methods/declarations from a
      "namespace", the equivalent of Java's packages. 
   
      cout is a variable (NOT A METHOD) in the "std" package, which is why we
      have scope it to use cout, as in
      std::cout << ...

      This can be tedious, so you can "use" a namespace to bring all its
      definitions into the main program scope. 
   */

   using namespace std; // normally this goes right after all the #includes
   // now anything in the std namespace is available to use without scope
   cout << "I've got stds!" << endl;

   return 0; // 0 indicates success, anything else indicates an error to the OS
}


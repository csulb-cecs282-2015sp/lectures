#include <iostream>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
   const int LARGEST_POSSIBLE = 100;

   // Some of this will look funny for now; we will explain later.

   // A random_device helps to "seed" a number generator.
   random_device rd;
   // a compiler-chosen "good" random number generator.
   default_random_engine engine(rd());

   // Takes the output of the engine and maps it to a uniform distribution 
   // between two parameters.
   uniform_int_distribution<int> distr(1, LARGEST_POSSIBLE);
   
   // Now "call" the distribution to get a number.
   int chosen = distr(engine);
   cout << "I choose the number " << chosen << "!" << endl;

   // Every time I call the distribution I get a new number.
   cout << "Next number: " << distr(engine) << endl;
   cout << "Next number: " << distr(engine) << endl;
}
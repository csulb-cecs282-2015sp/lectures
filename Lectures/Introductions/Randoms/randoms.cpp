#include <iostream>
#include <cstdlib> // for RAND_MAX
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
   const int LARGEST_POSSIBLE = 100;

   srand(time(0)); // seed the random number generator based on current time
   //srand(10);
   rand();
   // the rand() function generates a random integer from 0 to RAND_MAX
   int chosen = rand() % 101               ; // how to cut interval to [0, 100]?
   cout << "I choose the number " << chosen << "!" << endl;
   cout << "RAND_MAX is " << RAND_MAX << endl;
}
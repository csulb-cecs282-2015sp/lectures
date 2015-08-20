#include "LinkedQueue.h"
#include <iostream>
using namespace std;

// for later
void PassByValue(LinkedQueue param);
void PassByReference(LinkedQueue &param);
LinkedQueue ReturnByValue();
LinkedQueue& ReturnByReference();
LinkedQueue* ReturnStackPointer();
LinkedQueue* ReturnHeapPointer();

int main(int argc, char* argv[]) {
   // Testing the exceptions:
   LinkedQueue empty;
   
   try {
      empty.Remove();
      cout << "This shouldn't print" << endl;
   }
   catch (std::out_of_range &ex) {
      cout << "Caught the exception, with message " << ex.what() << endl;
   }


   // Compare pass by value to pass by reference
   cout << endl << endl;
   LinkedQueue primes;
   primes.Add(2);
   primes.Add(3);
   primes.Add(5);
   primes.Add(7);
   primes.Add(11);
   PassByValue(primes);

   cout << endl << "Now pass by reference" << endl;
   PassByReference(primes);


   cout << endl << endl << "THERE IS ONE FINAL BUG IN THE QUEUE" << endl;
   empty = primes; // what is this calling? did we define it?
   empty.Remove();
   primes.Remove();


   cout << "-----------" << endl << endl;

   // practice return by value/reference/pointer
   cout << "Returning by value " << endl;
   LinkedQueue byValue = ReturnByValue();
   cout << "Removing: " << byValue.Remove() << endl << endl;

   // THIS IS DANGEROUS
   cout << "Returning by reference " << endl;
   LinkedQueue &byReference = ReturnByReference();
   //cout << "Removing: " << byReference.Remove() << endl << endl;
   
   // THIS IS DANGEROUS TOO
   cout << "Returning stack pointer" << endl;
   LinkedQueue *byPointer = ReturnStackPointer();
   //cout << "Removing: " << byPointer->Remove() << endl << endl;

   // THIS IS OK
   cout << "Returning heap pointer" << endl;
   LinkedQueue *byHeapPointer = ReturnHeapPointer();
   cout << "Removing: " << byHeapPointer->Remove() << endl << endl;



   cout << endl << endl << "Program stopping, stack popping" << endl;
   return 0;
}

void PassByValue(LinkedQueue param) {
   cout << param.Size() << endl;
}

void PassByReference(LinkedQueue &param) {
   cout << param.Size() << endl;
}

LinkedQueue ReturnByValue() {
   LinkedQueue temp;
   temp.Add(2);
   temp.Add(4);
   temp.Add(6);
   return temp;
}

LinkedQueue& ReturnByReference() {
   LinkedQueue temp;
   temp.Add(2);
   temp.Add(4);
   temp.Add(6);
   return temp;
}

LinkedQueue* ReturnStackPointer() {
   LinkedQueue temp;
   temp.Add(2);
   temp.Add(4);
   temp.Add(6);
   return &temp;
}

LinkedQueue *ReturnHeapPointer() {
   LinkedQueue *temp = new LinkedQueue();
   temp->Add(2);
   temp->Add(4);
   temp->Add(6);
   return temp;
}
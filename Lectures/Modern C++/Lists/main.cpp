#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
   // Demo the use of our LinkedList class.
   LinkedList<int> l; // TData is int....
   l.AddFirst(1);     // ... so all the Add methods take ints.
   l.AddFirst(2);
   l.AddFirst(3);
   l.AddLast(4);
   l.AddLast(5);


   // Use the .Get method to access individual elements.
   // How efficient is this loop?
   for (int i = 0; i < l.Size(); i++) {
      cout << l.Get(i) << endl;
   }


   cout << "Remove: " << endl;
   // The .RemoveFirst/Last/At methods return the data removed.
   while (l.Size() > 0) {
      cout << l.RemoveFirst() << endl;
   }

   cout << endl;

   // It is easy to get the "border" cases wrong in a linked structure. Let's
   // test to see what happens when adding to a list that had just been emptied.
   l.AddFirst(1);
   l.AddFirst(2);
   l.AddFirst(3);
   l.AddLast(4);
   l.AddLast(5);

   cout << "After adding back to the emptied list:" << endl;
   for (int i = 0; i < l.Size(); i++) {
      cout << l.Get(i) << endl;
   }
   // Does that look correct?
   cout << endl;

   cout << "Contains 14? " << endl;
   // Demo the Contains method. Will this be true or false?
   cout << l.Contains(14) << endl;
   cout << endl;

   // So far we have used the LinkedList directly, so the List base class 
   // doesn't seem necessary. Through polymorphism, we can declare a List
   // pointer to a LinkedList object.
   List<int> *p = new LinkedList<int>();
   // We can now only call List<int> methods on p... which, fortunately, is all
   // of our important functions.
   p->AddLast(4);
   p->AddLast(8);
   p->AddLast(15);
   p->AddLast(16);
   p->AddLast(23);
   p->AddLast(42);
   cout << "Pointer to a List contains 16? " << p->Contains(16) << endl;


   // So far we don't have much of a reason to do this type of polymorphism.
   // But we will...
 


   // Lecture part 2: iterators!
   // Picture the normal iterator loop:
   // for (_____::iterator itr = _____.begin(); itr != _____.end(); itr++) {
   //    do something with *itr or itr->

   /*
   If we want our LinkedList to follow this trend, what do we need to 
   implement?

   1. An inner class named iterator, so our full scoped name will be 
      LinkedList<TData>::iterator
   2. Operators ++, ==, !=, *, and -> in the iterator class.
   3. Member methods .begin() and .end() in LinkedList.
   
   When those are implemented, we can then...
   */
   cout << endl << "ITERATORS!!!" << endl;
   for (LinkedList<int>::iterator itr = l.begin(); itr != l.end(); itr++) {
      cout << *itr << endl;
   }
}
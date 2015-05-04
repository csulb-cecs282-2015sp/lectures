#ifndef __LIST_H
#define __LIST_H

/*
A List is an "abstract data type"; it is an IDEA of a structure that would be
useful, if only we could implement it. (Rest assured, we CAN implement it!)
We will define this "ADT" in terms of what operations it supports and what
properties it follows. We will then look at an actual implementation.

We want our lists to hold any type of data, so we use a template.
*/

#include <vector>
template<typename TData>
class List {

public:
   /*
   All of the operations that Lists can perform. We declare them as pure virtual
   functions, saying that a generic List does not implement the functions, but a
   derived classs will.
   */
   // Adds data to the end of the list.
   virtual void AddLast(TData data) = 0;
   // Adds data at the front of the list.
   virtual void AddFirst(TData data) = 0;

   // Removes and returns the first element of the list.
   virtual TData RemoveFirst() = 0;
   // Removes and returns the last element of the list.
   virtual TData RemoveLast() = 0;
   
   // Accesses data at the given index.
   virtual TData& Get(int index) const = 0;

   // Get the number of elements in the list.
   virtual int Size() const = 0;

   // Clear the list of all elements.
   virtual void Clear() = 0;

   // Checks if the list contains a particular data element.
   virtual bool Contains(const TData &data) = 0;

};

#endif
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <memory>
#include <stdexcept>
#include "List.h"

/*
Implements the List base class using a linked data structure with dynamically-
allocated Nodes.
*/
template<typename TData>
class LinkedList : public List<TData> {
public:
   class Node {
      TData mData; // Note the type is TData

      // While unique_ptr indicates a unique ownership situation, shared_ptr 
      // indicates a shared ownership. shared_ptr is a "reference counted"
      // pointer: the language keeps track of how many shared pointers currently
      // point to a heap object, and as soon as all shared_ptrs are lost to the
      // heap object, it is deleted.
      std::shared_ptr<Node> mNext;
      std::shared_ptr<Node> mPrev;

      friend class LinkedList<TData>;

   public:
      static void* operator new(std::size_t sz){
         onHeap++;
         std::cout << "operator new: " << onHeap << " Nodes on the heap" << std::endl;
         return ::operator new(sz);
      }

         static void operator delete(void* ptr, std::size_t sz) {
         onHeap--;
         std::cout << "operator delete: " << onHeap << " Nodes on the heap" << std::endl;
         ::operator delete(ptr);
      }

      static int onHeap;
      // Initialize a Node with the given data, and a pointer for the next Node.
      Node(TData data) : mData(data) {
      }
   };

   // A shared_ptr to the head of the list. The mPrev link of the head will link
   // to the tail in a circular fashion
   std::shared_ptr<Node> mHead;
   int mSize;

public:
   LinkedList() : mHead(nullptr), mSize(0) {}

   // We now implement all of List's pure virtual functions, using the behavior
   // of a doubly linked list.

   virtual int Size() const {
      return mSize;
   }

   virtual void AddFirst(TData data) {
      // Adding first has two cases: if the list is empty, and if it is not.

      AddLast(data);
      mHead = mHead->mPrev;
   }

   virtual void AddLast(TData data) {
      // AddLast is similar to AddFirst.

      if (mSize == 0) {
         // If the list is empty, this will be the head of the list.
         mHead = std::shared_ptr<Node>(new Node(data));
         // Make mHead's prev link back to the tail... namely, itself.
         mHead->mPrev = mHead->mNext = mHead;
      }
      else {
         // The new node needs a Next that points to the current head; a Prev
         // that points to the current head's prev.
         std::shared_ptr<Node> newNode(new Node(data));
         newNode->mNext = mHead;
         newNode->mPrev = mHead->mPrev;
         mHead->mPrev->mNext = newNode;
         mHead->mPrev = newNode;
      }
      mSize++;
   }

   // Remove the first data element, unlinking and deleting its node.
   virtual TData RemoveFirst() { 
      if (mSize == 0)
         throw std::out_of_range("Cannot remove from an empty LinkedList");
      TData temp = mHead->mData;

      // Unlink the current head. Two cases: if there is only 1 element, or not.
      if (mSize == 1) {
         // Set mHead to nullptr.
         mHead->mNext = nullptr;
         mHead->mPrev = nullptr;
         mHead = nullptr;
         // Now there are no shared_ptrs to the old Node on the heap, so it will
         // be deleted automatically.
      }
      else {
         // New mHead needs to be mHead's next.
         mHead = mHead->mNext;
         mHead->mPrev = mHead->mPrev->mPrev;
         mHead->mPrev->mNext = mHead;

         // Now no one points to the old head, so it will be deleted.
      }
      mSize--;

      return temp;
   }

   virtual TData RemoveLast() {
      if (mSize == 0)
         throw std::out_of_range("Cannot remove from an empty LinkedList");

      TData temp = mHead->mPrev->mData;

      // Similar logic to RemoveFirst, except the head does not change.
      if (mSize == 1) {
         // Set mHead to nullptr.
         mHead->mNext = nullptr;
         mHead->mPrev = nullptr;
         mHead = nullptr;
         // Now there are no shared_ptrs to the old Node on the heap, so it will
         // be deleted automatically.
      }
      else {
         // New mHead needs to be mHead's next.
         mHead->mPrev = mHead->mPrev->mPrev;
         mHead->mPrev->mNext = mHead;

         // Now no one points to the old tail, so it will be deleted.
      }
      mSize--;
      return temp;
   }

   virtual void Clear() {
      // This is a hack. To do this nicely we would need to learn about
      // std::weak_ptr, but that is complicated. For now, we will just keep
      // calling RemoveLast.
      while (mSize > 0) {
         RemoveLast();
      }
   }

   virtual TData& Get(int index) const {
      // Start a Node pointer at the head. Walk the pointer down the list
      // until we have walked "index" steps.

      if (index < 0 || index >= mSize)
         throw std::out_of_range("Index out of range");

      // We don't need shared_ptr here; we are not involved in the lifetime
      // of the nodes, we just need read access.
      Node *n = mHead.get(); // .get() returns the raw pointer
      for (int i = 0; i < index; i++)
         n = n->mNext.get();

      return n->mData;
   }

   virtual bool Contains(const TData &data) {
      Node *n = mHead.get();
      for (int i = 0; i < mSize; i++) {
         if (n->mData == data)
            return true;
         n = n->mNext.get();
      }
      return false;
   }


   /*
   Lecture part two. Iterators!
   */
   class LinkedListIterator { // lowercase by expectation.
      Node *mCurrent;
      LinkedList<TData> *mList;
      friend class LinkedList < TData >;

   public:
      LinkedListIterator(LinkedList<TData> *list, Node *start) : mList(list), mCurrent(start) {}
      LinkedListIterator(const LinkedListIterator &rhs) : mList(rhs.mList), mCurrent(rhs.mCurrent) {}

      TData &operator*() {
         return mCurrent->mData;
      }

      TData &operator->() {
         return mCurrent->mData;
      }

      LinkedListIterator operator++(int) {// postincrement
         iterator temp = *this;

         if (mCurrent == nullptr)
            throw std::out_of_range("Cannot advance null iterator");
         
         if (mCurrent == mList->mHead->mPrev.get())
            mCurrent = nullptr;
         else
            mCurrent = mCurrent->mNext.get();

         return temp;
      }

      LinkedListIterator &operator++() { // preincrement
         if (mCurrent == nullptr)
            throw std::out_of_range("Cannot advance null iterator");
         
         if (mCurrent == mList->mHead->mPrev.get())
            mCurrent = nullptr;
         else
            mCurrent = mCurrent->mNext;
         return *this;
      }

      friend bool operator==(const LinkedListIterator &lhs, 
       const LinkedListIterator &rhs) {
         return lhs.mCurrent != rhs.mCurrent;
      }

      friend bool operator!=(const LinkedListIterator &lhs, 
       const LinkedListIterator &rhs) {
         return lhs.mCurrent != rhs.mCurrent;
      }

   };

   typedef LinkedListIterator iterator;

   // With the iterator class done, we now just need .begin() and .end().
   iterator begin() {
      // return an iterator starting at head.
      return LinkedListIterator(this, mHead.get());
   }

   iterator end() {
      // return an iterator that is nullptr
      return LinkedListIterator(this, nullptr);
   }
};

template<typename T>
int LinkedList<T>::Node::onHeap = 0;
#endif
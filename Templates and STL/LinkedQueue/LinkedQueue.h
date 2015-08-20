#ifndef __LINKEDQUEUE_H
#define __LINKEDQUEUE_H

// A templated version of the LinkedQueue class, where data members are of
// a templated type.

// In a templated class, all functions are defined in the class declaration.

template <typename TData> // this applies to the entire class.
class LinkedQueue {
private:
   class Node {
      TData mData; // Note the type is TData
      Node *mNext; 
      friend class LinkedQueue<TData>;

   public:
      // Initialize a Node with the given data, and a pointer for the next Node.
      Node(TData data, Node *next) : mData(data), mNext(next) {
      }
   };


   Node *mHead;
   Node *mTail;
   int mSize;

public:
   // Everything that follows is the same as before, except now all parameters
   // and return types that deal with data items are now of type TData.
   LinkedQueue() : mHead(nullptr), mTail(nullptr), mSize(0) {
   }

   LinkedQueue(const LinkedQueue &other)
      : mHead(other.mHead), mTail(other.mTail), mSize(other.mSize) {

      mHead = nullptr;
      Node *o = other.mHead;
      Node *mine = nullptr;

      for (int i = 0; i < other.mSize; i++) {
         Node *n = new Node(o->mData, nullptr);

         if (i == 0) {
            mHead = n;
         }
         else {
            mine->mNext = n;
         }
         o = o->mNext;
         mine = n;
      }
      mTail = mine;
   }
   
   ~LinkedQueue() {
      Node *n = mHead;

      while (n != nullptr) {
         Node *temp = n;
         n = n->mNext;
         delete temp;
      }
   }

   LinkedQueue& operator=(const LinkedQueue &rhs) {
      if (this == &rhs) {
         // this happens when you do something like "x=x";
         // in this case, we don't want to do anything.
         return *this;
      }

      // Cute trick ahead.
      LinkedQueue temp(rhs); // use copy constuctor to deep-copy rhs

      // now "take over" the temp's list, and give it ours to destruct.
      std::swap(mHead, temp.mHead);
      std::swap(mTail, temp.mTail);
      return *this; // temp goes out of scope, destructing our old list.
   }

   // Add an element to the end of the queue. Note the parameter type.
   void Add(TData data) {
      if (mSize == 0) {
         Node *newNode = new Node(data, nullptr);
         mHead = mTail = newNode;
      }
      else {
         Node *newNode = new Node(data, nullptr);
         mTail->mNext = newNode;
         mTail = newNode;
      }
      mSize++;

   }
   // Note the return type.
   TData Remove() {
      if (mSize == 0) {
         throw std::out_of_range("Queue was empty");
      }
      TData data = mHead->mData;
      Node *temp = mHead;
      mHead = mHead->mNext;
      delete temp;

      if (mSize == 1) {
         mTail = nullptr;
      }
      mSize--;
      return data;
   }
   
   // Give the size of the queue. What does inline mean?
   inline int Size() const {
      return mSize;
   }
};

#endif
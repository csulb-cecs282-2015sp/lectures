#include "LinkedQueue.h"

// Default construct a LinkedQueue with no elements.
LinkedQueue::LinkedQueue()
 : mHead(nullptr), mTail(nullptr), mSize(0) { // "nullptr" instead of "null"

   // Before continuing, draw a picture of a LinkedQueue variable on the stack.

}


LinkedQueue::LinkedQueue(const LinkedQueue &other)
   : mHead(other.mHead), mTail(other.mTail), mSize(other.mSize) {
   // This initializer list is the "shallow copy" behavior of the 
   // copy constructor. Is it correct? We'll answer this later.








}

void LinkedQueue::Add(int data) {
   // Add the new data to the tail of the queue. 
   // Create a Node to hold the data, then link the current "tail" of the queue
   // to the new Node.
   

   // First case: the queue is empty, so there is no tail.
   if (mSize == 0) {
      // DRAW THIS OUT.
      Node *newNode = new Node(data, nullptr);
      mHead = mTail = newNode;



   }
   else {
      Node *newNode = new Node(data, nullptr);
      mTail->mNext = newNode;
      mTail = newNode;
      // There is a bug in this code. Can you find it?
   }
   mSize++;
}

int LinkedQueue::Remove() {
   if (mSize == 0) {
      // what do we do?
    

   }

   // mHead points to the next item we want to remove. 
   // Make a copy of the data at the head, then redirect the head.
   
   int data = mHead->mData;
   mHead = mHead->mNext;

   // What happens to the old head Node? There is a bug in this code...



   mSize--;
   return data;
}


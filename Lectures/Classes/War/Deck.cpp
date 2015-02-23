#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>


using std::default_random_engine;
using std::uniform_int_distribution;
using std::random_device;

// Deck's constructor must initialize the card count to 52, and then initialize
// each Card in the deck's array.
Deck::Deck() : mCardCount(DECK_SIZE), mCards() {
   // mCards() in an initializer list uses the default constructor to initialize
   // each element of the array.


   // But the default constructor gives 0 for both the Kind and Suit of a Card,
   // giving us a deck of 52 "0 of spades" cards. We must manually iterate back
   // through the array and assign kinds and suits.
   int index = 0;
   for (int s = 0; s < 4; s++) { // 0 is spades, 1 is clubs, 2 diamond, 3 hearts
      for (int k = 2; k <= 14; k++) {
         mCards[index].SetKind(k);
         mCards[index].SetSuit(s);
         index++;
      }
   }
}

int Deck::GetCount() const {
   return mCardCount;
}

// Returns a copy of the 'last' Card in the deck, and decreases the count of
// how many cards are left.
Card Deck::DealOne() {
   return mCards[--mCardCount]; // What is --mCardCount?
}

// Shuffle the deck's array of cards using Knuth's shuffling algorithm.
void Deck::Shuffle() {
   // Knuth's algorithm for shuffling an array: 
   // for i = length - 1 down to 1:
   //    let j = random number from 0 to i inclusive
   //    swap array[j] with array[i]
   random_device rd;
   default_random_engine engine(rd());


   for (int i = mCardCount - 1; i >= 1; i--) {
      uniform_int_distribution<int> range(0, i);
      // What happens to "range" each time through this loop?

      
      
      int j = range(engine);
      std::swap(mCards[j], mCards[i]);
   }
}

// Print all the cards remaining in the deck's array.
void Deck::PrintDeck() const {
   for (int i = 0; i < mCardCount; i++) {
      std::cout << mCards[i].ToString() << "; ";
   }
   std::cout << std::endl;
}

#ifndef __DECK_H
#define __DECK_H

#include "Card.h" // need this to use the Card type

/*
Now that we have a Card class, we can model a Deck of 52 cards for playing
a game of War. A Deck object will shuffle an array of cards, and then deal them
one at a time.
*/
class Deck {
private:
   static const int DECK_SIZE = 52; // Static?





   // This array will hold all 52 cards. We will not actually "remove" cards from 
   // the deck when dealing... as you will see.
   Card mCards[DECK_SIZE];

   // We will keep track of how many cards are "left" in the deck.
   int mCardCount;

public:
   // Construct a deck with 52 cards in a pre-sorted order.
   Deck();

   // Return the njmber of cards still left in the deck. Why const again?
   int GetCount() const; 

   // Shuffle the deck.
   void Shuffle();

   // "Removes" one card from the deck and returns a copy of it.
   Card DealOne();

   // Prints all the cards in the deck.
   void PrintDeck() const; 
};

#endif
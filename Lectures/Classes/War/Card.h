#ifndef __CARD_H  // huh???
#define __CARD_H

#include <string>

/*
This class represents a single playing card in a standard 52-card deck.
This file contains the declaration of the Card class only. Like a function
prototype, it will inform the compiler about WHAT a "Card" object is, but not
necessarily HOW it works. The implementation of the class will come in another
file.
*/
class Card {
private:
   // The private member variables of the class will represent its state.

   char mKind; // numerical value of card; 11 = J, 12 = Q, 13 = K, 14 = Ace
   char mSuit; // 0 = Spade, 1 = Club, 2 = Diamond, 3 = Heart

public:
   // A "default constructor": one that takes no arguments. Will be needed later
   Card();

   // A constructor taking enough information to set up a Card object.
   Card(char kind, char suit);
   
   // Unlike Java, not all C++ objects have a "convert to string" function.
   // But we can add one manually.
   std::string ToString() const; // What is with the "const"?


   // We can't use < or > to compare Card objects yet, but we do need a way of
   // deciding which of two cards is "greater". This method will do that.
   // Given another card, compare "this" card to "other" and return a value 
   // indicating which is greater and should win the hand.
   
   // What's with the "const Card &" parameter?
   int CompareTo(const Card &other) const;

   // Mutators for Kind and Suit.
   void SetKind(char kind);
   void SetSuit(char suit);
}; // NOTE THE SEMICOLON

#endif
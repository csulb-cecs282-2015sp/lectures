#include "Card.h"
#include <string>
using std::string;

/*
In this file we will provide the IMPLEMENTATION/definition of the functions
declared as part of the Card class.
*/

// To define a member function of a class, we have to SCOPE IT using the ::
// "scope resolution" operator.

// Card::Card says that I am defining the Card constructor of the Card class.
Card::Card(char kind, char suit) :
   mKind(kind), mSuit(suit) {

   // In java, you would do this:
   // mKind = kind;
   // mSuit = suit;
}

Card::Card() : mKind(0), mSuit(0) { 
   // A default constructor gives default values to member variables.
   // We must have a default constructor if we want to make arrays of our class.
   // Why would that be?
}

// "int Card::CompareTo" says that this method returns int, belongs to Card, and
// is named CompareTo.
int Card::CompareTo(const Card &other) const {
   // To compare, we will subtract "other" card's Kind from "this" card's Kind.
   // other.mKind is private, so why am I allowed to do this?:
   return mKind - other.mKind; 
}

// Return a string representation of this Card that can be outputted if needed.
// What does "string Card::ToString()" say to the compiler?
string Card::ToString() const {
   string strValue; // a string's default constructor makes it empty.
   if (mKind <= 10)
      strValue += std::to_string(mKind);
   else {
      strValue += (
       mKind == 11 ? "Jack" :
       mKind == 12 ? "Queen" :
       mKind == 13 ? "King" :
       "Ace"
      );
   }
   strValue += " of ";

   string suits[] = { "Spades", "Clubs", "Diamonds", "Hearts" };
   strValue += suits[mSuit];
   return strValue;
}

void Card::SetKind(char kind) {
   // validate the kind
   if (kind >= 2 && kind <= 14)
      mKind = kind;
}

void Card::SetSuit(char suit) {
   // validate the suit
   if (suit >= 0 && suit <= 3)
    mSuit = suit;
}
#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"

using namespace std;

// Play a game of War. Using the Deck and Card classes, set up two decks of 
// cards and shuffle them. Then repeatedly deal 1 card to each player and 
// compare the cards. Whichever card is greater wins that round.
int main(int argc, char* argv[]) {

   // Build a deck for player 1.
   Deck d1;
   d1.PrintDeck(); // Prints in standard unshuffled deck order... why?
   cout << endl << endl;

   // Shuffle and demonstrate that the shuffle worked.
   d1.Shuffle();
   d1.PrintDeck();

   // Shuffle a deck for player 2.
   Deck d2;
   d2.Shuffle();
   

   cout << endl << endl << "Let's play WAR!" << endl;
   while (d1.GetCount() > 0) {
      // Let's draw this out on the stack.
      Card c1 = d1.DealOne(), c2 = d2.DealOne();

      // Remember: compare will be negative if c1 < c2; positive if c1 > c2;
      // or 0 if they are equal.
      int compare = c1.CompareTo(c2);

      cout << c1.ToString() << " vs. " << c2.ToString() << " ... " <<
         (compare < 0 ? "Player 2 wins!" : compare > 0 ? "Player 1 wins!" : "Tie!") << endl;

      char cont;
      cout << "Continue? y/n: ";
      cin >> cont;
      if (cont != 'y')
         break;
      cout << endl;
   }
}

#include <iostream>
#include <string>

#include "Pokemon.h"

using namespace std;

int main() {
   // Construct a Pikachu knowing Tackle.
   Move tackle("Tackle", 45);
   Pokemon p1("Pikachu", 100, 50, 35, tackle);

   // Construct a Ponyta knowing Ember.
   // The 'Move("Ember", 40)' allows me to make a move while constructing p2
   Pokemon p2("Ponyta", 120, 40, 60, Move("Ember", 40));
   
   // Default construct p3, which will take the name "Missingno."
   Pokemon p3;

   // Copy construct p4, as a copy of Ponyta.
   Pokemon p4(p2);
   
   // Add p1 and p2 to get an offspring
   Pokemon child = p1 + p2;
   

   // Make them fight!
   // To make Pikachu fight its child Pikyta, uncomment the next line
   // p2 = child;
   cout << endl << endl << p1 << endl << " VERSUS " << endl << p2 
      << endl << endl;
   
   int round = 1;
   while (p1.GetHP() > 0 && p2.GetHP() > 0) {
      cout << "Round " << round << "... fight!" << endl;
      p1.Attack(p2);
      cout << p2.GetName() + " has " << p2.GetHP() << " HP left" << endl;

      p2.Attack(p1);
      cout << p1.GetName() + " has " << p1.GetHP() << " HP left" << endl;

      round++;
      cout << endl << endl;
   }
   // Determine the winner
   cout << (p1.GetHP() > 0 ? p1.GetName() + " wins!" :
      p2.GetHP() > 0 ? p2.GetName() + " wins!" :
      "They both fainted!") << endl;
}
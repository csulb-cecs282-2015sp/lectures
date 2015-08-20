#ifndef __POKEMON_H
#define __POKEMON_H
#include <iostream>
#include <string>
/*
Design a class to represent a single Pokemon. 
We will keep things simple. The Pokemon class will define these state variables:
   - string Name
   - int HP, Attack, Defense
   - a single Move that it can attack with
and these operations:
   - constructor taking Name, HP, Attack, Defense, and Move
   - copy constructor
   - accessor for HP only

   - operator<< for printing the Pokemon in this format:
      *NAME* with *MOVE*: ** HP, ** Attack, ** Defense

   - operator+ to "add" two Pokemon together, creating a new "offspring" whose
      name is the first half of lhs and the second half of rhs.

   - operator=, for doing copy assignment
   
   - void Attack, telling the Pokemon to use its Move on a target.
      Formula: reduce opponent Pokemon's HP by
      (my Attack * my Move Strength) / (opponent Defense)
      HP cannot go below 0.
*/

class Move {
   std::string mName;
   int mPower;

   friend class Pokemon;

public:
   Move(const std::string &name, int power)
      : mName(name), mPower(power) {
      std::cout << "Construct Move " << mName << std::endl;
   }

   // This gives the Pokemon's operator<< access to a Move's name.
   friend std::ostream& operator<<(std::ostream &lhs, const Pokemon &rhs);
};


class Pokemon {
   // Fun fact: all class members are private by default.
   std::string mName;
   int mHP;
   int mAttack;
   int mDefense;
   Move mMove;

public:
   // Constructor
   Pokemon(const std::string &name, int hp, int attack, int defense,
      Move move);

   // Default constructor
   Pokemon();
   
   // Copy constructor
   Pokemon(const Pokemon &other);

   // Accessors
   int GetHP() const;
   int GetAttack() const;
   int GetDefense() const;
   const Move &GetMove() const;
   const std::string &GetName() const {
      return mName;
   }

   // Mutators
   void SetHP(int newHP);
   void SetAttack(int newAttack);
   void SetDefense(int newDefense);
   void SetMove(const Move &newMove);

   // Attack
   void Attack(Pokemon &other);

   // operators
   friend std::ostream& operator<<(std::ostream &lhs, const Pokemon &rhs);
   friend Pokemon operator+(const Pokemon &lhs, const Pokemon &rhs);
};


#endif
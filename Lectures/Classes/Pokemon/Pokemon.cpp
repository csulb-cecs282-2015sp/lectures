#include <string>
#include "Pokemon.h"

using namespace std;

Pokemon::Pokemon(const string &name, int hp, int attack, int defense,
   Move move) 
 : mName(name), mHP(hp), mAttack(attack), mDefense(defense),
   mMove(move)
{
   cout << "Construct Pokemon " << mName << ", " << mHP;
   // I want to print the Move that my Pokemon knows, too
   cout << " knowing the move " << mMove.mName << endl;
   cout << endl;
}

Pokemon::Pokemon()
   : mName("Missingno."), mHP(1000), mAttack(0), mDefense(1), 
      mMove("Splash", 0)
{
   cout << "Default Construct Pokemon " << mName << ", " << mHP;
   cout << " and I know the move " << mMove.mName;
   cout << endl;
}

Pokemon::Pokemon(const Pokemon &other)
   : mName(other.mName), mHP(other.mHP), mAttack(other.mAttack),
   mDefense(other.mDefense), mMove(other.mMove)
{
   cout << "Copy Construct Pokemon " << mName << ", " << mHP;
   cout << " and I know the move " << mMove.mName;
   cout << endl;
}

int Pokemon::GetHP() const {
   return mHP;
}

int Pokemon::GetAttack() const {
   return mAttack;
}

int Pokemon::GetDefense() const {
   return mDefense;
}

const Move& Pokemon::GetMove() const {
   return mMove;
}

void Pokemon::SetHP(int newHP) {
   // if the HP is negative, make mHP 0.
   if (newHP < 0)
      mHP = 0;
   else
      mHP = newHP;
}

void Pokemon::SetAttack(int newAttack) {
   mAttack = newAttack;
}

void Pokemon::SetDefense(int newDefense) {
   mDefense = newDefense;
}

void Pokemon::SetMove(const Move &newMove) {
   mMove = newMove;
}

std::ostream& operator<<(std::ostream &lhs, const Pokemon &rhs) {
   lhs << rhs.mName << "; HP " << rhs.mHP << "; Att " << rhs.mAttack <<
      "; Def " << rhs.mDefense << "; Move " << rhs.mMove.mName;
   return lhs;
}


Pokemon operator+(const Pokemon &lhs, const Pokemon &rhs) {
   string leftName = lhs.mName.substr(0, lhs.mName.length() / 2);
   string rightName = rhs.mName.substr(rhs.mName.length() / 2);
   string newName = leftName + rightName;

   Pokemon child(newName, lhs.mHP, lhs.mAttack, rhs.mDefense, rhs.mMove);
   return child;
}

// Reduce the target Pokemon's HP using the following formula:
// damage = Attack * MovePower / TargetDefense.
void Pokemon::Attack(Pokemon &other) {
   int damage = mAttack * mMove.mPower / other.mDefense;
   other.SetHP(other.mHP - damage);
}

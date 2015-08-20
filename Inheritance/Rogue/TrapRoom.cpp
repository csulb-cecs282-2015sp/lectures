#include "TrapRoom.h"
#include "DungeonRoom.h"
#include <iostream>
#include <string>
#include <random>

using namespace std;


TrapRoom::TrapRoom() {
   uniform_int_distribution<int> traps(0, NUMBER_OF_TRAP_TYPES - 1);
   mTrapType = traps(DungeonRoom::mRandom);
}

string TrapRoom::GetRoomName() const {
   string name = "a room with ";
   switch (mTrapType) {
   case 0:
      name += "Miley Cyrus on a wrecking ball.";
      break;
   case 1:
      name += "Justin Bieber doing country covers.";
      break;
   case 2:
      name += "a golden chest of gold.";
      break;
   }
   return name;
}

string TrapRoom::GetDescription() const {
   switch (mTrapType) {
   case 0:
      return "She wrecks you.";
   case 1:
      return "He makes you a Belieber.";
   case 2:
      return "It looks awfully enticing...";
   default:
      return "A BUG IN THE PROGRAM attacks and you die.";
   }
}

void TrapRoom::GetActions(std::vector<std::string> *list) {
   

   switch (mTrapType) {
   case 0:
      list->push_back("Sing along.");
      list->push_back("Ride the wrecking ball into the next room.");
      break;

   case 1:
      list->push_back("Kill yourself.");
      list->push_back("Send him to Canada.");
      list->push_back("Kill yourself twice.");
      break;

   case 2:
      list->push_back("Open it.");
      list->push_back("Call Pawn Stars.");
      break;

   }

}

bool TrapRoom::DoAction(int number) {
   switch (mTrapType) {

   case 0:
      switch (number) {
      case 1:
         cout << "Let's print the lyrics to a song. You die." << endl;
         return false;

      case 2:
         return true;

      }

   case 1:
      switch (number) {
      case 1:
      case 3:
         cout << "GG." << endl;
         return false;

      case 2:
         cout << "They send him back." << endl;
         return false;
      }

   case 2:
      switch (number) {
      case 1:
         cout << "It explodes. You die." << endl;
         return false;

      case 2:
         cout << "Pawn Stars steals the chest and then kills you. You die." << endl;
         return false;
      }

   }
   return false;
}
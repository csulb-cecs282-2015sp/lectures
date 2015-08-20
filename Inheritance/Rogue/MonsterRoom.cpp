#include <iostream>
#include "MonsterRoom.h"
#include "TrapRoom.h"
#include "DungeonRoom.h"
#include <string>
#include <random>
using namespace std;


MonsterRoom::MonsterRoom() {
   uniform_int_distribution<int> monsters(0, NUMBER_OF_MONSTER_TYPES - 1);
   mMonsterType = monsters(DungeonRoom::mRandom);
}

string MonsterRoom::GetRoomName() const {
   string name = "a room with ";
   switch (mMonsterType) {
   case 0:
      name += "a GIANT SPIDER!!!";
      break;
   case 1:
      name += "a SPOOKY GHOST!!!";
      break;

   case 2:
      name += "a 5,000 ton dragon.";
      break;
   }
   return name;
}

string MonsterRoom::GetDescription() const {
   switch (mMonsterType) {
   case 0:
      return "The spider appears to be wounded.";
   case 1:
      return "Your movement catches the ghost's attention.";
   case 2:
      return "The dragon roasts you alive and then eats your corpse. You die.";
   default:
      return "A BUG IN THE PROGRAM attacks and you die.";
   }
}




void MonsterRoom::GetActions(std::vector<std::string> *list) {
   list->push_back("Run away!!!!");
   list->push_back("Curl up in a ball and hope it ignores you.");
   switch (mMonsterType) {
   case 0:
      list->push_back("Spray it with RAAAAAAID.");
      break;

   case 1:
      list->push_back("Call the Ghostbusters.");
      break;

   case 2:
      list->push_back("Seduce the dragon.");
      list->push_back("Accept your mortal fate.");
      break;
   }
}



bool MonsterRoom::DoAction(int number) {
   switch (mMonsterType) {
   case 0:
      switch (number) {
      case 1:
         cout << "You escaped to the next room!" << endl;
         return true;
      case 2:
         cout << "The spider sees you with its 10,000 eyes and spins you into a ball of silk." << endl;
         return false;

      case 3:
         cout << "The wind in the dungeon catches the Raid and sprays you in the eyes. You are blind. You blindly stumble to the next room." << endl;
         return true;
      }

   case 1:
      switch (number) {
      case 1:
         cout << "You can't run from a ghost." << endl;
         return false;

      case 2:
      case 3:
         cout << "The Ghostbusters come to your aid and bust dat ghost." << endl;
         return true;
      }

   case 2:
      cout << "You ded." << endl;
      return false;
   }

   return false;
}





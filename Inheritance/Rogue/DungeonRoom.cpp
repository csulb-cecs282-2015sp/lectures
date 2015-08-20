#include "DungeonRoom.h"
#include "TrapRoom.h"
#include "MonsterRoom.h"
#include <string>
#include <random>

using namespace std;

default_random_engine DungeonRoom::mRandom{ random_device()() };

string DungeonRoom::GetDescription() const {
   return "The room is empty.";
}

string DungeonRoom::GetRoomName() const {
   return "an empty room";
}

DungeonRoom *DungeonRoom::GetNextRoom() const {
   uniform_int_distribution<int> roomType(0, NUMBER_OF_ROOM_TYPES - 1);

   switch (roomType(mRandom)) {
   case 0:
      return new DungeonRoom();
   case 1:
      return new MonsterRoom();
   case 2:
      return new TrapRoom();
   }
   return nullptr;
}

void DungeonRoom::GetActions(std::vector<std::string> *list) {
   list->push_back("Go to the next room.");
}

bool DungeonRoom::DoAction(int number) {
   return true;
}
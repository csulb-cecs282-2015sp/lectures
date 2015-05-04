#ifndef __MONSTERROOM_H
#define __MONSTERROOM_H

#include "DungeonRoom.h"

class MonsterRoom : public DungeonRoom {
private:
   int mMonsterType;
   static const int NUMBER_OF_MONSTER_TYPES = 3;
public:
   MonsterRoom();

   virtual std::string GetRoomName() const;
   virtual std::string GetDescription() const;
   virtual void GetActions(std::vector<std::string> *list);
   virtual bool DoAction(int number);
};

#endif
#ifndef __TRAPROOM_H
#define __TRAPROOM_H

#include "DungeonRoom.h"

class TrapRoom : public DungeonRoom {
private:
   int mTrapType;
   static const int NUMBER_OF_TRAP_TYPES = 3;
public:
   TrapRoom();

   virtual std::string GetRoomName() const;
   virtual std::string GetDescription() const;
   virtual void GetActions(std::vector<std::string> *list);
   virtual bool DoAction(int number);

};

#endif
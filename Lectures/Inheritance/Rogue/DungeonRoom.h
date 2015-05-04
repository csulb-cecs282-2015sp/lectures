#ifndef __DUNGEONROOM_H
#define __DUNGEONROOM_H

#include <string>
#include <vector>
#include <random>

class DungeonRoom {
protected:
   static std::default_random_engine mRandom;
   static const int NUMBER_OF_ROOM_TYPES = 3;

public:
   virtual std::string GetRoomName() const;
   virtual std::string GetDescription() const;

   virtual DungeonRoom *GetNextRoom() const;


   virtual void GetActions(std::vector<std::string> *list);
   virtual bool DoAction(int number);
};

#endif
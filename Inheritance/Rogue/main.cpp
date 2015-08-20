#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
   cout << "Welcome to our Rogue-like game. Let's begin!" << endl;

   DungeonRoom *currentRoom = new DungeonRoom();

   vector<string> actions;

   while (true) {
      cout << endl << endl << "You enter " << currentRoom->GetRoomName() << endl;
      cout << currentRoom->GetDescription() << endl;
      currentRoom->GetActions(&actions);

      cout << "What do you want to do?" << endl;
      int counter = 1;
      for (string &a : actions) {
         cout << counter << ") " << a << endl;
         counter++;
      }
      actions.clear();

      int choice;
      cin >> choice;
      if (!currentRoom->DoAction(choice))
         return 0;
      
      DungeonRoom *next = currentRoom->GetNextRoom();
      delete currentRoom;
      currentRoom = next;

   }
}
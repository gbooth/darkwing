#ifndef ROOM_H
#define ROOM_H

#include "Object.h"
#include <map>
#include <list>
#include "Direction.h"
#include "directionState.h"

class Room : public Object {
 public:
  Room(int);
  virtual ~Room() {};
  bool getHasEnemy();
  bool checkForNPC(int);
  bool checkForObj(int);
  std::pair<int, int> getDirection(Direction);
  void objChanged(int);
  std::string getMessage();
  std::list<int> objToSave();

 private:
  std::list<int> npcInRoom;
  std::list<int> objInRoom;
  std::map<Direction, std::pair<bool, std::pair<int, int>>> adjRooms;
  dirState checkDirection(Direction);
  bool hasEnemy;
  std::list<int> changedObj;
  std::string roomMessage;
  int roomID;
};

#endif // ROOM_H

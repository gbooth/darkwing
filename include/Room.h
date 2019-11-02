#ifndef ROOM_H
#define ROOM_H

#include "Object.h"
#include <map>
#include <list>

class Room : public Object {
 public:
  Room(int, int);
  virtual ~Room();
  bool getHasEnemy();
 private:
  std::list<Identifier> npcInRoom;
  std::list<Identifier> objectsInRooms;
  std::map<Direction, std::pair<bool, std::pair<int, int>>> adjoiningRooms;
  bool hasEnemy;
  std::list<Identifier> changedObjects;
};

#endif // ROOM_H

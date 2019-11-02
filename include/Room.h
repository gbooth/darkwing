#ifndef ROOM_H
#define ROOM_H

#include "Object.h"


class Room : public Object {
 public:
  Room(int, int);
  virtual ~Room();
  bool getHasEnemy();
  enum Direction {north, south, east, west};
 private:
  list<Identifiers> npcInRoom;
  list<Identifiers> objectsInRooms;
  map<Direction, pair<bool, pair<int, int>>> adjoiningRooms;
  bool hasEnemy;
  list<Identifiers> changedObjects;
};

#endif // ROOM_H

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

  bool checkForEnemy();
  bool checkForNPC(int);
  bool checkForObj(int);

  std::pair<int, int> getDirection(Direction);

  void objChanged(int);
  std::string getMessage();

  std::list<int> objToSave();

 private:
  std::map<int, Person> npcInRoom;
  std::map<int, RoomObject> objInRoom;

  std::map<Direction, std::pair<bool, std::pair<int, int>>> adjRooms;
  bool checkDirection(Direction);

  bool hasEnemy;

  std::list<int> changedObj;
  std::string roomMessage;

  &Person getNPC(int);
  &RoomObject getObj(int);
};

#endif // ROOM_H

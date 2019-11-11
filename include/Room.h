#ifndef ROOM_H
#define ROOM_H

#include "Object.h"
#include <map>
#include <list>
#include "Direction.h"
#include "Person.h"
#include "Chest.h"
#include "Lock.h"
#include "Lever.h"
#include "DoorMood.h"

class Room : public Object {
 public:
  /**
  *constructor
  *@param int for the identifier that corresponds to the room
  *@throw if id doesnt describe a room
  *@throw if file data is not formatted correctly to be read
  *@throw if room file cannot be opened
  */
  Room(int);

  /**
  *destructor
  */
  virtual ~Room();

  bool checkForEnemy();
  bool checkForNPC(int);
  bool checkForObj(int);

  std::pair<int, int> getDirection(Direction);

  void objChanged(int);
  std::string getMessage();

  std::list<int> objToSave();

 private:
  std::map<int, Person*> npcInRoom;
  std::map<int, RoomObject*> objInRoom;

  std::map<Direction, std::pair<DoorMood, std::pair<int, int>>> adjRooms;

  bool hasEnemy;

  std::list<int> changedObj;
  std::string roomMessage;

  bool checkDirection(Direction);
  Person* getNPC(int);
  RoomObject* getObj(int);
};

#endif // ROOM_H

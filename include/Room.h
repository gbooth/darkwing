/**
 *@author Gavin Booth
 *@date 2019-11
 */

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

class Person;

/**
 * This function gives all the identifiers related with the rooms:
 * checking for Enemies, orientation for the player.checking for objects
 */


class Room : public Object {
 public:
  /**
  *Default constructor
  */
  Room(int);

  /**
  *Destructor
  */
  virtual ~Room();

  bool checkForEnemy();
  void setHasEnemy();
  bool checkForNPC(int);
  bool checkForObj(int);

  std::pair<int, int> getDirection(Direction);

  void objChanged(int);
  std::string getMessage();

  std::list<int> objToSave();

  void setDoor(Room**);
  void upDoorMood(Direction, DoorMood);

  Person* const getNPC(int);
  RoomObject* const getObj(int);
 private:
  std::map<int, Person*> npcInRoom;
  std::map<int, RoomObject*> objInRoom;

  std::map<Direction, std::tuple<DoorMood, RoomObject*, int, int>> adjRooms;

  bool hasEnemy;

  std::list<int> changedObj;
  std::string roomMessage;

  bool checkDirection(Direction);
  void setDoorMood(Direction, DoorMood);
};

#endif // ROOM_H

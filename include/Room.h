/**
 *@author Gavin Booth
 *@date 2019-11
 */

#ifndef ROOM_H
#define ROOM_H

#include "Object.h"
#include "Direction.h"
#include "Person.h"
#include "Chest.h"
#include "Lock.h"
#include "Lever.h"
#include "DoorMood.h"
#include <map>
#include <list>
#include <tuple>
#include <utility>
#include <string>

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

  /**
   *This function gives the existence of an Enemy.
   * @return hasEnemy.
   */
  bool checkForEnemy();

  /**
   *This function set the Enemy to false.
   */
  void setHasEnemy();

  /**
   *This function gives if NPC in the room or not.
   *@throw invalid_id error"id not for a person"
   *@return true
   */
  bool checkForNPC(int);

  /**
   *Function that give ,if there is an object in the room.
   *@throw invalid_id Error:"id not for room object"
   *@return true.
   */
  bool checkForObj(int);

  /**
   *Checks the directions for adjacent room to move.
   */
  std::pair<int, int> getDirection(Direction);

  /**
   *this function identify the object in the room.
   *@throw invalid_id Error:"obj not in this room"
   */
  void objChanged(int);

  /**
   *This function will give you message related with the rooms.
   * @return roomMessage
   */
  std::string getMessage();

  /**
   *this function checks that the objects are unique before saving.
   *@return changeObj which means change objects.
   */
  std::list<int> objToSave();

  /**
   *Set the coordinates of the rooms.
   *@throw file_error "door depend file is missing"
   */
  void setDoor(Room**);

  /**
   * Gives the direction of the door and the state.
   * @throw file_error"door depend file is missing"
   */
  void upDoorMood(Direction, DoorMood);

  /**
   *Detects if there is an NPC in the roomGG
   *@return constant person pointer
   */
  Person* const getNPC(int);

  /**
   *This function gives he identifier of the object in the room.
   */
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

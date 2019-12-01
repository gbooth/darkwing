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
  *constructor
  *@param a the id of the room
  */
  Room(int a);

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
   *can change hasEnemy value
   */
  void setHasEnemy();

  /**
   *This function gives if NPC in the room or not.
   *@param a the id to check for in the room
   *@throw invalid_id error"id not for a person"
   *@return true
   */
  bool checkForNPC(int a);

  /**
   *Function that give ,if there is an object in the room.
   *@param a the id of the object to check for
   *@throw invalid_id Error:"id not for room object"
   *@return true.
   */
  bool checkForObj(int a);

  /**
   *Checks the directions for adjacent room to move.
   *@param d the direction to check
   */
  std::pair<int, int> getDirection(Direction d);

  /**
   *this function identify the object in the room.
   *@param a the id of the object changed
   *@throw invalid_id Error:"obj not in this room"
   */
  void objChanged(int a);

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
   *@param r the world containing the doors
   *@throw file_error "door depend file is missing"
   */
  void setDoor(Room** r);

  /**
   * Gives the direction of the door and the state.
   * @param a the direction of the door
   * @param b the state of the door
   * @throw file_error"door depend file is missing"
   */
  void upDoorMood(Direction a, DoorMood b);

  /**
   *Detects if there is an NPC in the room.
   *@param a the id of the NPC to return
   *@return constant person pointer
   */
  Person* const getNPC(int a);

  /**
   *This function gives he identifier of the object in the room.
   *@param a the id of the object to get in the room
   *@return pointer to the RoomObject you are searching for
   */
  RoomObject* const getObj(int a);

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

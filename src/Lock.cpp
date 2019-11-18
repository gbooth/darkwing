/**
*@author Jorge Aceytuno g
*@date  2019-11-05
*/

#include"Lock.h"
#include"Room.h"
#include<fstream>
#include<string>
#include"Exceptions.h"
#include "RoomObject.h"
#include<iostream>


/** This class is implemented as a derived class of Room Objects and the purpouse is
* to give access to different objects to access during the game.
*/
Lock::Lock(int id) : RoomObject{id} {
  std::string line;
  std::string idStr = std::to_string(id);
  std::fstream lockData;
  lockData.open("Locks.csv");
  if (lockData.is_open()) {
    while (!lockData.eof()) {
      getline(lockData, line, ',');
      if (line == idStr) {
        getline(lockData, line);
        lockValue = std::stoi(line);
        break;
      } else {
        lockData.ignore(1000, '\n');
      }
      if (line != idStr && lockData.eof()) {
        throw invalid_id("ERROR:the ID specified is not on file");
        lockData.close();
      }
    }
  } else {
    throw file_error("ERROR: the file you are trying to open is missing");
  }
}

Lock::~Lock() {}

void Lock::unlock(Item key) {
  if (this->getID() == 2203) {
    if (this->checkKey(key))
      std::cout << "The map clearly shows the way out of the forest is east" <<
                std::endl;
    this->setState(true);
  } else {
    if (this->checkKey(key)) {
      std::cout <<
                "The key fits perfectly into "
                << "the lock and turns, unlocking the door"
                << std::endl;
      this->setState(true);
    } else {
      std::cout << "The key fits into the lock but wont turn" << std::endl;
    }
  }
}

/** This function verify if the player is using the right key.
 */
bool Lock::checkKey(Item key) {
  if (key.getItemValue() != lockValue)
    return false;
  else
    return true;
}

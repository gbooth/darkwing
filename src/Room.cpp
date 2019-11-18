#include "Room.h"
#include "Direction.h"
#include "Exceptions.h"
#include "Villager.h"
#include "Enemy.h"
#include "Chest.h"
#include "Lock.h"
#include "Lever.h"
#include<string>
#include<map>
#include<list>
#include<cassert>
#include<utility>
#include<iostream>
#include<fstream>
#include<algorithm>

Room::Room(int id) : Object{id} {
  if (id / 1000 != 1 || id > 1026)
    throw invalid_id("ID does not identify a room");

  std::ifstream in;
  std::string readIn;
  int tempX, tempY, tempID = 0;
  DoorMood tempDoor;

  in.open("mapReference.csv");

  if (in.is_open()) {
    //find the appropriate line in the reference file that corresponds to the id
    for (std::getline(in, readIn, ':'); id != std::stoi(readIn, nullptr, 10);
         in.ignore(1000, '\n'), std::getline(in, readIn, ':')) {}
    std::getline(in, readIn, ':');
    roomMessage = readIn;
    //map directions
    std::getline(in, readIn, ':');
    Direction tempDir = north;
    for (int i = 0; i < 4;
         std::getline(in, readIn, ':'),
         i++, tempDir = static_cast<Direction>(i)) {
      if (readIn == "|")
        continue;
      tempX = readIn[0] - '0';
      tempY = readIn[1] - '0';
      switch (readIn[2]) {
      case 't':
        tempDoor = ajar;
        break;
      case 'l':
        tempDoor = locked;
        break;
      case 'b':
        tempDoor = blocked;
        break;
      default:
        throw file_error("file has incorrect data - 1");
      }
      adjRooms[tempDir] = std::make_tuple(tempDoor, nullptr, tempX, tempY);
    }

    //create and map NPCs
    for (uint i = 0; i < readIn.length()/4; i++) {
      for (int j = 0; j < 4; j++)
        switch (j) {
        case 0:
          tempID += 1000 * (readIn[(i*4) + j] - '0');
          break;
        case 1:
          tempID += 100 * (readIn[i*4 + j] - '0');
          break;
        case 2:
          tempID += 10 * (readIn[i*4 + j] - '0');
          break;
        case 3:
          tempID += (readIn[i*4 + j] - '0');
          break;
        }
      switch (tempID/100%10) {
      case 2: {
        Villager* temp = new Villager(tempID);
        npcInRoom[tempID] = temp;
        break;
      }
      case 3: {
        Enemy* temp = new Enemy(tempID);
        npcInRoom[tempID] = temp;
        break;
      }
      default:
        throw file_error("file has incorrect data - 2");
        break;
      }
      tempID = 0;
    }

    //create and map Room Objects
    std::getline(in, readIn, ':');
    for (uint i = 0; i < readIn.length()/4; i++) {
      for (int j = 0; j < 4; j++)
        switch (j) {
        case 0:
          tempID += 1000 * (readIn[i*4 + j] - '0');
          break;
        case 1:
          tempID += 100 * (readIn[i*4 + j] - '0');
          break;
        case 2:
          tempID += 10 * (readIn[i*4 + j] - '0');
          break;
        case 3:
          tempID += (readIn[i*4 + j] - '0');
          break;
        default:
          throw file_error("file has incorrect data  - 3");
          break;
        }
      switch (tempID/100%10) {
      case 1: {
        Chest* temp = new Chest(tempID);
        objInRoom[tempID] = temp;
        break;
      }
      case 2: {
        Lock* temp = new Lock(tempID);
        objInRoom[tempID] = temp;
        break;
      }
      case 3: {
        Lever* temp = new Lever(tempID);
        objInRoom[tempID] = temp;
        break;
      }
      default:
        throw file_error("file has incorrect data - 4");
        break;
      }
      tempID = 0;
    }

    std::getline(in, readIn);
    if (readIn == "t")
      hasEnemy = true;
    else
      hasEnemy = false;
  } else {
    throw file_error("room file not present");
  }
  in.close();
}

Room::~Room() {
  for (auto it = objInRoom.begin(); it != objInRoom.end(); ++it)
    delete it->second;
  for (auto it = npcInRoom.begin(); it != npcInRoom.end(); ++it)
    delete it->second;
}

bool Room::checkForEnemy() {
  return hasEnemy;
}

void Room::setHasEnemy() {
  hasEnemy = false;
}

bool Room::checkForNPC(int id) {
  if (id/1000 == 3) {
    if (npcInRoom.end() != npcInRoom.find(id)) {
      return true;
    } else {
      return false;
    }
  } else {
    throw invalid_id("id not for a person");
  }
}

bool Room::checkForObj(int id) {
  if (id/1000 == 2) {
    if (objInRoom.end() != objInRoom.find(id)) {
      return true;
    } else {
      return false;
    }
  } else {
    throw invalid_id("id not for room object");
  }
}

bool Room::checkDirection(Direction d) {
  if (adjRooms.end() == adjRooms.find(d))
    return false;
  else
    return true;
}

std::pair<int, int> Room::getDirection(Direction d) {
  if (this->checkDirection(d)) {
    switch (std::get<0>(adjRooms[d])) {
    case ajar: {
      return std::make_pair(std::get<2>(adjRooms[d]), std::get<3>(adjRooms[d]));
    }
    case blocked: {
      if (std::get<1>(adjRooms[d])) {
        if (std::get<1>(adjRooms[d])->getState()) {
          return std::make_pair(std::get<2>(adjRooms[d]),
                                std::get<3>(adjRooms[d]));
        } else {
          return std::make_pair(0, -1);
        }
      }
    }
    case locked: {
      if (std::get<1>(adjRooms[d])) {
        if (std::get<1>(adjRooms[d])->getState()) {
          return std::make_pair(std::get<2>(adjRooms[d]),
                                std::get<3>(adjRooms[d]));
        } else {
          return std::make_pair(0, -2);
        }
      }
    }
    }
  } else {
    return std::make_pair(-1, -1);
  }
}

void Room::objChanged(int id) {
  if (this->checkForObj(id))
    changedObj.push_back(id);
  else
    throw invalid_id("obj not in this room");
}

std::string Room::getMessage() {
  return roomMessage;
}

std::list<int> Room::objToSave() {
  changedObj.sort();
  changedObj.unique();
  return changedObj;
}

void Room::setDoor(Room** world) {
  std::ifstream in("doorDep.csv");
  std::string readIn;
  Direction dir;
  int x, y, roomObjID;

  if (in.is_open()) {
    getline(in, readIn, ':');
    while (!in.eof()) {
      if (this->getID() == std::stoi(readIn)) {
        getline(in, readIn, ':');
        dir = static_cast<Direction>(std::stoi(readIn));
        std::getline(in, readIn, ':');
        x = readIn[0] - '0';
        y = readIn[1] - '0';
        std::getline(in, readIn);
        std::get<1>(adjRooms[dir]) = world[x][y].getObj(std::stoi(readIn));
      } else {
        in.ignore(1000, '\n');
      }
      std::getline(in, readIn, ':');
    }
  } else {
    throw file_error("door depend file is missing");
  }
}

Person* const Room::getNPC(int id) {
  if (this->checkForNPC(id))
    return npcInRoom[id];
  else
    return nullptr;
}

RoomObject* const Room::getObj(int id) {
  if (this->checkForObj(id))
    return objInRoom[id];
  else
    return nullptr;
}

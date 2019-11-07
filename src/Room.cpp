#include "Room.h"
#include "Direction.h"
#include "Villager.h"
#include "Enemy.h"
#include<string>
#include<map>
#include<list>
#include<utility>
#include<iostream>
#include<fstream>
#include<algorithm>

Room::Room(int id) : Object{id} {
  if (id / 1000 != 1 || id > 1022)
    throw invalid_id("ID does not identify a room");

  std::ifstream in;
  std::string readIn;
  int tempX, tempY, tempID = 0;
  DoorMood tempDoor;

  in.open("mapReference.csv");

  if (in.is_open()) {
    //find the appropriate line in the reference file that corresponds to the id
    for (std::getline(in, readIn, ','); id != std::stoi(readIn, nullptr, 10);
         in.ignore(1000, '\n'), std::getline(in, readIn, ','));

    std::getline(in, readIn, ',');
    roomMessage = readIn;

    //map directions
    std::getline(in, readIn, ',');
    Direction tempDir = north;
    for (int i = 0; i < 4; std::getline(in, readIn, ','), i++, tempDir + 1) {
      if (readIn == "|")
        continue;
      tempX = readIn[0] - '0';
      tempY = readIn[1] - '0';
      switch(readIn[2]){
      case 't':
        tempDoor = open;
        break;
      case 'l':
        tempDoor = locked;
        break;
      case 'b':
        tempDoor = blocked;
        break;
      default:
        throw file_error("file has incorrect data");
      }
      adjRooms[tempDir] = std::make_pair(tempDoor, std::make_pair(tempX, tempY));
    }

    //create and map NPCs
    std::getline(in, readIn, ',');
    for (int i = 0; i < readIn.length()/4; i++) {
      for (int j = 0; j < 4; j++)
        switch (j) {
        case 0:
          tempID += 1000 * readIn[i*4 + j] - '0';
          break;
        case 1:
          tempID += 100 * readIn[i*4 + j] - '0';
          break;
        case 2:
          tempID += 10 * readIn[i*4 + j] - '0';
          break;
        case 3:
          tempID += readIn[i*4 + j] - '0';
          break;
        }
      switch (tempID/100%10) {
      case 2:
        Villager temp(tempID);
        npcInRoom[tempID] = temp;
        break;
      case 3:
        Enemy temp(tempID);
        npcInRoom[tempID] = temp;
        break;
      default:
        throw file_error("file has incorrect data");
        break;
      }
      tempID = 0;
    }

    //create and map Room Objects
    std::getline(in, readIn, ',');
    for (int i = 0; i < readIn.length()/4; i++) {
      for (int j = 0; j < 4; j++)
        switch (j) {
        case 0:
          tempID += 1000 * readIn[i*4 + j] - '0';
          break;
        case 1:
          tempID += 100 * readIn[i*4 + j] - '0';
          break;
        case 2:
          tempID += 10 * readIn[i*4 + j] - '0';
          break;
        case 3:
          tempID += readIn[i*4 + j] - '0';
          break;
        default:
          throw file_error("file has incorrect data");
          break;
        }
      switch (tempID/100%10) {
      case 1:
        Chest temp(tempID);
        objInRoom[tempID] = temp;
        break;
      case 2:
        Lock temp(tempID);
        objInRoom[tempID] = temp;
        break;
      case 3:
        Lever temp(tempID);
        objInRoom[tempID] = temp;
        break;
      default:
        throw file_error("file has incorrect data");
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
}

bool Room::checkForEnemy() {
  return hasEnemy;
}

bool Room::checkForNPC(int id) {
  if (id/1000 == 3)
    if (npcInRoom.end() != npcInRoom.find(id))
      return true;
    else
      return false;
  else
    throw invalid_id("id not for a person");
}

bool Room::checkForObj(int id) {
  if (id/1000 == 2)
    if (objInRoom.end() != objInRoom.find(id))
      return true;
    else
      return false;
  else
    throw invalid_id("id not for room object");
}

bool Room::checkDirection(Direction d) {
  if (adjRooms.end() == adjRooms.find(d))
    return false;
  else
    return true;
}

std::pair<int, int> Room::getDirection(Direction d) {
  if (this->checkDirection(d))
    switch(adjRooms[d].first){
    case open:
      return adjRooms[d].second;
    case blocked:
      return std::make_pair(0, -1);
    case locked:
      return std::make_pair(0, -2);
  }
  else{
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

&Person Room::getNPC(int id) {
  assert(this->checkForNPC(id));
  return npcInRoom[id];
}

&RoomObject Room::getObj(int id) {
  assert(this->checkForObj(id));
  return objInRoom[id];
}

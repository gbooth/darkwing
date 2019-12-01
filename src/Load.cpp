/**
 * @author Gavin Booth
 * @date 2019-11
 */
#include "Load.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <map>
#include <utility>
Load::Load(std::string fName) {
  std::string readIn, objData;
  int roomID, objID;
  bool objState, roomEn;
  filename = fName;
  loadFile.open(fName);

  for (int i = 0; i < 4; i++) {
    getline(loadFile, readIn, ':');
    switch (i) {
    case 0:
      if (readIn != "HP")
        throw file_error("File data corrupt or invalid:HP");
      break;
    case 1:
      if (readIn != "pos")
        throw file_error("File data corrupt or invalid:pos");
      break;
    case 2:
      if (readIn != "inv")
        throw file_error("File data corrupt or invalid:inv");
      break;
    case 3:
      if (readIn != "equipWep")
        throw file_error("File data corrupt or invalid:equipWep");
      break;
    }
    getline(loadFile, readIn);
    heroLoadMap[static_cast<HeroAtt>(i)] = readIn;
  }

  getline(loadFile, readIn, ':');
  while (!loadFile.eof()) {
    roomID = std::stoi(readIn);
    getline(loadFile, readIn);
    objData = readIn;

    while (true) {
      if (objData.size() == 1) {
        if (objData == "f") {
          roomEnemy[roomID] = false;
          break;
        } else {
          throw file_error("File data corrupt:hasEnemy");
        }
      }
      objID = std::stoi(objData.substr(0, 4));
      objData.erase(0, 4);
      if (objData[0] - '0' == 1)
        objState = true;
      else if (objData[0] - '0' == 0)
        objState = false;
      else
        throw file_error("File data corrupt:ObjState");
      objData.erase(0, 2);
      roomLoadState[roomID][objID] = objState;
    }
    getline(loadFile, readIn, ':');
  }
}

Load::~Load() {}

void Load::loadGame(Hero& h, Room** world) {
  this->loadHero(h);
  this->loadRooms(world);
}

void Load::loadHero(Hero& h) {
  Item* equipedWep = nullptr;
  for (auto heroMap : heroLoadMap) {
    switch (heroMap.first) {
    case HP: {
      h.setHealth(stoi(heroMap.second));
      break;
    }
    case pos: {
      h.setPosition(std::make_pair(heroMap.second[0] - '0'
                                   , heroMap.second[1] - '0'));
      break;
    }
    case invnty: {
      int loop = heroMap.second.size()/6;
      for (int i = 0; i < loop; i++) {
        Item* temp = new Item(stoi(heroMap.second.substr(0, 4)));
        if (temp->getID() == stoi(heroLoadMap[equipWep]))
          equipedWep = temp;
        for (int j = 0; j < heroMap.second[4] - '0'; j++)
          h.addInventory(temp, false);
        heroMap.second.erase(0, 6);
      }
      break;
    }
    case equipWep: {
      if (stoi(heroMap.second) == 4205)
        break;
      h.setWeapon(equipedWep);
      break;
    }
    }
  }
}

void Load::loadRooms(Room** world) {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      for (auto it : roomLoadState[world[i][j].getID()])
        if (it.first/1000 == 2) {
          if (it.second)
            world[i][j].getObj(it.first)->setState(true);
        } else {
          throw file_error("Load file has corrupted or invalid data");
        }
  for (auto it : roomEnemy) {
    switch (it.first) {
    case 1004: {
      world[3][0].setHasEnemy();
      break;
    }
    case 1005: {
      world[4][0].setHasEnemy();
      break;
    }
    case 1011: {
      world[0][2].setHasEnemy();
      break;
    }
    case 1012: {
      world[1][2].setHasEnemy();
      break;
    }
    case 1015: {
      world[4][2].setHasEnemy();
      break;
    }
    default: {
      break;
    }
    }
  }
}

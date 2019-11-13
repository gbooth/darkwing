#include "Load.h"
#include<string>
#include<map>

Load::Load() {
  std::string readIn, objData;
  int roomID, objID, objState;

  while (true) {
    cout << "Enter the save file name(without filetype)." << endl
         << "Enter \"exit\" to exit file loading --";
    getline(std::cin, filename);
    if(filename == "exit")
      goto endLoad;
    loadFile.open(filename + ".txt");
    if (loadFile.is_open())
      break;
    else
      std::cout << "Invalid file" << std::endl;
  }

  for (int i = 0; i < 4; i++) {
    getline(loadFile, readIn, ':');
    switch (i) {
    case 0:
      if (readIn != "HP")
        throw file_error("File data corrupt or invalid");
    case 1:
      if (readIn != "pos")
        throw file_error("File data corrupt or invalid");
    case 2:
      if (readIn != "inv")
        throw file_error("File data corrupt or invalid");
    case 3:
      if (readIn != "equipWep")
        throw file_error("File data corrupt or invalid");
    }
    getline(loadFile, readIn);
    heroLoadMap[static_cast<HeroAtt>(i)] = readIn;
  }

  getline(loadFile, readIn, ':');
  while (!loadFile.eof()) {
    roomID = std::stoi(readIn);
    getline(loadFile, readIn);
    objData = readIn;

    for(int i = 0; i < readIn.size()/5; i++){
      objID = std::stoi(objData.substr(0, 4));
      objData.erase(0, 4);
      if(objData.size() == 2)
        objState = std::stoi(objData);
      else{
        objState = objData[0] - '0';
        objData.erase(0, 1);
      }
      roomLoadState[roomID][objID] = objState;
    }
    getline(loadFile, readIn, ':');
  }
endLoad:
}

Load::~Load() {}

void Load::loadGame(const Hero* h, const Room** world) {
   this->loadHero(h);
   this->loadRooms(world);
}

void Load::loadHero(const Hero* h) {
  for(auto heroMap : heroLoadMap){
    switch(heroMap.first)
    case HP:
      h->setHealth(stoi(heroMap.second));
      break;
    case pos:
      h->setPosition(std::make_pair(heroMap.second[0] - '0', heroMap.second[1] - '0'));
      break;
    case inv:
      for(int i = 0; i < heroMap.second.size()/5; i++){
        for(int j = 0; j < heroMap.second[4] - '0'; j++)
          h->addInv(new Item(stoi(heroMap.second.substr(0, 4))));
        heroMap.second.erase(0, 5);
      }
      break;
    case equipWep:
      h->setWeapon(stoi(heroMap.second));
      break;
  }
}

void Load::loadRooms(const Room** world) {
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      for(auto it : roomLoadState.second)
        switch(it.first/1000){
        case 2:
          if(it.second != 0)
            world[i][j].getObj(it).setState(true);
            break;
          else
            break;
        case 3:
          world[i][j].getNPC(it).setHealth(it.second);
          break;
        default:
          throw file_error("Load file has corrupted or invalid data");
        }
}

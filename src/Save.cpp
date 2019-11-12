#include "Save.h"
#include "Exceptions.h"

Save::Save(const Hero* h, const Room** r) {
  std::string fname;
  std::string out;
  std::cout << "Enter file name you wish to save as (no need for extension): " <<
            std::endl;
  std::cin >> fname;
  fileName = fname + ".txt";

  std::string posit = to_string(h->getPos().first)+to_string(h->getPos().second);
  std::string invStr = "";
  for (auto it = h->invSave().begin(); it != h->invSave().end(); it++) {
    invStr += it->first + it->second + ",";
  }

  //all the attributes of a hero
  heroSaveMap[HP] = std::to_string(h->getHealth());
  heroSaveMap[pos] = posit;
  heroSaveMap[inv] = invStr;
  heroSaveMap[equipWep] = h->getWeapon().getName();

  //all the attributes of a room and its objects
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      out = "";
      list<int> objSave = r[i][j].objToSave();
      for (auto it: objSave) {
        if (it/1000 == 2) {
          out += it;
          if (r[i][j].getObj(it).getState())
            out += '1' + ',';
          else
            out += '0'+ ',';
        } else {
          out += it;
          if (std::to_string(r[i][j].getNPC(it)->getHealth()).length() < 2)
            out += '0' + std::to_string(r[i][j].getNPC(it)->getHealth());
          else
            std::to_string(r[i][j].getNPC(it)->getHealth())
          }
      }
      roomObj[r[i][j].getID()] = out;
    }
  }
}

Save::~Save() {}

void Save::saveGame() {
  saveFile.open(fileName, std::ios_base::app);
  if(saveFile.is_open()){
    saveHero();
    saveGame();
    saveFile.close();
  } else {
    throw file_error("ERROR: save file not open");
  }
}

void Save::saveHero() {
  for (auto it : heroSaveMap) {
    switch (it.first) {
    case HP:
      saveFile << "HP:" << it.second << std::endl;
      break;
    case pos:
      saveFile << "pos:" << it.second << std::endl;
      break;
    case equipWep:
      saveFile << "equipWep:"<< it.second << std::endl;
      break;
    case inv:
      saveFile << "inv:" << it.second << std::endl;
      break;
    }
  }
}

void Save::saveRoom() {
  for (auto it: roomObj) {
    saveFile << it.first << ":" << it.second << std::endl;
  }
}


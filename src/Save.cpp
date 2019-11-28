#include "Save.h"
#include "Exceptions.h"
#include<list>
#include<utility>
#include<string>
#include<vector>

Save::Save(Hero* h, Room** r) {
  std::string fname;
  std::string out;
  bool goodFileName = true;
  while (true) {
    std::cout << "Enter file name you wish to save as\n(no need for extension "
              << "& no characters other than the good old alphabet): ";
    getline(std::cin, fname);
    for (int i = 0; i < fname.size(); i++)
      if (!((fname[i] >= 65 && fname[i] <= 90) || (fname[i] >= 97
            && fname[i] <= 122)))
        goodFileName = false;
    if (goodFileName)
      break;
    std::cout << "no characters not in the alphabet.\n";
  }

  fileName = fname + ".txt";

  std::string posit = std::to_string(h->getPos().first)+std::to_string(
                        h->getPos().second);
  std::string invStr = "";
  std::vector<std::pair<int, int>> invS = h->invSave();
  for (uint i = 0; i < invS.size(); i++) {
    invStr += std::to_string(invS[i].first) + std::to_string(invS[i].second);
    invStr += ",";
  }


//all the attributes of a hero
  heroSaveMap[HP] = std::to_string(h->getHealth());
  heroSaveMap[pos] = posit;
  heroSaveMap[invnty] = invStr;
  heroSaveMap[equipWep] = std::to_string(h->getWeapon()->getID());

//all the attributes of a room and its objects
  int rID = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      rID = r[i][j].getID();
      out = "";
      std::list<int> objSave = r[i][j].objToSave();
      for (auto it : objSave) {
        if (it/1000 == 2) {
          out += std::to_string(it);
          if (r[i][j].getObj(it)->getState())
            out += "1,";
          else
            out += "0,";
        }
      }
      if (!r[i][j].checkForEnemy())
        out += "f";
      if (out != "f" && out != "")
        roomObj[rID] = out;
      else if ((rID == 1004 || rID == 1005 || rID == 1011 || rID == 1012
                || rID == 1015) && out != "")
        roomObj[rID] = out;
    }
  }
}

Save::~Save() {}

void Save::saveGame() {
  saveFile.open(fileName, std::ios_base::trunc);
  if (saveFile.is_open()) {
    saveHero();
    saveRoom();
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
    case invnty:
      saveFile << "inv:" << it.second << std::endl;
      break;
    }
  }
}

void Save::saveRoom() {
  for (auto it : roomObj) {
    saveFile << it.first << ":" << it.second << std::endl;
  }
}


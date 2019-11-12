#include "Save.h"
#include "Exceptions.h"

Save::Save(Hero* h, Room** r) {
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

  heroSaveMap[HP] = std::to_string(h->getHealth());
  heroSaveMap[pos] = posit;
  heroSaveMap[inv] = invStr;
  heroSaveMap[equipWep] = h->getWeapon().getName();

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      out = "";
      list<int> objSave = r[i][j].objToSave();
      for(auto it: objSave){
        if(it/1000 == 2){
          out += it;
          if(r[i][j].getObj(it).getState())
            out += '1';
          else
            out += '0';
        }else{
          out += it;
          out += std::to_string(r[i][j].getNPC(it).getHealth());
        }
      }
      roomObj[r[i][j].getID()] = out;
    }
  }
}

Save::~Save() {}

void Save::saveHero(Hero* h) {

  for (auto it : heroSaveMap) {
    saveFile << it.first << ": " << it.second << std::endl;

  }

}

void Save::saveRoom(Room* r) {

}


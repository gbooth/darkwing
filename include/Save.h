#ifndef SAVE_H
#define SAVE_H

#include "HeroAtt.h"
#include "Hero.h"
#include "Room.h"
#include <fstream>
#include <map>
#include <list>



class Save {
 public:

  Save(Hero* h, Room** r);

  virtual ~Save();

  void saveGame();
 private:
  void saveHero();
  void saveRoom();
  std::ofstream saveFile;
  std::map<HeroAtt, std::string data> heroSaveMap;
  std::map<int roomID, std::list<int objID>> roomObj;
  std::string fileName;
};

#endif // SAVE_H

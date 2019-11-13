#ifndef LOAD_H
#define LOAD_H

#include "HeroAtt.h"
#include "Room.h"
#include "Hero.h"
#include<map>
#include<fstream>
#include<string>

class Load {
 public:
  Load();
  virtual ~Load();
  void loadGame(Hero* const, Room** const);

 private:
  std::ifstream loadFile;
  std::map<HeroAtt, std::string> heroLoadMap;
  std::map<int, std::map<int, int>> roomLoadState;
  std::string filename;

  void loadHero(Hero* const);
  void loadRooms(Room** const);
};

#endif // LOAD_H

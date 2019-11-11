#ifndef LOAD_H
#define LOAD_H

#include "HeroAtt.h"
#include<map>
#include<fstream>
#include<string>

class Load {
 public:
  Load();
  virtual ~Load();
  void loadHero();
  void loadRooms();

 private:
  std::ifstream loadFile;
  std::map<HeroAtt, std::string> heroLoadMap;
  std::map<int, bool> roomLoadState;
  std::string filename;
};

#endif // LOAD_H

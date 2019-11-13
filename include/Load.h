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
  void loadGame(const Hero*, const Room**);

 private:
  std::ifstream loadFile;
  std::map<HeroAtt, std::string> heroLoadMap;
  std::map<int, std::map<int, int>> roomLoadState;
  std::string filename;

  void loadHero(const Hero*);
  void loadRooms(const Room**);
};

#endif // LOAD_H

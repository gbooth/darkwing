/**
 *@author Gavin Booth
 *@date 2019-11
 */

#ifndef LOAD_H
#define LOAD_H
#include "HeroAtt.h"
#include "Room.h"
#include "Hero.h"
#include<map>
#include<fstream>
#include<string>

/**
 *This class will provide the load for the player and rooms conditions.
 */
class Load {
 public:
  /**
   *Default Constructor
   *@param s is the filename
   */
  Load(std::string s);

  /**
   *Default Destructor
   */
  virtual ~Load();

  /**
   *Function that load the game.
   *@param the hero
   *@param r the world containing the hero
   */
  void loadGame(Hero&, Room** r);

 private:
  std::ifstream loadFile;
  std::map<HeroAtt, std::string> heroLoadMap;
  std::map<int, std::map<int, bool>> roomLoadState;
  std::map<int, bool> roomEnemy;
  std::string filename;
  void loadHero(Hero&);
  void loadRooms(Room**);
};

#endif // LOAD_H

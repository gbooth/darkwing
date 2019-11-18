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
   *In the Constructor will be asked the player for the save filename without the typefilename.
   *providing the options for health,position,inventory and weapon.
   */
  Load();

  /**
   *Default Destructor
   */
  virtual ~Load();

  /**
   *Function that load the game.
   */
  void loadGame(Hero&, Room**);

  /**
   *@param loadfile that will hold the information at the time of load.
   *@param heroLoadMap will provide the map for the Hero.
   *@param roomLoadState will give the room state at load for the Hero.
   *@param filename provides the name for the file.
   * @param roomEnemy
   */
 private:
  std::ifstream loadFile;
  std::map<HeroAtt, std::string> heroLoadMap;
  std::map<int, std::map<int, bool>> roomLoadState;
  std::map<int, bool> roomEnemy;
  std::string filename;

  /**
   *This function considering private,will give the condition for the Hero at the load time as Health
   *Position,Inventory and Weapon.
   *Hero at loading time.
   */
  void loadHero(Hero&);

  /**
   *This function,considering private will give the condition for the room when loading as state,
   * npc,health,objects.
   * in case of file misreading.
   */
  void loadRooms(Room**);
};

#endif // LOAD_H

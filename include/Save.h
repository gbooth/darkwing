/**
* @author Ben Hunt
* @date Fall 2019
*/

#ifndef SAVE_H
#define SAVE_H

#include "HeroAtt.h"
#include "Room.h"
#include "Hero.h"
#include <fstream>
#include <map>
#include <list>
#include <string>

/**
 *This function help the Hero to save all the condition during the game.
 */
class Hero;

/**
* Helps to save the game complete.
*/
class Save {
 public:
  /**
  *Default constructor
  *@param h the hero
  *@param r the world containing the hero
  */
  Save(Hero* h, Room** r);

  /**
  *Virtual destructor
  */
  virtual ~Save();

  /**
  *The function to save the game entirely.
  * @throw file_error "ERROR: save file not open"
  */
  void saveGame();

 private:
  /**
   * helper function to save Hero
   */
  void saveHero();
  /**
   *helper function to save room .
  */
  void saveRoom();
  std::ofstream saveFile;
  std::map<HeroAtt, std::string> heroSaveMap;
  std::map<int, std::string> roomObj;
  std::string fileName;
};

#endif // SAVE_H

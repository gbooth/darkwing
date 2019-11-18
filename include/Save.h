/**
* @author Ben Hunt
* @date Fall 2019
*/

#ifndef SAVE_H
#define SAVE_H

#include "HeroAtt.h"
#include "Room.h"
#include <fstream>
#include <map>
#include <list>
#include "Hero.h"

class Hero;

class Save {
public:
 /**
 *Default constructor
 */
 Save(Hero*, Room**);

 /**
 *Virtual destructor
 */
 virtual ~Save();
 /**
 *the function to save the game entirely
 * @throw file_error if save file doesn't open
 */
 void saveGame();

private:
  /**< helper function to save Hero */
 void saveHero();
 /**< helper function to save room */
 void saveRoom();
 std::ofstream saveFile;
 std::map<HeroAtt, std::string> heroSaveMap;
 std::map<int, std::string> roomObj;
 std::string fileName;
};

#endif // SAVE_H

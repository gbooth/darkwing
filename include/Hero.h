/**
 *@author  Wesley Waldern
 *@date  2019-11
 */

#ifndef HERO_H
#define HERO_H

#include "Person.h"
#include <string>
#include "Room.h"
#include "Item.h"
#include <map>
#include "Direction.h"
#include <list>
#include "RoomObject.h"
#include "Villager.h"
#include "Command.h"
#include "Save.h"
#include "GitGud.h"

/**
 *This class will provide to the Hero or player, all the conditions that he is involve with ,during the whole game as: Weapons,Enemy identifier,position,
 *Directions,inventory.
 */
class Hero : public Person {
 public:
  /**
   *Default Constructor
   */
  Hero();

  /**
  *Default destructor.
   */
  virtual ~Hero();

  /**
   *This function define the npc by the hero.
   */
  bool attack(Person*, Room**);

  /**
   *This function give the description of the object selected by the hero.
   * @return the description of the object.
   */
  std::string inspect(Object*);

  /**
   *This function gives the weapon identifier.
   * @return the identifier of the chosen weapon.
   */
  Item* getWeapon();

  /**
   *This function let you set the identifier of the weapon of choice.
   * @return the weapon of choice.
   */
  void setWeapon(Item*);

  /**
  *This function will gives the direction and the position of the hero.
  */
  void mv(Direction, Room**);

  /**
   *This function gives you the position of the hero.
   * @throw "ERROR: position out of bounds" if the firs and second position is > 4.
   */
  void setPosition(std::pair<unsigned int, unsigned int>);

  /**
   *this function access the position of the player.
   */
  std::pair<unsigned int, unsigned int> getPos();

  /**
   *This function gives the inventory saved.
   */
  std::vector<std::pair<int, int>> invSave();

  /**
   *This function gives the current inventory any time during the game.
   */
  void getInventory();

  /**
   *This function tell you what object has been added to your inventory.
   */
  void addInventory(Item*, bool);

  /**
   * This function give you the health when using potions.
   */
  void usePotion(Item*);

  /**
   *This function unlock when using the right key.
   */
  void useKey(Item*, Lock*);

  /**
   *This function let you know to talk with the Villager whe you are in the room.
   */
  bool talk(Villager*, Room**);

  /**
   *This function gives all the commands that you can use during the game and messages related with
   *messages that the hero will received every when asked for.
   */
  bool command(std::string, Room**);


  /**
   * This function interact giving the state of the objects in the rooms.
   */
  bool interact(RoomObject* const);

  /**
   *This function gives the conditions in which the game will be over.
   */
  void lose(GitGud, Room**);

  /**
   *This function gives message when the Hero wins the game.
   */
  void win(Room**);
  void reset();
  /**
   *This function contains the file to help he player from any room.
   */
  void help();

  /**
   *@param inventory  gives the status of the inventory.
   *@param weaponOfChoice give the weapon selected.
   *@param pos give the position of the Hero
   *@param refs to actions that ake place during the game.
   *@param cref these are the references for the the actions used in the commands.
   */


 private:
  void setRef();
  void setCommand();
  std::map<int, std::pair<Item*, int>> inventory;
  Item* weaponOfChoice;
  std::pair<uint, uint> pos;
  std::map<std::string, int> refs;
  std::map<std::string, Command> cRefs;
};

#endif // HERO_H

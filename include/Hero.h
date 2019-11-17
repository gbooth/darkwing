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
   *@param identifier of the Hero and his position.
   */
  Hero();

  /**
  *Default destructor.
   */
  virtual ~Hero();

  /**
   *This function define the npc by the hero.
   * @param represent the npc with be related with the hero.
   */
  void attack(Person*, Room**);

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
  *This function will give the direction and the position of the hero.
  *@param a will give the direction of the hero.
  *@param world give the room position.
  */
  void mv(Direction, Room**);

  /**
   *This function gives you the position of the hero.
   * @param pair for the coordinates of the hero.
   * @throw "ERROR: position out of bounds" if the firs and second position is > 4.
   */
  void setPosition(std::pair<unsigned int, unsigned int>);

  /**
   *this function access the position of the player.
   * return the position of the player.
   */
  std::pair<unsigned int, unsigned int> getPos();

  /**
   *@param map will associate the item with the identifier in the inventory.
   *@param weaponOfChoice provides the identifier of the weapons.
   *@param pos will give the coordinates of the position of the hero.
   */
  std::list<std::pair<int, int>> invSave();
  void getInventory();
  void addInventory(Item*);
  void usePotion(Item*);
  void useKey(Item*, Lock*);
  void talk(Villager*, Room**);
  void command(std::string, Room**);
  bool interact(RoomObject* const);
  void lose(GitGud, Room**);
  void win(Room**);
  void help();
 private:
  void setRef();
  void setCommand();
  std::map<int, std::pair<Item*, int>>  inventory;
  Item* weaponOfChoice;
  std::pair<uint, uint> pos;
  std::map<std::string, int> refs;
  std::map<std::string, Command> cRefs;
};

#endif // HERO_H

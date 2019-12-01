/**
 *@author  Wesley Waldern
 *@date  2019-11
 */

#ifndef HERO_H
#define HERO_H

#include "Person.h"
#include "RoomObject.h"
#include "Villager.h"
#include "Command.h"
#include "Save.h"
#include "GitGud.h"
#include "Direction.h"
#include "Room.h"
#include "Item.h"
#include <string>
#include <map>
#include <list>
#include <utility>
#include <vector>

/**
 *The player and his/her assorted characteristics: Weapons,Enemy identifier,position,
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
   *This function defines the npc by the hero.
   *@return true
   */
  bool attack(Person*, Room**);

  /**
   * @param a the object to inspect
   * @return the description of the object.
   */
  std::string inspect(Object* a);

  /**getter method for weapon
   * @return weaponOfChoice.
   */
  Item* getWeapon();

  /**
   * @param a the item to set as weapon of choice
   * @return the weapon of choice.
   */
  void setWeapon(Item* a);

  /**
  *This function will gives the direction and the position of the hero.
  * @param d the direction to move
  * @param w the world which you moving in
  */
  void mv(Direction d, Room** w);

  /**
   *This function gives you the position of the hero.
   * @param c the coordinate of the player
   * @throw "ERROR: position out of bounds" if x or y is > 4.
   */
  void setPosition(std::pair<unsigned int, unsigned int> c);

  /**
   * gets the position of the player.
   * @return pos
   */
  std::pair<unsigned int, unsigned int> getPos();

  /**
   *used by save to save the inventory
   */
  std::vector<std::pair<int, int>> invSave();

  /**
   *prints inventory to screen.
   */
  void getInventory();

  /**
   *adds an item to inventory
   * @param a the item* to add
   * @param b flag to ensure you add item to inv.
   */
  void addInventory(Item* a, bool b);

  /**
   * This function give you the health when using potions.
   * @param i the potion that you use
   */
  void usePotion(Item* i);

  /**
   *This function unlock when using the right key.
   * @param i the key to use
   * @param l the lock to use the key on
   */
  void useKey(Item* i, Lock* l);

  /**
   *This function let you know to talk with the Villager whe you are in the room.
   *@param v the villager pointer to talk to
   *@param r the world which the villager is in
   *@return true.
   */
  bool talk(Villager* v, Room** r);

  /**
   *parses the player commands during gameplay
   *@param s the string to interpret as commands for the hero
   *@param r the world containing the hero
   *@return true.
   */
  bool command(std::string s, Room** r);

  /**
   * This function interact giving the state of the objects in the rooms.
   *@param r the immutable RoomObject* to interact with
   *@return true.
   */
  bool interact(RoomObject* const r);

  /**
   *This function gives the conditions in which the game will be over.
   *@param g the condition for losing
   *@param r the world containing the hero
   */
  void lose(GitGud g, Room** r);

  /**
   *This function gives message when the Hero wins the game.
   *@param r the world containing the hero
   */
  void win(Room** r);

  /**
   *resets all of the data attributes of the hero to default state
   */
  void reset();

  /**
   *Outputs the help menu to the terminal
   */
  void help();

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

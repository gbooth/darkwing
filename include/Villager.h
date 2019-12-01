/**
 *@author Ben Hunt
 *@date 2019-11
 */

#ifndef VILLAGER_H
#define VILLAGER_H

#include "Person.h"

/**
 *This function gives the identification for the Villagers.
 */

class Villager : public Person {
 public:
  /**
  *Default Constructor
  * @param idnty the identifier of the villager
  * @throw invalid_id error "ERROR:not a villager"
  */
  Villager(int idnty);

  /**
  * destructor
  */
  virtual ~Villager();

  /**
  *It does nothing; implemented in Hero and enemy
  *@param npc the pointer to the person to attack
  *@param r the world that the person's are in
  *@return false.
  */
  bool attack(Person* npc, Room** r);

  /**
  * Related with the talking aspect of a villager
  */
  void response();

  /**
   *it will give a riddle
   *@return true.
   */
  bool riddle();
};

#endif // VILLAGER_H

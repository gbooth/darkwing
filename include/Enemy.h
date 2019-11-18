/**
 *@author  Ben Hunt
 *@date 2019-11
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Person.h"
#include "Hero.h"
#include <utility>

/**
 *This class will define all the characteristics of the Enemy during the game.
 */

class Enemy : public Person {
 public:
  /**
  *constructor
  * @param id is enemy identifier
  */
  Enemy(int id);

  /**
  * destructor
  */
  virtual ~Enemy();

  /**
  *@param h person to attack.
  *@param world array for the world to call lose function with
  *@return false.
  */
  bool attack(Person* h, Room** world);
};

#endif // ENEMY_H

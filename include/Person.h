/**
*@author Jorge Aceytuno
*@date 2019-11
*/
#ifndef PERSON_H
#define PERSON_H
#include "Object.h"
#include <utility>

/**
 *This class is derived of the Object class and will provide the person identifier,
 *set the health of the player and will give the damageValue during the game.
 */
class Person : public Object {
 public:

  /**
  * Constructor
  * @parameter id the identifer of the person.
  * @parameter damageVal the damage value of the person.
  * @parameter hp the health of the person.
  * @throw throw an error if id doesn't match a  person.
  */
  Person(int id);

  /**
  *default Destructor
  */
  virtual ~Person();

  /**
  *  Attack is a pure virtual method to be used for the Enemies and the Hero.
  */
  virtual void attack (Person* npc) = 0;

  /**
  *set health of the person.
  */
  void setHealth(int);

  /**
  *@return health of the person.
  */
  int getHealth();

  /**
  *set damage of the person.
  */
  void setDamage(int);

  /**
  *@return damage of the person.
  */
  int getDamage()const;

  /**
   *@parameter health will give the health points for the person.
   *@parameter damageValue will give the damage for the person during the game.
   */
 protected:
  int health;
  int damageValue;
};

#endif // PERSON_H

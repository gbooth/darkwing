/**
*@author Jorge Aceytuno id 001003732
*@date 2019-10-31
*/
#ifndef PERSON_H
#define PERSON_H

#include "Object.h"
#include <utility>

class Person : public Object {
 public:

  /**
  * Constructor
  * @param id the identifer of the person
  * @param damageVal the damage value of the person
  * @param pos the position of the person
  * @param hp the health of the person
  * @throw throw an error if id doesn't match a person
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
  *set health of character
  */
  void setHealth(int);

  /**
  *@return health of character
  */
  int getHealth();

  /**
  *set damage of character
  */
  void setDamage(int);

  /**
  *@return damage of character
  */
  int getDamage()const;

 protected:
  int health;
  int damageValue;
};

#endif // PERSON_H

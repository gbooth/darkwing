/**
*@author Jorge Aceytuno
*@date 2019-11
*/
#ifndef PERSON_H
#define PERSON_H
#include "Object.h"
#include "Room.h"
#include <utility>

class Room;

/**
 *This class is derived of the Object class and will provide the person identifier,
 *set the health of the player and will give the damageValue during the game.
 */
class Person : public Object {
 public:
  /**
  * Default Constructor
  *@param id gives the identifier for a person.
  */
  Person(int id);

  /**
  *default Destructor
  */
  virtual ~Person();

  /**
  *  Attack is a pure virtual method to be used for the Enemies and the Hero.
  *@param npc gives the identification of the npc.
  *@param world gives the room position for the npc.
  */
  virtual bool attack(Person* npc, Room** world) = 0;

  /**
  *set health of the person.
  */
  void setHealth(int);

  /**
  *@return health of the person.
  */
  int getHealth();

  /**
  *set the damage value of the person.
  */
  void setDamage(int);

  /**
  *@return damageValue of the person.
  */
  int getDamage()const;

  /**
  *These variablesn give the health and damage to the Hero.
  *@param health will give the health points for the person.
  *@param damageValue will give the damage for the person during the game
  */
 protected:
  int health;
  int damageValue;
};

#endif // PERSON_H

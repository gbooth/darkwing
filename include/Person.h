/**
*@author Jorge Aceytuno id 001003732
*@date 2019-10-31
*/
#ifndef PERSON_H
#define PERSON_H


#include "Object.h"
#include <utility>
/**
*This class is the declaration for Persons that will be included in the game  in the
*game CastleScape.
*/

class Person : public Object {
 public:
  /**The Persons,Villagers and the Enemies will be describe when the whole rooms are defined.
  *also the decision if the Villagers and Enemies will be identified in the classes Vil*age*r and Enemy or create one specific class for Identifiers.
  */

  /** The constructor behavior is to create a Person ,in this case because the class is abstract, we can not intanciate a Person object.g
   *@parameters for identification and position of the Person .
  */
  Person(int, int damageVal, std::pair<int, int> pos , int hp = 10);

  /**
   *  Attack is a pure virtual method to be used for the Enemies and the Hero.
   */

  virtual int Attack ()=0;

  /**
  *default Destructor
  */
  virtual ~Person();

 protected:
  std::pair<int, int>position;
  int health;
  int damageValue;

 private:
};

#endif // PERSON_H

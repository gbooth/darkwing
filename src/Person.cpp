/**author  Jorge Aceytuno id : 001003732
 * @date 2019 -11-05
 */

#include "Person.h"
#include "utility"
#include "Exceptions.h"
#include "Object.h"

/** this is an abstract class then there is no creation of objects
 */

Person::Person(int id, int damageVal, std::pair<int, int>pos, int hp)
: Object{id}, damageValue{damageVal}, position{pos}, health{hp} {}
/**
*destructor function.
*/
Person::~Person() {}

/**
*the function attack is a pure virtual function
*/

/**
*this implementation set  anytime the position for the player.
*/
void Person::setPosition (std::pair<int, int> pos) {
  position = pos;
}
/** This function gives the position for the player.
 */

std::pair<int, int> Person::getPos() {
  return position;
}
/** This method set the health for the player anytime.
 */

void Person::setHealth(int hp) {
  health=hp;
}
/** This method return the health of the player anytime.
 */
int Person::getHealth () {
  return health;
}
/** This function give the damage caused when losing point in the game.
 */
void Person::setDamage(int damValue) {
}

/** This method give you the damage value in real time for the player.
 */
int Person::getDamage()const {
  return damageValue;
}




/**author  Jorge Aceytuno id : 001003732
 * @date 2019 -11-05
 */

#include "Person.h"
#include <utility>
#include "Exceptions.h"

Person::Person(int id, int damageVal, std::pair<uint, uint>pos, int hp)
: Object{id}, damageValue{damageVal}, position{pos}, health{hp} {
  if(id /1000 != 3 || id < 3000 || id > 3399)
    throw invalid_id("ERROR: this ID does not describe a person");
}

Person::~Person() {}

void Person::setPosition (std::pair<uint, uint> pos) {
  if(pos.first > 4  || pos.second > 4)
    throw invalid_pos("ERROR: position out of bounds");
  position = pos;
}

std::pair<uint, uint> Person::getPos() {
  return position;
}

void Person::setHealth(int hp) {
  health=hp;
}

int Person::getHealth () {
  return health;
}

void Person::setDamage(int damValue) {
  damageValue = damValue;
}

int Person::getDamage()const {
  return damageValue;
}




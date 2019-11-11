#ifndef ENEMY_H
#define ENEMY_H

#include "Person.h"
#include "Hero.h"
#include <utility>


class Enemy : public Person {
 public:
  /**
  *constructor
  * @param id is enemy identifier
  * @param dmg is damage value
  * @param pos the position
  * @param hp the health
  * @throw if id is not of enemy type
  */
  Enemy(int id);

  /**
  * destructor
  */
  virtual ~Enemy();

  /**
  * @param the hero to attack
  */
  void attack(Person* h);

 protected:

 private:
};

#endif // ENEMY_H

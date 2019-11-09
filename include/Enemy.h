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
  Enemy(int id, int dmg = 2, std::pair<int, int>pos = std::make_pair(3,3), int hp = 10);

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

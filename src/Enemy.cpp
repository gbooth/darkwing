/**
 *@autor Ben Hunt
 *@date 2019-11
 */

#include "Enemy.h"
#include "Exceptions.h"
#include <iostream>

Enemy::Enemy(int id)
  :Person{id} {
  if (id/100%10 != 3 || id < 3301)
    throw invalid_id("ERROR: id does not describe an enemy");
}

Enemy::~Enemy() {}

bool Enemy::attack(Person* hero, Room** world) {
  std::cout << "I'll crush you Duck Norris" << std::endl;
  int heroHp = hero->getHealth() - this->damageValue;
  std::cout << "You take " << damageValue << " points of damage." << std::endl;
  hero->setHealth(heroHp);
  std::cout << "your health is now " << hero->getHealth() << "." << std::endl;
  return false;
}

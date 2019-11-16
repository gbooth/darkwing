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

void Enemy::attack(Person* hero) {
  std::cout << "I'll crush you Duck Norris" << std::endl;
  int heroHp = hero->getHealth() - this->damageValue;
  hero->setHealth(heroHp);
  if (hero->getHealth() < 1)
    std::cout << "you died" << std::endl;
  else
    std::cout << "your health is now " << hero->getHealth() << "." << std::endl;
}

#include "Enemy.h"
#include "Hero.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestEnemy, ctorTest) {
  Enemy r(3301);
  EXPECT_EQ(7, r.getHealth());
  EXPECT_EQ(2, r.getDamage());
}

TEST(TestEnemy, attackTest) {
  Room** world;
  world = new Room*[5];
  for (int i = 0; i < 5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  Hero* a = new Hero;
  EXPECT_EQ(20, a->getHealth());
  Enemy e(3301);
  e.attack(a, world);
  EXPECT_EQ(18, a->getHealth());
  delete a;
  a = nullptr;
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete [] world;
  world = nullptr;
}

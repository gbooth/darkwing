#include "Enemy.h"
#include "Hero.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestEnemy, ctorTest) {
  Enemy r(3301);
  EXPECT_EQ(10, r.getHealth());
  EXPECT_EQ(2, r.getDamage());
}

TEST(TestEnemy, attackTest) {
  Hero a;
  EXPECT_EQ(10, a.getHealth());
  Enemy e(3301);
  e.attack(&a);
  EXPECT_EQ(8, a.getHealth());
}

#include "Enemy.h"
#include "Hero.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestEnemy, ctorTest) {
  Enemy r(3301);
  std::pair<uint, uint> ps = std::make_pair(3, 3);
  EXPECT_THROW(Enemy e(3300, 1, std::make_pair(1, 1), 10), invalid_id);
  EXPECT_NO_THROW(Enemy e(3301, 1, std::make_pair(1, 1), 10));
  EXPECT_EQ(2, r.getDamage());
  EXPECT_EQ(ps, r.getPos());
  EXPECT_EQ(10, r.getHealth());
  EXPECT_EQ(3301, r.getID());
}
TEST(TestEnemy, setPosTest) {
  Enemy r(3301);
  std::pair<uint, uint> ps = std::make_pair(3, 4);
  EXPECT_NO_THROW(r.setPosition(ps));
  std::pair<uint, uint> pv = std::make_pair(6, 7);
  std::pair<uint, uint> p1 = std::make_pair(6, 2);
  std::pair<uint, uint> p2 = std::make_pair(1, 7);
  EXPECT_THROW(r.setPosition(pv), invalid_pos);
  EXPECT_THROW(r.setPosition(p1), invalid_pos);
  EXPECT_THROW(r.setPosition(p2), invalid_pos);
}

TEST(TestEnemy, getPosTest){
  Enemy r(3301);
  std::pair<uint, uint> p1 = std::make_pair(3,3);
  EXPECT_EQ(p1, r.getPos());
}

TEST(TestEnemy, attackTest) {
  Hero a(3101, 1, std::make_pair(0, 0), 10);
  EXPECT_EQ(10, a.getHealth());
  Enemy e(3301);
  e.attack(&a);
  EXPECT_EQ(8, a.getHealth());
}

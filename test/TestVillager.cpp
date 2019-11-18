#include "Villager.h"
#include "Exceptions.h"
#include <sstream>
#include "gtest/gtest.h"

TEST(TestVillager, ctorTest) {
  EXPECT_THROW(Villager v(3306), invalid_id);
  EXPECT_NO_THROW(Villager a(3201));
}

TEST(TestVillager, responseTest) {
  Villager a(3201);
  a.response();
  Villager b(3202);
  b.response();
  Villager c(3203);
  c.response();
  Villager d(3204);
  d.response();
  Villager e(3205);
  e.response();
  Villager f(3206);
  f.response();
  Villager g(3207);
  g.response();
  Villager h(3208);
  h.response();
  Villager i(3209);
  i.response();
  Villager j(3210);
  j.response();
}

TEST(TestVillager, riddleTest) {
  Villager v(3208);
  std::streambuf *backup;
  std::istringstream oss("chuck norris");
  backup = std::cin.rdbuf();
  std::cin.rdbuf(oss.rdbuf());
  v.riddle();
}

TEST(TestVillager, attackTest) {
  Room** world;
  world = new Room*[5];
  for (int i = 0; i < 5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  Villager* p = new Villager(3210);
  EXPECT_EQ(10, p->getHealth());
  Villager v(3208);
  v.setDamage(0);
  v.attack(p, world);
  EXPECT_EQ(10, p->getHealth());
  delete p;
  p = nullptr;
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete [] world;
  world = nullptr;
}

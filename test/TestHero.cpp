#include "Hero.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(TestHero, inspectTest) {
  Object a(4205);
  Hero h;
  std::cout << h.inspect(&a) << std::endl;
}

TEST(TestHero, mvTest) {
  Hero h;
  Room** world;
  world = new Room*[5];
  for (int i = 0; i<5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  h.mv(east, world);
  EXPECT_EQ(1, h.getPos().first);
  EXPECT_EQ(0, h.getPos().second);
}

TEST(TestHero, inventoryTest) {
  Item a(4203);
  Item b(4101);
  Item c(4301);
  Hero h;
  h.addInventory(&a);
  h.addInventory(&b);
  h.addInventory(&b);
  h.addInventory(&b);
  h.addInventory(&b);
  h.addInventory(&c);
  h.getInventory();
}

TEST(TestHero, usePotionTest) {
  Hero h;
  Item b(4101);
  Item c(4102);
  h.setHealth(8);
  h.usePotion(&b);
  std::cout << h.getHealth() << std::endl;
  h.setHealth(5);
  h.usePotion(&c);
  std::cout << h.getHealth() << std::endl;
  h.setHealth(10);
  h.usePotion(&c);
  std::cout << h.getHealth() << std::endl;
}

TEST(TestHero, weaponTest) {
  Item a(4205);
  Hero h;
  h.addInventory(&a);
  h.setWeapon(&a);
  std::cout << h.getWeapon()->getName() << std::endl;
}

TEST(TestHero, talkTest){
Hero h;
Villager v(3207);
h.talk(&v);
}

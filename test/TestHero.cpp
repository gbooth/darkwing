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
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete world;
  world = nullptr;
}

TEST(TestHero, inventoryTest) {
  Item* a = new Item(4203);
  Item* b = new Item(4101);
  Item* c = new Item(4301);
  Hero h;
  h.addInventory(a);
  h.addInventory(b);
  h.addInventory(b);
  h.addInventory(b);
  h.addInventory(b);
  h.addInventory(c);
  h.getInventory();
}

TEST(TestHero, usePotionTest) {
  Hero h;
  Item* b = new Item(4101);
  Item* c = new Item(4102);
  h.setHealth(8);
  h.usePotion(b);
  std::cout << h.getHealth() << std::endl;
  h.setHealth(5);
  h.usePotion(c);
  std::cout << h.getHealth() << std::endl;
  h.setHealth(10);
  h.usePotion(c);
  std::cout << h.getHealth() << std::endl;
  delete b;
  delete c;
  b = nullptr;
  c = nullptr;
}

TEST(TestHero, weaponTest) {
  Item* a = new Item(4205);
  Hero h;
  h.addInventory(a);
  h.setWeapon(a);
  std::cout << h.getWeapon()->getName() << std::endl;
  delete a;
  a = nullptr;
}

TEST(TestHero, talkTest) {
  Hero h;
  Villager v(3207);
  Room** world;
  world = new Room*[5];
  for (int i = 0; i<5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  h.talk(&v, world);
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete world;
  world = nullptr;
}

TEST(TestHero, useKeyTest) {
  Hero h;
  Lock* l = new Lock(2201);
  Lock* m = new Lock(2202);
  Item* a = new Item(4301);
  h.useKey(a, l);
  h.useKey(a, m);
  delete l;
  delete m;
  delete a;
  l = nullptr;
  m = nullptr;
  a = nullptr;
}

TEST(TestHero, interactTest) {
  Hero h;
  RoomObject* r = new Lever(2302);
  RoomObject* s = new Chest(2101);
  h.interact(r);
  h.interact(s);
  delete r;
  delete s;
  r = nullptr;
  s = nullptr;
}

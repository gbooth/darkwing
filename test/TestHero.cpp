#include "Hero.h"
#include "Exceptions.h"
#include <utility>
#include "gtest/gtest.h"

TEST(TestHero, inspectTest) {
  Object a(4205);
  Hero h;
  std::cout << h.inspect(&a) << std::endl;
}

TEST(TestHero, mvTest) {
  Hero h;
  Room** world;
  world = new Room*[5];
  for (int i = 0; i < 5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  h.mv(east, world);
  EXPECT_EQ(1, h.getPos().first);
  EXPECT_EQ(0, h.getPos().second);
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete [] world;
  world = nullptr;
}

TEST(TestHero, inventoryTest) {
  Item* a = new Item(4203);
  Item* b = new Item(4101);
  Item* c = new Item(4301);
  Hero h;
  h.addInventory(a, true);
  h.addInventory(b, true);
  h.addInventory(c, true);
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
  h.addInventory(a, true);
  h.setWeapon(a);
  std::cout << h.getWeapon()->getName() << std::endl;
  delete a;
  a = nullptr;
}

TEST(TestHero, talkTest) {
  Hero h;
  Villager v(3207);
  Villager w(3208);
  std::streambuf *backup;
  std::istringstream oss("chuck norris");
  backup = std::cin.rdbuf();
  std::cin.rdbuf(oss.rdbuf());
  Room** world;
  world = new Room*[5];
  for (int i = 0; i < 5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  h.talk(&v, world);
  h.talk(&w, world);
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete [] world;
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
  RoomObject* l = new Lock(2201);
  RoomObject* r = new Lever(2302);
  RoomObject* s = new Chest(2101);
  EXPECT_TRUE(h.interact(r));
  EXPECT_TRUE(h.interact(s));
  EXPECT_FALSE(h.interact(l));
  delete r;
  delete s;
  delete l;
  l = nullptr;
  r = nullptr;
  s = nullptr;
}

TEST(TestHero, HelpTest) {
  Hero h;
  h.help();
}

TEST(TestHero, loseTest) {
  Hero h;
  Room** world = nullptr;
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  h.lose(riddle, world);
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  h.lose(ducked, world);
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  h.lose(moronUser, world);
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  h.lose(stalactite, world);
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  h.lose(jail, world);
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  h.lose(friends, world);
}

TEST(TestHero, win) {
  Hero h;
  Room** world = nullptr;
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  h.win(world);
}

TEST(TestHero, commandTest) {
  Hero h;
  std::streambuf *backup;
  std::istringstream oss("chuck norris");
  std::istringstream  sv("save");
  std::cin.rdbuf(sv.rdbuf());
  backup = std::cin.rdbuf();
  std::cin.rdbuf(oss.rdbuf());
  Room** world = nullptr;
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i]= new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  Lever* bridge1 = static_cast<Lever*>(world[0][4].getObj(2305));
  Lever* bridge2 = static_cast<Lever*>(world[0][3].getObj(2306));
  Lever* bridge3 = static_cast<Lever*>(world[1][3].getObj(2302));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      world[i][j].setDoor(world);
      if (world[i][j].getID() == 1005) {
        Lever* bridgeLever = static_cast<Lever*>(world[i][j].getObj(2301));
        bridgeLever->setDepLever(std::make_pair(bridge1, false));
        bridgeLever->setDepLever(std::make_pair(bridge2, true));
        bridgeLever->setDepLever(std::make_pair(bridge3, true));
      }
    }
  }
  Item* key1 = new Item(4301);
  Item* key2 = new Item(4302);
  Item* hpPot = new Item(4101);
  h.command("go north", world);
  h.command("go east", world);
  h.setHealth(4);
  h.command("use major health potion", world);
  h.command("attack small chest", world);
  h.command("open small chest", world);
  h.command("open small chest", world);
  h.command("open spikey chest", world);
  h.command("inspect room", world);
  h.command("talk quackie chan", world);
  h.command("talk bob", world);
  h.command("talk james pond", world);
  h.command("inventory", world);
  h.command("talk king eider", world);
  h.command("go north", world);
  h.command("go west", world);
  h.command("go south", world);
  h.command("go north", world);
  h.command("open spikey chest", world);
  h.command("inspect spikey chest", world);
  h.command("go south", world);
  h.command("talk king eider", world);
  h.command("equip", world);
  h.command("equip dagger", world);
  h.command("help", world);
  h.command("use forest map", world);
  h.command("attack Duck rogers", world);
  h.command("inspect gizmoduck", world);
  h.command("inspect dagger", world);
  h.command("inspect barb", world);
  h.command("hello", world);
  h.command("go esat", world);
  h.command("inspect king eider", world);
  h.setPosition(std::make_pair(2, 0));
  h.command("inspect room", world);
  h.command("talk sirius quack", world);
  std::cin.clear();
  h.setPosition(std::make_pair(3, 1));
  h.command("go east", world);
  h.command("use forest map", world);
  h.setPosition(std::make_pair(3, 0));
  h.command("use blue key", world);
  h.command("use orange key", world);
  h.command("attack quacker jack", world);
  h.command("attack quacker jack", world);
  h.setPosition(std::make_pair(3, 3));
  h.command("flip cram lever", world);
  h.command("flip dagger", world);
  h.command("go south", world);
  h.command("flip stone lever", world);
  h.setPosition(std::make_pair(4, 3));
  h.command("flip mossy lever", world);
  h.command("use forest map", world);
  h.command("use blue key", world);
  h.command("use orange key", world);
  h.addInventory(key1, true);
  h.addInventory(key2, true);
  h.addInventory(hpPot, true);
  h.command("inventory", world);
  h.setPosition(std::make_pair(0, 2));
  h.command("use orange key", world);
  h.setPosition(std::make_pair(2, 3));
  h.command("use blue key", world);
  h.command("use orange key", world);
  h.command("save", world);
  h.setPosition(std::make_pair(3, 2));
  h.command("go west", world);
  h.setPosition(std::make_pair(2, 3));
  h.command("flip bone lever", world);
  h.setPosition(std::make_pair(0, 3));
  h.command("flip flimsy lever", world);
  h.setPosition(std::make_pair(1, 3));
  h.command("flip gold lever", world);
  h.setPosition(std::make_pair(4, 0));
  h.command("flip stone lever", world);
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete [] world;
  world = nullptr;
}

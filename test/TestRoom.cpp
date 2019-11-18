/**
* @author Gavin Booth <g.booth@uleth.ca>
* @date Nov. 2019
*/
#include "Room.h"
#include "Exceptions.h"
#include <utility>
#include <list>
#include <string>
#include "gtest/gtest.h"

TEST(TestRoom, CtorTest) {
  EXPECT_NO_THROW(Room wizardsRoom(1001));
  EXPECT_THROW(Room temp(2000), invalid_id);
}

TEST(TestRoom, CheckEnemy) {
  Room wizardsRoom(1001);
  Room duckThrone(1012);
  EXPECT_FALSE(wizardsRoom.checkForEnemy());
  EXPECT_TRUE(duckThrone.checkForEnemy());
}

TEST(TestRoom, CheckNPC) {
  Room wizardsRoom(1001);
  Room throneRoom(1002);
  Room duckAnteChamber(1011);

  EXPECT_FALSE(wizardsRoom.checkForNPC(3208));
  EXPECT_FALSE(throneRoom.checkForNPC(3208));
  EXPECT_TRUE(throneRoom.checkForNPC(3201));
  EXPECT_TRUE(throneRoom.checkForNPC(3202));
  EXPECT_TRUE(throneRoom.checkForNPC(3203));
  EXPECT_TRUE(duckAnteChamber.checkForNPC(3303));
  EXPECT_THROW(wizardsRoom.checkForNPC(4101), invalid_id);
  EXPECT_THROW(throneRoom.checkForNPC(1001), invalid_id);
  EXPECT_THROW(duckAnteChamber.checkForNPC(2101), invalid_id);
}

TEST(TestRoom, checkObj) {
  Room undergroundLake(1005);
  Room quartz(1016);
  Room field(1008);

  EXPECT_FALSE(undergroundLake.checkForObj(2302));
  EXPECT_TRUE(undergroundLake.checkForObj(2301));
  EXPECT_THROW(undergroundLake.checkForObj(3301), invalid_id);

  EXPECT_FALSE(quartz.checkForObj(2301));
  EXPECT_TRUE(quartz.checkForObj(2306));
  EXPECT_TRUE(quartz.checkForObj(2104));
  EXPECT_THROW(quartz.checkForObj(1007), invalid_id);

  EXPECT_FALSE(field.checkForObj(2301));
  EXPECT_FALSE(field.checkForObj(2306));
  EXPECT_THROW(field.checkForObj(1006), invalid_id);
}

TEST(TestRoom, getDir) {
  Room** world = nullptr;
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  Lever* bridge1 = static_cast<Lever*>(world[0][4].getObj(2305));
  Lever* bridge2 = static_cast<Lever*>(world[0][3].getObj(2306));
  Lever* bridge3 = static_cast<Lever*>(world[1][3].getObj(2302));
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      world[i][j].setDoor(world);
      if (world[i][j].getID() == 1005) {
        Lever* bridgeLever = static_cast<Lever*>(world[i][j].getObj(2301));
        bridgeLever->setDepLever(std::make_pair(bridge1, false));
        bridgeLever->setDepLever(std::make_pair(bridge2, true));
        bridgeLever->setDepLever(std::make_pair(bridge3, true));
      }
    }
//  Room field = world[2][1];
//  Room forest = world[3][1];
//  Room undergroundRiver = world[2][3];
//  Room bridge = world[1][4];
  Direction dir = north;
  EXPECT_EQ(std::make_pair(2, 0), world[2][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(3, 1), world[3][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(0, -2), world[2][3].getDirection(dir));
  dir = static_cast<Direction>(dir + 1);
  EXPECT_EQ(std::make_pair(2, 2), world[2][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(3, 1), world[3][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(4, 0), world[2][3].getDirection(dir));
  dir = static_cast<Direction>(dir + 1);
  EXPECT_EQ(std::make_pair(3, 1), world[2][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(0, -2), world[3][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(-1, -1), world[2][3].getDirection(dir));
  EXPECT_EQ(std::make_pair(0, -1), world[1][4].getDirection(dir));
  dir = static_cast<Direction>(dir + 1);
  EXPECT_EQ(std::make_pair(1, 1), world[2][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(2, 1), world[3][1].getDirection(dir));
  EXPECT_EQ(std::make_pair(-1, -1), world[2][3].getDirection(dir));
  for (int i = 0; i < 5; i++)
    delete[] world[i];
  delete [] world;
  world = nullptr;
}

TEST(TestRoom, objChange) {
  Room field(1008);
  Room quartz(1016);
  Room undergroundLake(1005);
  EXPECT_THROW(field.objChanged(1008), invalid_id);
  EXPECT_THROW(field.objChanged(2101), invalid_id);
  EXPECT_NO_THROW(quartz.objChanged(2306));
  EXPECT_NO_THROW(quartz.objChanged(2104));
  EXPECT_THROW(quartz.objChanged(2301), invalid_id);
  EXPECT_NO_THROW(undergroundLake.objChanged(2301));
}

TEST(TestRoom, getMessage) {
  Room wizardsTower(1001);
  Room quartz(1016);
  Room stalagmite(1019);
  std::string s = "cave. This chamber sparkles with Quartz ";
  std::string t = "crystals that seem to have sprouted from every wall.";
  std::string u = "cave. This chamber has large Stalagmites ";
  std::string y = "yet no stalactites, how strange.";
  EXPECT_EQ("Wizard’s Tower.", wizardsTower.getMessage());
  EXPECT_EQ(s + t, quartz.getMessage());
  EXPECT_EQ(u + y, stalagmite.getMessage());
}

TEST(TestRoom, objToSave) {
  Room quartz(1016);
  Room undergroundRiver(1018);
  std::list<int> savingObjA, savingObjB;
  quartz.objChanged(2306);
  quartz.objChanged(2104);
  quartz.objChanged(2306);
  quartz.objChanged(2104);
  quartz.objChanged(2306);
  quartz.objChanged(2104);
  quartz.objChanged(2306);
  quartz.objChanged(2104);
  savingObjA.push_back(2104);
  savingObjA.push_back(2306);
  EXPECT_EQ(savingObjA, quartz.objToSave());
  undergroundRiver.objChanged(2303);
  undergroundRiver.objChanged(2202);
  undergroundRiver.objChanged(2303);
  undergroundRiver.objChanged(2202);
  undergroundRiver.objChanged(2303);
  undergroundRiver.objChanged(2202);
  undergroundRiver.objChanged(2303);
  undergroundRiver.objChanged(2202);
  undergroundRiver.objChanged(2303);
  undergroundRiver.objChanged(2202);
  savingObjB.push_back(2202);
  savingObjB.push_back(2303);
  EXPECT_EQ(savingObjB, undergroundRiver.objToSave());
}

TEST(TestRoom, setHasEnemy) {
  Room a(1012);
  EXPECT_TRUE(a.checkForEnemy());
  a.setHasEnemy();
  EXPECT_FALSE(a.checkForEnemy());
}

TEST(TestRoom, getNPC) {
  Room a(1012);
  Person* const ptr = a.getNPC(3305);
  Person* const ptr2 = a.getNPC(3304);
  EXPECT_EQ(nullptr, ptr2);
  EXPECT_EQ("firequacker", ptr->getName());
}

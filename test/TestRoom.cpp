/**
* @author Gavin Booth <g.booth@uleth.ca>
* @date Nov. 2019
*/
#include "Room.h"
#include "Exceptions.h"
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
  EXPECT_TRUE(quartz.checkForObj(2102));
  EXPECT_THROW(quartz.checkForObj(1007), invalid_id);

  EXPECT_FALSE(field.checkForObj(2301));
  EXPECT_FALSE(field.checkForObj(2306));
  EXPECT_THROW(field.checkForObj(1006), invalid_id);
}

TEST(TestRoom, getDir) {
  Room field(1008);
  Room forest(1009);
  Room undergroundRiver(1018);
  Room bridge(1022);

  Direction dir = north;
  EXPECT_EQ(std::make_pair(2, 0), field.getDirection(dir));
  EXPECT_EQ(std::make_pair(-1, -1), forest.getDirection(dir));
  EXPECT_EQ(std::make_pair(0, -2), undergroundRiver.getDirection(dir));

  dir = static_cast<Direction>(dir + 1);
  EXPECT_EQ(std::make_pair(2, 2), field.getDirection(dir));
  EXPECT_EQ(std::make_pair(-1, -1), forest.getDirection(dir));
  EXPECT_EQ(std::make_pair(4, 0), undergroundRiver.getDirection(dir));

  dir = static_cast<Direction>(dir + 1);
  EXPECT_EQ(std::make_pair(3, 1), field.getDirection(dir));
  EXPECT_EQ(std::make_pair(0, -2), forest.getDirection(dir));
  EXPECT_EQ(std::make_pair(-1, -1), undergroundRiver.getDirection(dir));
  EXPECT_EQ(std::make_pair(0, -1), bridge.getDirection(dir));

  dir = static_cast<Direction>(dir + 1);
  EXPECT_EQ(std::make_pair(1, 1), field.getDirection(dir));
  EXPECT_EQ(std::make_pair(2, 1), forest.getDirection(dir));
  EXPECT_EQ(std::make_pair(-1, -1), undergroundRiver.getDirection(dir));
}

TEST(TestRoom, objChange) {
  Room field(1008);
  Room quartz(1016);
  Room undergroundLake(1005);

  EXPECT_THROW(field.objChanged(1008), invalid_id);
  EXPECT_THROW(field.objChanged(2101), invalid_id);
  EXPECT_NO_THROW(quartz.objChanged(2306));
  EXPECT_NO_THROW(quartz.objChanged(2102));
  EXPECT_THROW(quartz.objChanged(2301), invalid_id);

  EXPECT_NO_THROW(undergroundLake.objChanged(2301));
}

TEST(TestRoom, getMessage) {
  Room wizardsTower(1001);
  Room quartz(1016);
  Room stalagmite(1019);

  EXPECT_EQ("Wizard’s Tower.", wizardsTower.getMessage());
  EXPECT_EQ("cave. This chamber sparkles with Quartz crystals that seem to have sprouted from every wall.",
            quartz.getMessage());
  EXPECT_EQ("cave. This chamber has large Stalagmites yet no stalactites, how strange.",
            stalagmite.getMessage());
}

TEST(TestRoom, objToSave) {
  Room quartz(1016);
  Room undergroundRiver(1018);

  std::list<int> savingObjA, savingObjB;
  quartz.objChanged(2306);
  quartz.objChanged(2102);
  quartz.objChanged(2306);
  quartz.objChanged(2102);
  quartz.objChanged(2306);
  quartz.objChanged(2102);
  quartz.objChanged(2306);
  quartz.objChanged(2102);
  savingObjA.push_back(2102);
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

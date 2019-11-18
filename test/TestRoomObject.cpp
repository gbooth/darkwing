#include "RoomObject.h"
#include "gtest/gtest.h"

TEST(TestRoomObject, getStateTest) {
  RoomObject a(2101);
  RoomObject b(2102, true);
  EXPECT_EQ(false, a.getState());
  EXPECT_EQ(true, b.getState());
}

TEST(TestRoomObject, setStateTest) {
  RoomObject a(2101);
  a.setState(true);
  EXPECT_EQ(true, a.getState());
}

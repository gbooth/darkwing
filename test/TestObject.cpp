/**
* @author Ben Hunt
* @date 30 Oct. 2010
*/
#include "Object.h"
#include "Exceptions.h"
#include <string>
#include "gtest/gtest.h"

TEST(TestObject, ctorTest) {
  EXPECT_THROW(Object a(1000), invalid_id);
  EXPECT_NO_THROW(Object a(1018));
}

TEST(TestObject, getIDTest) {
  Object a(4301);
  EXPECT_EQ(4301, a.getID());
}

TEST(TestObject, getNameTest) {
  Object a(1001);
  EXPECT_EQ("wizard room", a.getName());
}

TEST(TestObject, getDescTest) {
  Object a(1001);
  std::string s = "The home of the renowned wizard whom you serve loyally.";
  std::string r = " A spikey chest lies in the corner.";
  std::string x = " You can go north, east or south.";
  std::string p = s + r + x;
  EXPECT_EQ(p, a.getDesc());
}




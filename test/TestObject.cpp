/**
* @author Ben Hunt
* @date 30 Oct. 2010
*/
#include "Object.h"
#include "gtest/gtest.h"

TEST(TestObject, getIDTest) {
  Object a(1001);
  EXPECT_EQ(1001, a.getID());

}

TEST(TestObject, getNameTest) {
  Object a(1001);
  EXPECT_EQ("wizard room", a.getName());
}

TEST(TestObject, getDescTest) {
  Object a(1001);
  EXPECT_EQ("the home of the renowned wizard whom you serve loyally",
            a.getDesc());
}




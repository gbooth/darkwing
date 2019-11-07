/**
* @author Ben Hunt
* @date 30 Oct. 2010
*/
#include "Object.h"
#include "gtest/gtest.h"
#include "Exceptions.h"
TEST(TestObject, ctorTest){
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
  EXPECT_EQ("the home of the renowned wizard whom you serve loyally",
            a.getDesc());
}




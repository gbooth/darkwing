/**
* @author Ben Hunt
* @date 30 Oct. 2010
*/
#include "Object.h"
#include "gtest/gtest.h"

TEST(TestObject, ctorTest) {
  Object a(Object::jzargo);
  EXPECT_EQ(Object::jzargo, a.id);
}



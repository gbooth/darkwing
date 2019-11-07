#include "gtest/gtest.h"
#include "Lever.h"
#include "Exceptions.h"

TEST(TestLever, ctorTest) {
  Lever l(2303);
  EXPECT_EQ(false, l.getState());
  EXPECT_THROW(Lever(1000), invalid_id);
  EXPECT_NO_THROW(Lever a(2301));
}

TEST(TestLever, setLeverTest) {
  Lever l(2303);
  l.setLever(true);
  EXPECT_EQ(true, l.getState());
}

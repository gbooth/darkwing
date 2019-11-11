#include <Chest.h>
#include <gtest/gtest.h>
#include <Exceptions.h>

TEST(TestChest, constructorTest){
  EXPECT_NO_THROW(Chest a(2101));
  EXPECT_THROW(Chest b(3301), invalid_id);
}

TEST(TestChest, getContentsTest){
Chest a(2101);
Chest b(2102);
EXPECT_EQ(4204, a.getContents().getID());
EXPECT_NE(4201, b.getContents().getID());
}

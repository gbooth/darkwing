#include <Item.h>
#include <gtest/gtest.h>
#include <Exceptions.h>

TEST(TestItem, ConstructorTest) {
  EXPECT_NO_THROW(Item sword(4201));
  EXPECT_THROW(Item goblin1(3301), invalid_id);
}

TEST(TestItem, getItemValueTest) {
  Item k(4303);
  Item w(4202);
  Item p(4101);

  EXPECT_EQ(-3, k.getItemValue());
  EXPECT_EQ(8, w.getItemValue());
  EXPECT_EQ(20, p.getItemValue());
  EXPECT_NE(0, p.getItemValue());
}

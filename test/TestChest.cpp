#include <Chest.h>
#include <gtest/gtest.h>
#include <Exceptions.h>

TEST(TestChest, constructorTest) {
  EXPECT_NO_THROW(Chest a(2101));
  EXPECT_THROW(Chest b(3301), invalid_id);
}

TEST(TestChest, getContentsTest) {
  Chest a(2101);
  Chest b(2102);
  Item* c = a.getContents();
  Item* d = b.getContents();
  EXPECT_EQ(4204, c->getID());
  EXPECT_NE(4204, d->getID());
  delete c;
  delete d;
}

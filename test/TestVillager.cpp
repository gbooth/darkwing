#include "Villager.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestVillager, ctorTest){
  EXPECT_THROW(Villager v(3306), invalid_id);
  EXPECT_NO_THROW(Villager a(3201));
}

TEST(TestVillager, responseTest){
  Villager v(3201);
  v.response();
}

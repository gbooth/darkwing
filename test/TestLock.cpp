/** @author Jorge Aceytuno id:001003732
*@date 2019-11-8
*/

#include "Lock.h"
#include "gtest/gtest.h"
#include "Exceptions.h"
#include"Item.h"

TEST(TestLock, TestConstructor) {

  EXPECT_THROW(Lock a (3001), invalid_id);
}

TEST(TestLock, TestCheckkey) {
  Lock a(2202);
  a.checkKey(4301);
  EXPECT_EQ(a.checkKey(4301), false);
}

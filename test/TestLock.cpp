/** @author Jorge Aceytuno id:001003732
*@date 2019-11-8
*/

#include "Lock.h"
#include "gtest/gtest.h"
#include "Exceptions.h"
#include"Item.h"

TEST(TestLock, TestConstructor) {
  EXPECT_THROW(Lock a(3001), invalid_id);
}

TEST(TestLock, TestUnlock) {
  Lock a(2202);
  Lock b(2203);
  b.unlock(4303);
  a.unlock(4301);
}

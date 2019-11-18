#include "Lever.h"
#include "Exceptions.h"
#include <utility>
#include <vector>
#include "gtest/gtest.h"

TEST(TestLever, ctorTest) {
  Lever l(2303);
  EXPECT_EQ(false, l.getState());
  EXPECT_THROW(Lever(1000), invalid_id);
  EXPECT_NO_THROW(Lever a(2301));
}

TEST(TestLever, setGetTest) {
  Lever a(2303);
  Lever* aptr = &a;
  bool b = true;
  std::pair<Lever*, bool> l;
  l = std::make_pair(aptr, b);
  a.setDepLever(l);
  std::vector<std::pair<Lever*, bool>> vec;
  vec.push_back(l);
  EXPECT_TRUE(a.getDepLever() == vec);
  aptr = nullptr;
}

#include "Load.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestLoad, loadGameTest) {
  Load l;
  Hero a;
  Room** world;
  for (int i = 0; i<5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  l.loadGame(a, world);
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
}

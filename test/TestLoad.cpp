#include "Load.h"
#include "Exceptions.h"
#include "gtest/gtest.h"
#include <sstream>

TEST(TestLoad, loadGameTest) {
  Hero a;
  Room** world;
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
    std::streambuf *backup;
  std::istringstream oss("\nsampleLoad");
  backup = std::cin.rdbuf();
  std::cin.rdbuf(oss.rdbuf());
  Load l;
  l.loadGame(a, world);
  for (int i = 0; i < 5; i++) {
    delete [] world[i];
  }
  delete [] world;
}

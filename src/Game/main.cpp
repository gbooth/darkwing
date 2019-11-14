#include "Room.h"
#include "Hero.h"
#include "Load.h"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

int titleScreen();
void clearScreen();
void newGame(Hero*, Room**);
void loadGame(Hero* const, Room** const);
void exitGame();

int main() {
  std::string inStr = "";
  Hero* h = nullptr;
  Room** world = nullptr;
  while (true) {
    if (titleScreen() == 1) {
      newGame(h, world);
      std::cout << "It is a pleasant spring day in Anates Terra, a province in"
                << " Avemland.\nEach province in Avemland is ruled over by a k"
                << "ing, and Anates Terra \nis no different. Our story begins "
                << "in Castle Anates, in the resident\nwizard tower, where an "
                << "eager young apprentice named Duck Norris is\nassisting wit"
                << "h the concoction of a new potion. The wizard, brilliant\na"
                << "s he is eccentric, still cannot determine why this potion "
                << "does not\nmake pigs fly.\n\"Norris, bring me the wooden du"
                << "ck we must do some debugging.\"\ncried the wizard.  Duck N"
                << "orris rushed to fetch the wooden duck and\nplaced it in fr"
                << "ont of the wizard.\"Your duck, master,\" murmured Norris."
                << "\nThe wizard took the duck without a second glance and pro"
                << "ceeded to\nexplain the potion properties. Minutes go by an"
                << "d the Wizard grows\nincreasingly frustrated to the point o"
                << "f him throwing the duck into\nthe bubbling cauldron. Upon "
                << "the duck touching the surface of the\npotion it comes aliv"
                << "e and grows to the size of a dragon. \"You have\nused me f"
                << "or debugging for the last time wizard!\" thundered the gia"
                << "nt\nduck. The duck swoops a wooden wing down and picks up "
                << "the wizard\nand storms out of the castle leaving a giant d"
                << "uck-sized hole in the\nwall. As Duck Norris, you must save"
                << " your master.\n";
    } else {
      newGame(h, world);
      loadGame(h, world);
    }
    std::cout <<"hello " << world[0][0].getName();

    std::getline(std::cin, inStr);
    while (true) {
      if (inStr == "exit") {
        delete h;
        for (int i = 0; i < 5; i++)
          delete [] world[i];
        delete world;
        break;
      }
      h->command(inStr, world);
      getline(std::cin, inStr);
    }
  }
}

int titleScreen() {
  int in;
  while (true) {
    std::cout << "  _____          _   _       _____                       " <<
              std::endl
              << " / ____|        | | | |     / ____|                      " << std::endl
              << "| |     __ _ ___| |_| | ___| (___   ___ __ _ _ __   ___  " << std::endl
              << "| |    / _` / __| __| |/ _ \\___ \ / __/ _` | ' _\ / _ \ " << std::endl
              << "| |___| (_| \__ \ |_| |  __/____) | (_| (_| | |_) |  __/ " << std::endl
              << " \_____\__,_|___/\__|_|\___|_____/ \___\__,_| .__/ \___| " << std::endl
              << "                                            | |          " << std::endl
              << "                                            |_|          " << std::endl;
    std::cout << std::setw(22) << "1 - New Game" << std::endl
              << std::setw(22) << "2 - Load Game" << std::endl
              << std::setw(22) << "3 - Exit Game" << std:: endl;
    std::cout << "Selection -- ";
    std::cin >> in;
    switch (in) {
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      exitGame();
    default:
      std::cout << "invalid selection";
      system("PAUSE");
      break;
    }
    clearScreen();
  }
}

void clearScreen() {
  std::cout << std::flush;
  system("CLS");
}

void newGame(Hero* h, Room** world) {
  h = new Hero;
  world = new Room*[5];
  for (int i = 0; i < 5; i++)
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      world[i][j].setDoor(world);
}

void loadGame(Hero* const h, Room** const world) {
//    Load l;
//    l.loadGame(h, world);
}

void exitGame() {
  exit(0);
}

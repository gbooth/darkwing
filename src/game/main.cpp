#include "Room.h"
#include "Hero.h"
#include "Load.h"
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

int titleScreen();
void clearScreen();
Room** newGame(Room**);
void loadGame(Hero* const, Room** const);
void exitGame();

int main() {
  std::string inStr;
  Hero h;
  Room** world = nullptr;
  while (true) {
    if (titleScreen() == 1) {
      world = newGame(world);
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
                << "uck-sized hole in the\nwall. As Duck Norris, you stand awes"
                << "truck in the wizard room you must\nsave your master.\n\n";
    }
//    else {
//      newGame(h, world);
//      loadGame(h, world);
//    }
    std::cout << "what will you do now?(type for help for commands)\n";
    std::cin.ignore(1000,'\n');
    while (true) {
      std::cout << "   _  " << std::endl << "__(0)>";
      std::getline(std::cin, inStr);
      std::cout << R"(\___))" << std::endl;
      if (inStr == "exit") {
        for (int i = 0; i < 5; i++){
          delete [] world[i];
        }
        delete world;
        world = nullptr;
        break;
      }
      h.command(inStr, world);
    }
  }
  return 0;
}

int titleScreen() {
  std::string in;
  while (true) {
    std::cout << R"(    ____             __            _            )" << std::endl
              << R"(   / __ \____ ______/ /___      __(_)___  ______)" << std::endl
              << R"(  / / / / __ `/ ___/ //_/ | /| / / / __ \/ __ `/)" << std::endl
              << R"( / /_/ / /_/ / /  / ,<  | |/ |/ / / / / / /_/ / )" << std::endl
              << R"(/_____/\__,_/_/  /_/|_| |__/|__/_/_/ /_/\__, /  )" << std::endl
              << R"(                                       /____/   )" << std::endl;
    std::cout << std::setw(21) << "1 - New Game" << std::endl
              << std::setw(22) << "2 - Load Game" << std::endl
              << std::setw(22) << "3 - Exit Game" << std:: endl;
    std::cout << "Selection -- ";
    std::cin >> in;
    if(in == "1"){
      return 1;
    } else if(in == "2"){
      return 2;
    } else if (in == "3"){
      exitGame();
    }
    clearScreen();
  }
}

void clearScreen() {
 std::cout << std::string( 100, '\n' );
}

Room** newGame(Room** world) {
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      world[i][j].setDoor(world);
  return world;
}

void loadGame(Hero* const h, Room** const world) {
//    Load l;
//    l.loadGame(h, world);
}

void exitGame() {
  exit(0);
}
